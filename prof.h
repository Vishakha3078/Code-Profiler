#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"ctype.h"
#include<stdbool.h>

typedef enum{
    START,
    STATEMENT,
    LOOP,
    CONDITIONAL_STATEMENT,
    FUNCTION,
    HEADER,
    FUNC_CALL,
    CURLY,
    COUNT,
    END,
}TokenType;

typedef struct{
    TokenType type;
    char *value;
}Token;

typedef struct Node{
    TokenType type;
    char *value;
    struct Node **ptr;
    int ptrsize;
}Node; 

typedef struct parseoutput{
    Token *extras;
    int extra_size;
    Node **array_func;
    int func_index;
    Node *root;
}parseroutput;

Token **lexer(FILE *fp);
parseroutput *parser(Token **tokens);
