all: compile run_program

compile:
	gcc -Wall -Wextra main.c -o main -lncurses

run_program:
	./main