
all: apecc

clean:
	rm -f apecc
	rm -f *.class *.hi *.o *.exe

apecc: apecc.hs apecode.h
	ghc --make -O2 apecc.hs -fforce-recomp
