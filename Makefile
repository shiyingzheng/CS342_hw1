all: hw1

hw1: hw1.c hw1.h parse.o
    clang -o hw1 hw1.c parse.o

parse: parse.c parse.h
    clang -c parse 

clean: hw1
    rm -f hw1
