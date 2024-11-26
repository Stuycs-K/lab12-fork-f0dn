.PHONY: compile run clean
fork.out compile: main.o
	@gcc -o fork.out main.o -Wall
main.o: main.c
	@gcc -c main.c -Wall
clean:
	@rm -f fork.out *.o
run: fork.out
	@./fork.out
