import java.awt.*;
import java.awt.geom.*;
import java.awt.event.*;
import java.awt.image.*;
import java.io.*;
import java.security.*;
import javax.swing.*;
 
public class WordSnakeGenerator {
    static Process proc;
    JFrame jf;
    InputStream is;
    OutputStream os;
    BufferedReader br;
    static int dump;
 
    int n, m;
    char [][] table;
    int w;
    String [] word;
 
    int c;
    String [] return_word;
    int [][] return_x;
    int [][] return_y;
    int valid;
     
    // ---------------------------------------------------
 
    void generate(String seed) {
      try {
        SecureRandom r = SecureRandom.getInstance("SHA1PRNG");
        r.setSeed(Long.parseLong(seed));
 
        n = r.nextInt(46) + 5;
        m = r.nextInt(46) + 5;
        table = new char[n][m];
 
        BufferedReader in = new BufferedReader(new FileReader("words"));
        String s;
        s = in.readLine();
        w = Integer.parseInt(s);
        word = new String[w];
        for (int i=0; i<w; i++) {
          word[i] = in.readLine();
        }
        in.close();
 
        int [] ratio = new int[26];
        for (int i=0; i<w; i++) {
          for (int j=0; j<word[i].length(); j++)
            ratio[word[i].charAt(j)-'a'] ++;
        }
        int ratio_sum = 0;
        for (int i=0; i<26; i++) {
          int mult = r.nextInt(21) + 10;
          ratio[i] *= mult;
          ratio_sum += ratio[i];
        }
        for (int i=0; i<n; i++)
          for (int j=0; j<m; j++) {
            int next = r.nextInt(ratio_sum);
            for (int k=0; k<26; k++) {
              if (ratio[k] > next) {
                table[i][j] = (char)('a' + k);
                break;
              }
              next -= ratio[k];
            }
          }
      }
      catch (Exception e) {
        addFatalError("An exception occurred while generating test case.");
        e.printStackTrace();
      }
    }
    // ---------------------------------------------------
 
    int calcScore() {
      if (valid == 0) {
        addFatalError("Your return syntax is not valid.");
        return 0;
      }
      return 0;
    }
 
    public int runTest(String seed) { // double in latter cases
      try {
        generate(seed);
 
        System.out.println(n + " " + m);
        for (int i=0; i<n; i++) {
          for (int j=0; j<m; j++)
            System.out.print(table[i][j]);
          System.out.println("");
        }
        System.out.println(w);
        for (int i=0; i<w; i++)
          System.out.println(word[i]);
 
        return 0;
      }
      catch (Exception e) {
        addFatalError("An exception occurred while trying to get your program's results.");
        e.printStackTrace();
        return 0;
      }
    }
 
    public WordSnakeGenerator(String seed) {
        //interface for runTest
        runTest(seed);
 
        if (proc != null)
            try { proc.destroy(); }
            catch (Exception e) { e.printStackTrace(); }
    }
    // ---------------------------------------------------
    public static void main(String[] args) {
        String seed = "1";
        dump = 1;
        for (int i = 0; i<args.length; i++)
        {   if (args[i].equals("-seed"))
                seed = args[++i];
        }
        WordSnakeGenerator f = new WordSnakeGenerator(seed);
    }
    // ---------------------------------------------------
    void addFatalError(String message) {
        System.out.println(message);
    }
}
 
class ErrorReader extends Thread{
    InputStream error;
    public ErrorReader(InputStream is) {
        error = is;
    }
    public void run() {
        try {
            byte[] ch = new byte[50000];
            int read;
            while ((read = error.read(ch)) > 0)
            {   String s = new String(ch,0,read);
                System.out.print(s);
                System.out.flush();
            }
        } catch(Exception e) { }
    }
}
