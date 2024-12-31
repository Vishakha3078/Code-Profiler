#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"ctype.h"
#include"stdbool.h"
#include"unistd.h"

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

typedef struct lexeroutput{
    Token **token;
    int token_size;
}lexeroutput;

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

typedef struct liststack{
    int size;
    int top;
    ListNode **arr;
}liststk;

typedef struct trie_node{
    struct trie_node** list;
    bool is_end;
}trie_node;


lexeroutput *lexer(FILE *fp);
parseroutput *parser(lexeroutput *tokens);
void printtree(Node *root);
void code_generator(parseroutput* output);
int givecount(Node *root);
ListNode *makeNode();
ListNode *makelist(int n);
int pop(stk *s);
void push(stk *s,int val);
ListNode* listpop(liststk *s);
void listpush(liststk *s,ListNode *nd);
ListNode* traversenext(int n,ListNode* nd);
void give_colour_box(int w,int h);
trie_node* create_trie_node();  
void insert_in_trie(trie_node* root,char* string);
bool is_in_trie(trie_node* root,char* string);
