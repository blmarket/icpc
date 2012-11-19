all: a.exe judge

clean:
	rm a.exe judge

a.exe: main.cpp
	g++ -O2 $< -o $@

test: a.exe judge
	@./a.exe < 1.in 2>/dev/null | ./judge
	@./a.exe < 2.in 2>/dev/null | ./judge
	@./a.exe < 3.in 2>/dev/null | ./judge
	@./a.exe < 4.in 2>/dev/null | ./judge
	@./a.exe < 5.in 2>/dev/null | ./judge
	@./a.exe < 6.in 2>/dev/null | ./judge
	@./a.exe < 7.in 2>/dev/null | ./judge
	@./a.exe < 8.in 2>/dev/null | ./judge
	@./a.exe < 9.in 2>/dev/null | ./judge
	@./a.exe < 10.in 2>/dev/null | ./judge

.PHONY: all clean test
