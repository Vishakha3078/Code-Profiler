all:run
final: main.o lexer.o parser.o code_generator.o my_code.o
	gcc main.o lexer.o parser.o code_generator.o my_code.o -o final

main.o: main.c
	gcc -c main.c -o main.o

lexer.o: lexer.c
	gcc -c lexer.c -o lexer.o

parser.o: parser.c
	gcc -c parser.c -o parser.o

code_generator.o: code_generator.c
	gcc -c code_generator.c -o code_generator.o

my_code.o: my_code.c
	gcc -c my_code.c -o my_code.o

header: prof.h
	gcc prof.h

clear:
	rm *.o final

run: final
	./final
