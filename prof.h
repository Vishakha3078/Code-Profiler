#include"new_code.h"

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
    char **my_variable;
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
    int func_size;
    char **my_variable;
}parseroutput;
    
typedef struct trie_node{
    struct trie_node** list;
    bool is_end;
}trie_node;


lexeroutput *lexer(FILE *fp);
parseroutput *parser(lexeroutput *tokens);
void printtree(Node *root);
void code_generator(parseroutput* output);
int givecount(Node *root);
trie_node* create_trie_node();  
void insert_in_trie(trie_node* root,char* string);
bool is_in_trie(trie_node* root,char* string);
