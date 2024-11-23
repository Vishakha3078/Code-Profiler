#include"prof.h"
int main(){
FILE *f = fopen("test.c","r");
  //Token *tokens = lexer(fp);
 //   printf("tokens = %p\n", tokens);
 //   TokenType temp;
  //  printf("%s\n",tokens[0].value);
//    printf("done\n");
    //printf("%p\n",tokens);
    code_generator(parser(lexer(f)));
    return 0;
}
