all:run
final: main.o lexer.o parser.o code_generator.o stacklist.o
	gcc main.o lexer.o parser.o code_generator.o stacklist.o -o final

main.o: main.c
	gcc -c main.c -o main.o

lexer.o: lexer.c
	gcc -c lexer.c -o lexer.o

parser.o: parser.c
	gcc -c parser.c -o parser.o

code_generator.o: code_generator.c
	gcc -c code_generator.c -o code_generator.o

stacklist.o: stacklist.c
	gcc -c stacklist.c -o stacklist.o

header: prof.h
	gcc prof.h

clear:
	rm *.o final

run: final
	./final
