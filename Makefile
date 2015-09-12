all: hw1

hw1: hw1.c hw1.h parse.o
	clang -o hw1 hw1.c parse.o

parse: parse.c parse.h
	clang -c parse 

parsetest: parse.o parsetest.c
	clang -o parsetest parsetest.c parse.o

clean: hw1
	rm -f hw1
