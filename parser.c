#include"prof.h"

//give the total number of count variables rerquired in given function
//input -> pointer of function node
//output -> varibles count of function
int givecount(Node *root){
    int count = 0;
    if(root -> type == LOOP || root -> type == CONDITIONAL_STATEMENT || root -> type == FUNCTION || root -> type == START)
     {   count++;
     printf("       root -> %s \n",root -> value);
        printf("          cnt++\n");}
    for(int i = 0; i< root -> ptrsize; i++)
        count += givecount(root -> ptr[i] );             
    return count;
}

//prints an AST of given function
void printtree(Node *root){
    printf("%s\n",root -> value);
    for(int i = 0; i < root -> ptrsize; i++)
        printtree(root -> ptr[i]);
    return;
}

//creates AST node
//input -> token pointer
//output -> node containing token
Node *createnode(Token *token){
    Node *newnode = malloc(sizeof(Node));
    newnode -> type = token->type;
    newnode -> value = token->value;
    newnode -> ptr = malloc(sizeof(Node*));
    newnode -> ptrsize = 0;
    return newnode;
}

Node *specialnode(Token **tokens,int *token_num){
    Node *newnode = malloc(sizeof(Node));
    newnode -> type = tokens[*token_num]->type;
    newnode -> value = tokens[*token_num]->value;
    newnode -> ptr = malloc(sizeof(Node*)*2);
    newnode -> ptrsize = 1;
    *token_num = *token_num + 1;
    newnode -> ptr[0] = createnode(tokens[*token_num]);
    *token_num = *token_num + 1;
    return newnode;    
}

void create_tree(Token **tokens,int *token_num,Node *root,Node **ptr,int *ptrsize){
    while(tokens[*token_num]->type != CURLY){
        if(tokens[*token_num]->type == STATEMENT || tokens[*token_num]->type == FUNCTION || tokens[*token_num]->type == FUNC_CALL){
            ptr[*ptrsize] = createnode(tokens[*token_num]);
            *ptrsize = *ptrsize+1;
            *token_num = *token_num + 1;
            ptr = realloc(ptr,sizeof(Node*)*(*ptrsize + 1));
        }   
        else if(tokens[*token_num]->type == LOOP || tokens[*token_num]->type == CONDITIONAL_STATEMENT ){
            if(!strcmp(tokens[*token_num]-> value,"else")){
                ptr[*ptrsize]= createnode(tokens[*token_num]);
                *token_num = *token_num + 1;
                if(tokens[*token_num]->type == CURLY ){
                    *token_num = *token_num + 1;
                    create_tree(tokens,token_num,ptr[*ptrsize],ptr[*ptrsize] -> ptr,&(ptr[*ptrsize] -> ptrsize));
                }
                else{
                    ptr[*ptrsize] -> ptr[0]  = createnode(tokens[*token_num]);
                    ptr[*ptrsize] -> ptrsize = 1;
                    *token_num = *token_num + 1;
                }
            }
            else{
                ptr[*ptrsize] = specialnode(tokens,token_num);
                if(tokens[*token_num]->type == CURLY ){
                    *token_num = *token_num + 1;
                    create_tree(tokens,token_num,ptr[*ptrsize]->ptr[0],ptr[*ptrsize] -> ptr[0] -> ptr,&(ptr[*ptrsize] -> ptr[0] -> ptrsize));
                }
                else{
                    ptr[*ptrsize] -> ptr[0] -> ptr[0] = createnode(tokens[*token_num]);
                    ptr[*ptrsize] -> ptr[0] -> ptrsize = 1;
                    *token_num = *token_num + 1;
                }
            }
            *ptrsize = *ptrsize + 1;
            ptr = realloc(ptr,sizeof(Node*)*(*ptrsize + 1));
        }
    }
    root -> ptr = ptr;
    *token_num = *token_num + 1;
}

//creating parse tree
parseroutput* parser(lexeroutput *toks){
    Token **tokens = toks -> token; 
    int token_num = 0;
    Token *extras =(Token*) malloc(sizeof(Token));
    int extra_size = 0;
    Node **array_func =(Node**) malloc(sizeof(Node*));
    int func_index = 0;
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
                array_func[func_index] = specialnode(tokens,&token_num);
                token_num++;
                create_tree(tokens,&token_num,array_func[func_index]->ptr[0],array_func[func_index] -> ptr[0] -> ptr,&(array_func[func_index] -> ptr[0] -> ptrsize));
                func_index++;
                array_func = realloc(array_func,sizeof(Node*)*(func_index+1));
            }
        }
    }
    //for(int i =  0; i < toks -> token_size; i++){
  //      free(toks -> token[i]);
//    }
  for (int i = 0; i < extra_size; i++)
        printf("%s\n",extras[i].value);
    for (int i = 0; i < func_index; i++){
        printtree(array_func[i]);
        printf("here count\n");
        printf("count -> %d\n",givecount(array_func[i]));
    }
    output->extras = extras;
    output->extra_size = extra_size;
    output->array_func = array_func;
    output->func_index = func_index;
    output -> my_variable = toks -> my_variable;
    return output;
}
