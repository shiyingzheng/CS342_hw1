all: hw1

hw1: hw1.c hw1.h
    clang -o hw1 hw1.c

clean: hw1
    rm -f hw1
