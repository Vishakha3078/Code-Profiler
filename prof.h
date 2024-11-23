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

int pop(stk *st){
    st -> top = (st -> top) - 1;
    return st -> arr[(st -> top) + 1];
}

void push(stk *st,int val){
    if((st -> top)+1 == st -> size){
        st -> size = (st -> size) + 10;
        st = realloc(st, sizeof(int)*st ->size);
    }
    st -> top = st -> top + 1;
    st -> arr[st -> top] = val;
    return;
}

FILE *fp;
Token **lexer(FILE *fp);
parseroutput *parser(Token **tokens);
void printtree(Node *root);
void code_generator(parseroutput* output);
int givecount(Node *root);
ListNode *makeNode();
ListNode *makeNext(ListNode *nd);
ListNode *makelist(int n);
char* my_strcat(char *s1,char *s2);
char *remove_return_type(char *s);
void printcounts(parseroutput* output);
