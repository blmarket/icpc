RESULT = 1.out 2.out 3.out 4.out 5.out 6.out 7.out 8.out 9.out 10.out

all: a.exe judge

clean:
	rm a.exe judge $(RESULT)

a.exe: main.cpp
	g++ -O2 $< -o $@

.in.out: a.exe judge
	./a.exe < $< | ./judge $< > $@

test: a.exe judge $(RESULT)
	@cat $(RESULT)

.PHONY: all clean test

.SUFFIXES: .c .o .in .out
