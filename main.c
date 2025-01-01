#include"prof.h"
int main(){
    char* name = malloc(50);
    printf("Enter file Name:");
    scanf("%s",name);
    FILE *f = fopen(name,"r");
    code_generator(parser(lexer(f)));
    system("gcc stacklist.c code_generator.c parser.c my_code.c -lm && ./a.out");    
    return 0;
}
