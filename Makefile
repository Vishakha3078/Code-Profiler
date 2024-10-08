all:run
final: main.o lexer.o parser.o 
	gcc main.o lexer.o parser.o -o final

main.o: main.c
	gcc -c main.c -o main.o

lexer.o: lexer.c
	gcc -c lexer.c -o lexer.o

parser.o: parser.c
	gcc -c parser.c -o parser.o

header: prof.h
	gcc prof.h

clear:
	rm *.o final

run: final
	./final
