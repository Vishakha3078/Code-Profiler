all:run
final: main.o lexer.o parser.o code_generator.o printcounts.o 
	gcc main.o lexer.o parser.o code_generator.o printcounts.o -o final

main.o: main.c
	gcc -c main.c -o main.o

lexer.o: lexer.c
	gcc -c lexer.c -o lexer.o

parser.o: parser.c
	gcc -c parser.c -o parser.o

code_generator.o: code_generator.c
	gcc -c code_generator.c -o code_generator.o

printcounts.o: printcounts.c
	gcc -c printcounts.c -o printcounts.o

header: prof.h
	gcc prof.h

clear:
	rm *.o final

run: final
	./final
