all: compile run_program

compile:
	gcc main.c -o main

run_program:
	./main