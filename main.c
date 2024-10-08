#include"prof.h"
int main(){
FILE *fp = fopen("test.c","r");
  //Token *tokens = lexer(fp);
 //   printf("tokens = %p\n", tokens);
 //   TokenType temp;
  //  printf("%s\n",tokens[0].value);
//    printf("done\n");
    //printf("%p\n",tokens);
parser(lexer(fp));
    return 0;
}
