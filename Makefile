all: hw1 parse parsetest

hw1: hw1.c hw1.h parse.o
	clang -o hw1 hw1.c parse.o

parse: parse.c parse.h
	clang -c parse.c 

parsetest: parse.o parsetest.c
	clang -o parsetest parsetest.c parse.o

clean: hw1 parse parsetest
	rm -f hw1 parse parsetest
