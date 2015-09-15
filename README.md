# CS342_hw1
## Authors: Benjamin Stern, Cole Peppis, Ben Izmirli, Shiying Zheng
The hw1 program, similar to wget, retrieves the file from a valid URL, as long
as the file size is less than 1MB.

## To use:
The makefile compiles two executables, hw1 and parsetest. The hw1 executable
makes an http 1.0 get request for a file specified in the command line
arguements. The parsetest executable is a simple program that we used to test
our string parsing.

## Contents:
* hw1.c - Contains the main bulk of the hw1 program
* hw1.h - Header file for hw1.c
* parse.c - Contains the parse() method which parses a URL into a host, path, and file
* parse.h - Header file for parse.c
* parsetest.c - Program for testing parse.c

## Honor Code
We have adhered to the Honor Code in this assignment.
