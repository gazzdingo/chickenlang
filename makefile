LFLAGS = `sdl-config --libs` -lSDL
CC=gcc


test : test.o lexer.o parser.tab.o cw1.o chicken.o syntax.o
	$(CC) -o test test.o cw1.o lexer.o parser.tab.o chicken.o syntax.o -L/usr/lib/x86_64-linux-gnu -lSDL


parser.tab.c : parser.y
	bison parser.y

parser.tab.h : parser.y
	bison parser.y

lexer.c : lexer.l
	flex lexer.l

lexer.h : lexer.l
	flex lexer.l

lexer.o : lexer.c
	$(CC) -c -o lexer.o lexer.c

parser.tab.o : parser.tab.c
	$(CC) -c -o parser.tab.o parser.tab.c

test.o : test.c parser.tab.h lexer.h
	$(CC) -c -o test.o test.c

chicken.o: chicken.c
	$(CC) -c chicken.c

syntax.o : syntax.c
	$(cc) -c syntax.c
