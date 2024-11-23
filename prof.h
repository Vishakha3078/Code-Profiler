#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"ctype.h"
#include"stdbool.h"

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
}parseroutput;

typedef struct ListNode{
    struct ListNode *next;
    unsigned int val;
}ListNode;

typedef struct stack{
    int size;
    int top;
    int *arr;
}stk;

Token **lexer(FILE *fp);
parseroutput *parser(Token **tokens);
void printtree(Node *root);
void code_generator(parseroutput* output);
int givecount(Node *root);
