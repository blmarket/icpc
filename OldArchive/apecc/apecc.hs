{-# LANGUAGE FlexibleInstances, TypeSynonymInstances, TemplateHaskell,CPP #-}
{-# OPTIONS_GHC -Wall -fno-warn-orphans #-}

import Text.ParserCombinators.Parsec hiding (State)
import Text.ParserCombinators.Parsec.Pos
import Text.ParserCombinators.Parsec.Error
import Text.PrettyPrint.HughesPJ hiding (space,char,Style)
import Control.Applicative hiding ((<|>),many,Const)
import Control.Monad
import Data.Char
import Data.Maybe
import qualified Data.Map as Map
import System.Environment
import System.Process (runProcess,waitForProcess)
import System.Exit
import System.FilePath
import System.IO
import System.Console.GetOpt

#define USE_HARDCODED_HEADER   1
#define KEEP_INTERMEDIATE_FILE 0

#if USE_HARDCODED_HEADER
import Language.Haskell.TH (runIO, stringE)
#endif
#if !KEEP_INTERMEDIATE_FILE
import System.Directory
#endif

-------------------------------------------------------------------------------------
-- Utility
-------------------------------------------------------------------------------------

instance Applicative (GenParser t s) where
    pure  = return
    (<*>) = ap

-------------------------------------------------------------------------------------
-- Syntax
-------------------------------------------------------------------------------------

newtype FunName = FunName String
  deriving (Eq,Ord)

data Stmt
    = SCall    FunName
    | SIf      [LStmt] [LStmt]
    | SReturn  Bool

data Decl
    = StateDecl FunName [LStmt]

-- with line numbers
data L a = L { pos :: SourcePos, unL :: a }
  deriving (Eq,Ord)

type LStmt = L Stmt
type LDecl = L Decl
type Program = [LDecl]

-------------------------------------------------------------------------------------
-- Built in names
-------------------------------------------------------------------------------------

builtinNames :: [String]
builtinNames
    = ["move_left","move_right"
      ,"pick_up_left","pick_up_right"
      ,"put_down_left","put_down_right"
      ,"if_empty_left","if_empty_right"
      ,"if_tilt_left","if_tilt_right"
      ,"remember","recall"
      ,"trace"]

-------------------------------------------------------------------------------------
-- Pretty printing
-------------------------------------------------------------------------------------

data Style = Short | Compiled

class Pretty a where
    pretty :: Style -> a -> Doc

instance Pretty String where
    pretty _ = text

instance Pretty FunName where
    pretty Short    (FunName x) = text x
    pretty Compiled (FunName x)
       | x `elem` builtinNames  = text ("APECODE_BUILTIN_" ++ x)
       | otherwise              = text ("APECODE_STATE_" ++ x)

instance Pretty Bool where
    pretty Short    False = text "false";
    pretty Short    True  = text "true";
    pretty Compiled False = text "0 /*false*/";
    pretty Compiled True  = text "1 /*true*/";

instance Pretty Stmt where
    pretty s@Short (SCall a)
        = pretty s a
    pretty s@Short (SIf t e)
        = text "then"
      $+$ nest 4 (pretty s t)
      $+$ text "else"
      $+$ nest 4 (pretty s e)
    pretty s@Short (SReturn b)
        = text "return" <+> pretty s b <> text ";"
    pretty s@Compiled (SCall a)
        = text "APECODE_CALL(" <> pretty s a <> text ");"
    pretty s@Compiled (SIf t e)
        = text "APECODE_IF {"
      $+$ nest 4 (pretty s t)
      $+$ text "} else {"
      $+$ nest 4 (pretty s e)
      $+$ text "}"
    pretty s@Compiled (SReturn b)
        = text "APECODE_RETURN(" <> pretty s b <> text ");"

instance Pretty [LStmt] where
    pretty s stmts = vcat $ map (pretty s) stmts


instance Pretty Decl where
    pretty s@Short    (StateDecl f body)
        = text "state" <+> pretty s f <+> text "{"
       $$ nest 4 (pretty Short body)
       $$ text "}"
    pretty s@Compiled (StateDecl f body)
        = text "APECODE_STATE_BEGIN(" <> pretty s f <> text ")"
       $$ nest 4 (pretty s body)
       $$ text "APECODE_STATE_END()\n"

forwardDeclaration :: LDecl -> Doc
forwardDeclaration = prettyWithL fwdDecl
  where fwdDecl (StateDecl f _) = text "APECODE_STATE_FORWARD(" <> pretty Compiled f <> text ");"

instance Pretty [LDecl] where
    pretty Short    decls = vcat ( map (pretty Short)    decls )
    pretty Compiled decls = text "/* declarations */\n"
                         $$ vcat ( map forwardDeclaration decls )
                         $$ text "\n/* implementation */\n"
                         $$ vcat ( map (pretty Compiled) decls )


prettyNoL :: (a -> Doc) -> (L a -> Doc)
prettyNoL f (L _ a) = f a

prettyWithL :: (a -> Doc) -> (L a -> Doc)
prettyWithL f (L l a) = text "#line" <+> int (sourceLine l) $$ f a

prettyL :: Pretty a => (Style -> L a -> Doc)
prettyL Short    = prettyNoL   (pretty Short)
prettyL Compiled = prettyWithL (pretty Compiled)

instance Pretty LStmt where
    pretty = prettyL

instance Pretty LDecl where
    pretty = prettyL


instance Show FunName  where show = render . pretty Short
instance Show Stmt     where show = render . pretty Short
instance Show Decl     where show = render . pretty Short
instance Show a => Show (L a) where show = show . unL
                                    showList = showList . map unL

-------------------------------------------------------------------------------------
-- Parsing
-------------------------------------------------------------------------------------

isAlpha_, isAlphaNum_ :: Char -> Bool
isAlpha_    c = isAlpha    c || c == '_'
isAlphaNum_ c = isAlphaNum c || c == '_'

whitespace :: Parser ()
whitespace = skipMany single
   where single  = const () <$> space <|> comment <|> multiComment <?> ""
         comment = try (string "//") >> skipMany (satisfy (/='\n'))
         multiComment = try (string "/*") >> continueComment
         continueComment = try (string "*/" *> return ())
                       <|> anyChar *> continueComment

-- for error messages
anyWord :: Parser String
anyWord = show <$> try (many1 $ satisfy isAlphaNum_) <?> ""

keyword :: String -> Parser String
keyword match = try (do string match <?> match
                        notFollowedBy sameCat <?> ""
                        return match
                    ) <* whitespace
            <|> try (anyWord >>= unexpected)
  where
    sameCat | isAlpha_ (head match) = satisfy isAlphaNum_
            | otherwise = mzero

keywordMsg :: String -> String -> Parser String
keywordMsg match msg = keyword match <|> fail msg

parseFunName :: Parser FunName
parseFunName = FunName <$> try match <* whitespace
            <?> "name"
    where match = (:) <$> firstChar <*> many nextChar
          firstChar = satisfy isAlpha_
          nextChar  = satisfy isAlphaNum_

parseBool :: Parser Bool
parseBool = False <$ keyword "false"
        <|> True  <$ keyword "true"
    <?> "boolean (true or false)"

parseStmt :: Parser Stmt
parseStmt = fail ""
        <|> SIf       <$ keyword "then"     <*> parseBlock
                                            <*> (keywordMsg "else" "in then/else statement" *> parseBlock <|> pure [])
        <|> SReturn   <$ keyword "return"   <*> parseBool    <* keywordMsg ";" "in return statement"
        <|> SCall     <$ keyword "call"     <*> (parseFunName <|> fail "in call statement") <* keywordMsg ";" "in call statement"
    <?> "statement"

parseDecl :: Parser Decl
parseDecl = StateDecl <$ keyword "state" <*> (parseFunName <|> fail "in declaration") <*> parseBlock
    <?> "declaration"

parseWithL :: Parser a -> Parser (L a)
parseWithL parseA = L <$> getPosition <*> parseA

parseBlock :: Parser [LStmt]
parseBlock = keyword "{" *> many parseLStmt <* keyword "}"

parseLStmt :: Parser LStmt
parseLStmt = parseWithL parseStmt

parseLDecl :: Parser LDecl
parseLDecl = parseWithL parseDecl

parseProgram :: Parser [LDecl]
parseProgram = whitespace *> many parseLDecl <* eof

-------------------------------------------------------------------------------------
-- Checker
-------------------------------------------------------------------------------------

mkError :: SourcePos -> String -> ParseError
mkError l s = newErrorMessage (Message s) l

-- | Environment for error checking
data Env = Env { envFunctions :: Map.Map FunName SourcePos }

-- | All sub statements
subStatements :: LStmt -> [LStmt]
subStatements s@(L _ (SIf x y)) = s : concatMap subStatements (x++y)
subStatements s                 = [s]

-- | Is something a return statement?
isReturn :: LStmt -> Bool
isReturn (L _ (SReturn _)) = True
isReturn _                 = False


-- Simple control flow checker
data ControlFlow = ControlFlow { alwaysCall, alwaysReturn :: Bool }

-- join of control flow (phi node)
joinCF :: ControlFlow -> ControlFlow -> ControlFlow
joinCF (ControlFlow c1 r1) (ControlFlow c2 r2) = (ControlFlow (c1||c2) (r1&&r2))

initialCF :: ControlFlow
initialCF = ControlFlow False False

(++>) :: [b] -> (a,[b]) -> (a,[b])
(++>) x (y,z) = (y,x++z)
infix 0 ++>

-- | Check statements for errors
checkStmts :: Env -> ControlFlow -> [LStmt] -> (ControlFlow,[ParseError])
checkStmts _ cf [] = (cf,[])
checkStmts e cf (L l s:xs)
    = [mkError l $ "Unreachable statement" | alwaysReturn cf ]
  ++> case s of
         SCall f -> [ mkError l $ "State '" ++ show f ++ "' not declared."
                    | f `Map.notMember` envFunctions e && f `notElem` map FunName builtinNames]
                ++> checkStmts e cf{alwaysCall = True} xs
         SIf x y -> let (cf1,err1) = checkStmts e cf x
                        (cf2,err2) = checkStmts e cf y
                    in
                    [ mkError l $ "There is no call result for then/else statement."
                    | not (alwaysCall cf) ]
                   ++ err1 ++ err2 ++> checkStmts e (joinCF cf1 cf2) xs
         SReturn _ -> checkStmts e cf{alwaysReturn = True} xs


-- | Check a declaration for errors
checkDecl :: Env -> LDecl -> [ParseError]
checkDecl e (L l (StateDecl f body))
    = [ mkError l $ "State '" ++ show f ++ "' already declared,\nprevious declaration at " ++ show l'
      | let (Just l') = Map.lookup f (envFunctions e)
      , l' /= l
      ]
   ++ [ mkError l $ "State '" ++ show f ++ "' contains no return statement, it is an infinite loop."
      | not (any isReturn stmts)
      ]
   ++ snd (checkStmts e initialCF body)
 where
   stmts = concatMap subStatements body

-- | Check a program for errors
checkProgram :: FilePath -> [LDecl] -> [ParseError]
checkProgram fname decls
    = concatMap (checkDecl env) decls
   ++ [ mkError (initialPos fname) $ "State 'main' not declared."
      | FunName "main" `Map.notMember` envFunctions env]
  where env = Env (Map.fromList declNames)
        declNames = map (\(L l (StateDecl f _)) -> (f,l)) decls


-------------------------------------------------------------------------------------
-- Compiler
-------------------------------------------------------------------------------------

-- The header file
#if USE_HARDCODED_HEADER
$( do txt <- runIO $ readFile "apecode.h"
      [d| the_header_file :: String; the_header_file = $(stringE txt) |]
 )
#else
the_header_file :: String
the_header_file = "#include \"apecode.h\""
#endif

compileProg :: FilePath -> [LDecl] -> Doc
compileProg f decls
    = text the_header_file
   $$ text ("#line 1 " ++ show f)
   $$ pretty Compiled decls
   $$ text "\n"

-------------------------------------------------------------------------------------
-- Main
-------------------------------------------------------------------------------------

printError :: ParseError -> IO ()
printError = hPutStrLn stderr . showError

showError :: ParseError -> String
showError err
   = showPos (errorPos err) ++ ":" ++ " error:" ++
     showMessages (errorMessages err)

showMessages :: [Message] -> String
showMessages
    = unlines . map ("    "++) . lines
    . showErrorMessages "or" "unknown parse error" "expecting" "unexpected" "end of input"

showPos :: SourcePos -> String
showPos p = sourceName p ++ ":" ++ show (sourceLine p) ++ ":" ++ show (sourceColumn p)

parseInput :: String -> IO Program
parseInput input = 
    case parse parseProgram "input" input of
       Left e -> printError e >> exitFailure
       Right prog -> do
          case checkProgram "input" prog of
            [] -> return prog
            es -> mapM_ printError es >> exitFailure

compileFile :: FilePath -> Maybe FilePath -> IO ()
compileFile f outFile = do
    let inFile  = dropExtension f <.> "ape"
    let exeFile = dropExtension $ fromMaybe f outFile
    parsed <- parseFromFile parseProgram inFile
    case parsed of
       Left e -> printError e >> exitFailure
       Right prog -> do
          case checkProgram inFile prog of
            [] -> compileProgram inFile exeFile prog
            es -> mapM_ printError es >> exitFailure

compileProgram :: FilePath -> FilePath -> Program -> IO ()
compileProgram inFile exeFile prog = do
    let cFile = dropExtension exeFile <.> ".apecode.c"
    writeFile cFile (render $ compileProg inFile prog)
    p <- runProcess "gcc" [cFile,"-o",exeFile,"-Wall","-pedantic","-ansi","-O2"] Nothing Nothing Nothing Nothing Nothing
    waitForProcess p
#if !KEEP_INTERMEDIATE_FILE
    removeFile cFile
#endif
    return ()

main :: IO ()
main = do
    args <- getArgs
    case getOpt Permute options args of
       ([], [f],[]) -> compileFile f Nothing  `catch` print
       ([o],[f],[]) -> compileFile f (Just o) `catch` print
       (_,_,_)      -> putStr $ usageInfo header options
     where header = "Usage: apecc FILE.ape [OPTIONS]"
           options = [Option ['o'] ["output"] (ReqArg id "FILE") "Executable file to generate"]
