#include"prof.h"
int main(){
FILE *f = fopen("insertion_sort.c","r");
  //Token *tokens = lexer(fp);
 //   printf("tokens = %p\n", tokens);
 //   TokenType temp;
  //  printf("%s\n",tokens[0].value);
//    printf("done\n");
    //printf("%p\n",tokens);
    code_generator(parser(lexer(f)));
    system("gcc stacklist.c code_generator.c parser.c lexer.c my_code.c && ./a.out");    
    return 0;
}
