#include"prof.h"

//give the total number of count variables required in given function
//input -> pointer of function node
//output -> varibles count of function
int givecount(Node *root){
    int count = 0;
    for(int i = 0; i< root -> ptrsize; i++){
        if(root -> ptr[i] -> type == COUNT){
            count++;
            count += givecount(root -> ptr[i]);
        }
        if(root -> ptr[i] -> type == LOOP || root -> ptr[i] -> type == CONDITIONAL_STATEMENT){
            count++;
            if(!strcmp(root -> ptr[i] -> value,"else"))
                count += givecount(root -> ptr[i] -> ptr[0]);
            else 
                count += givecount(root -> ptr[i] -> ptr[1]);             
        }
    }
    return count;
}

//prints an AST of given function
//input -> takes node pointer of a function
void printtree(Node *root){
    printf("%s\n",root -> value);
    for(int i = 0; i < root -> ptrsize; i++)
        printtree(root -> ptr[i]);
    return;
}

//creates AST node
Node *createnode(Token *token){
    Node *newnode = malloc(sizeof(Node));
    newnode -> type = token->type;
    newnode -> value = token->value;
    newnode -> ptr = malloc(sizeof(Node*));
    newnode -> ptrsize = 0;
    return newnode;
}

//creates count_variable node which tells where to insert count in code
Node *createcountnode(){
    Node *newnode = malloc(sizeof(Node));
    newnode -> type = COUNT;
    newnode -> value ="cnt++";
    newnode -> ptr = malloc(sizeof(Node*));
    newnode -> ptrsize = 0;
    return newnode;
}

//creates node for else condition
Node *createnode_else(Token *token){
    Node *newnode = malloc(sizeof(Node));
    newnode -> type = token -> type;
    newnode -> value = token -> value;
    newnode -> ptr = malloc(sizeof(Node*));
    newnode -> ptrsize = 1;    
    newnode -> ptr[0] = createcountnode();
    return newnode;
}

//creates nodes for loops,conditional_statements,functions except for 'else'  
Node *specialnode(Token **tokens,int *token_num){
    Node *newnode = malloc(sizeof(Node));
    newnode -> type = tokens[*token_num]->type;
    newnode -> value = tokens[*token_num]->value;
    newnode -> ptr = malloc(sizeof(Node*)*2);
    newnode -> ptrsize = 2;
    *token_num = *token_num + 1;
    newnode -> ptr[0] = createnode(tokens[*token_num]);
    *token_num = *token_num + 1;
    newnode -> ptr[1] = createcountnode();
    return newnode;    
}

//create AST tree such that each node contain token-> value,token -> type ,its child array pointer(ptr),child array size(ptrsize)
//input -> takes array of token pointers,its current index,root node,it's children array pointer and child array size
void create_tree(Token **tokens,int *token_num,Node *root,Node **ptr,int *ptrsize){
    int i = 1;
    while(tokens[*token_num]->type != CURLY){
        if(tokens[*token_num]->type == STATEMENT || tokens[*token_num]->type == FUNCTION || tokens[*token_num]->type == FUNC_CALL){
            ptr[*ptrsize] = createnode(tokens[*token_num]);
            *ptrsize = *ptrsize+1;
            *token_num = *token_num + 1;
            ptr = realloc(ptr,sizeof(Node*)*(*ptrsize + 1));
        }   
        else if(tokens[*token_num]->type == LOOP || tokens[*token_num]->type == CONDITIONAL_STATEMENT ){
            if(!strcmp(tokens[*token_num]-> value,"else")){
                ptr[*ptrsize]= createnode_else(tokens[*token_num]);
                *token_num = *token_num + 1;
                i = 0;
            }
            else{
                ptr[*ptrsize] = specialnode(tokens,token_num);
                i = 1;
            } 
            if(tokens[*token_num]->type == CURLY ){
                *token_num = *token_num + 1;
                create_tree(tokens,token_num,ptr[*ptrsize]->ptr[i],ptr[*ptrsize] -> ptr[i] -> ptr,&(ptr[*ptrsize] -> ptr[i] -> ptrsize));
            }
            else{
                ptr[*ptrsize] -> ptr[i] -> ptr[0] = createnode(tokens[*token_num]);
                ptr[*ptrsize] -> ptr[i] -> ptrsize = 1;
                *token_num = *token_num + 1;
            }
            *ptrsize = *ptrsize + 1;
            ptr = realloc(ptr,sizeof(Node*)*(*ptrsize + 1));
        }
    }
    root -> ptr = ptr;
    *token_num = *token_num + 1;
}

//creating AST
//input -> output from lexer
//output -> struct containing array of function AST node pointers(array_func),its size(func_size),array of headers and function declarations(extras),its size(extra_size),array of own created variables(my_variable)
parseroutput* parser(lexeroutput *toks){
    Token **tokens = toks -> token; 
    int token_num = 0;
    Token *extras =(Token*) malloc(sizeof(Token));
    int extra_size = 0;
    Node **array_func =(Node**) malloc(sizeof(Node*));
    int func_size = 0;
    parseroutput* output= malloc(sizeof(parseroutput));
  
    while(tokens[token_num]->type != END){
        if(tokens[token_num]->type == HEADER){
            extras[extra_size].type = tokens[token_num]->type;
            extras[extra_size].value = tokens[token_num]->value;
            extra_size += 1;
            token_num++;
            extras = realloc(extras,sizeof(Token)*(extra_size + 1));
        }
        else if(tokens[token_num]->type == FUNCTION || tokens[token_num]->type == START){
            if(tokens[token_num+1]->type == FUNC_CALL){
                extras[extra_size].type = tokens[token_num]->type;
                extras[extra_size].value = tokens[token_num]->value;
                extra_size++;
                extras = realloc(extras,sizeof(Token)*(extra_size+2));
                extras[extra_size].type = tokens[token_num+1]->type;
                extras[extra_size].value = tokens[token_num+1]->value;
                extra_size++;   
                token_num += 2;
            }
            else{
                array_func[func_size] = specialnode(tokens,&token_num);
                token_num++;
                create_tree(tokens,&token_num,array_func[func_size]->ptr[1],array_func[func_size] -> ptr[1] -> ptr,&(array_func[func_size] -> ptr[1] -> ptrsize));
                func_size++;
                array_func = realloc(array_func,sizeof(Node*)*(func_size+1));
            }
        }
    }
  /*for (int i = 0; i < extra_size; i++)
        printf("%s\n",extras[i].value);
    for (int i = 0; i < func_size; i++){
        printtree(array_func[i]);
        printf("here count\n");
        printf("%d\n",givecount(array_func[i]));
    }*/
    output->extras = extras;
    output->extra_size = extra_size;
    output->array_func = array_func;
    output->func_size = func_size;
    output -> my_variable = toks -> my_variable;
    return output;
}
