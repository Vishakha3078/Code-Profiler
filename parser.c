#include"prof.h"

void printtree(Node *root){
    printf("%s\n",root -> value);
    for(int i = 0; i < root -> ptrsize; i++){
        printtree(root -> ptr[i]);
    }
    return;
}

Node *createnode(Token *token){
    Node *newnode = malloc(sizeof(Node));
    newnode -> type = token->type;
    newnode -> value = token->value;
    newnode -> ptr = malloc(sizeof(Node*));
    newnode -> ptrsize = 0;
    return newnode;
}


Node *createcountnode(){
    Node *newnode = malloc(sizeof(Node));
    newnode -> type = COUNT;
    newnode -> value ="cnt++";// array[count_index]
    //count_index++;
    newnode -> ptr = malloc(sizeof(Node*));
    newnode -> ptrsize = 0;
    return newnode;
}


Node *createnode_else(Token *token){
    Node *newnode = malloc(sizeof(Node));
    newnode -> type = token -> type;
    newnode -> value = token -> value;
    newnode -> ptr = malloc(sizeof(Node*));
    newnode -> ptrsize = 1;    
    newnode -> ptr[0] = createcountnode();
    return newnode;
}


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


void create_tree(Token **tokens,int *token_num,Node *root,Node **ptr,int *ptrsize){
    while(tokens[*token_num]->type != CURLY){
        if(tokens[*token_num]->type == STATEMENT || tokens[*token_num]->type == FUNCTION || tokens[*token_num]->type == FUNC_CALL){
            ptr[*ptrsize] = createnode(tokens[*token_num]);
            *ptrsize = *ptrsize+1;
            *token_num = *token_num + 1;
            ptr = realloc(ptr,sizeof(Node*)*(*ptrsize + 1));
        }   
        else if(!strcmp(tokens[*token_num]-> value,"else")){
            ptr[*ptrsize]= createnode_else(tokens[*token_num]);
            *token_num = *token_num + 1;
            if(tokens[*token_num]->type == CURLY ){
                *token_num = *token_num + 1;
                create_tree(tokens,token_num,ptr[*ptrsize]->ptr[0],ptr[*ptrsize] -> ptr[0] -> ptr,&(ptr[*ptrsize] -> ptr[0] -> ptrsize));
            }
            else{
                ptr[*ptrsize] -> ptr[0] -> ptr[0] = createnode(tokens[*token_num]);
                ptr[*ptrsize] -> ptr[0] -> ptrsize = 1;
                *token_num = *token_num + 1;
            }
            *ptrsize = *ptrsize + 1;
            ptr = realloc(ptr,sizeof(Node*)*(*ptrsize + 1));
        }
        else if(tokens[*token_num]->type == LOOP || tokens[*token_num]->type == CONDITIONAL_STATEMENT ){
            ptr[*ptrsize] = specialnode(tokens,token_num);
            if(tokens[*token_num]->type == CURLY ){
                *token_num = *token_num + 1;
                create_tree(tokens,token_num,ptr[*ptrsize]->ptr[1],ptr[*ptrsize] -> ptr[1] -> ptr,&(ptr[*ptrsize] -> ptr[1] -> ptrsize));
            }
            else{
                ptr[*ptrsize] -> ptr[1] -> ptr[0] = createnode(tokens[*token_num]);
                ptr[*ptrsize] -> ptr[1] -> ptrsize = 1;
                *token_num = *token_num + 1;
            }
            *ptrsize = *ptrsize + 1;
            ptr = realloc(ptr,sizeof(Node*)*(*ptrsize + 1));
        }
    }
    root -> ptr = ptr;
    *token_num = *token_num + 1;
}

parseroutput* parser(Token **tokens){
    int token_num = 0;
    Token *extras =(Token*) malloc(sizeof(Token));
    int extra_size = 0;
    Node **array_func =(Node**) malloc(sizeof(Node*));
    int func_index = 0;
    Node *root;
    parseroutput* output= malloc(sizeof(parseroutput));
  
    while(tokens[token_num]->type != END){
        if(tokens[token_num]->type == HEADER){
            extras[extra_size].type = tokens[token_num]->type;
            extras[extra_size].value = tokens[token_num]->value;
            extra_size += 1;
            token_num++;
            extras = realloc(extras,sizeof(Token)*(extra_size + 1));
        }
        else if(tokens[token_num]->type == FUNCTION){
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
                token_num = token_num + 1;
                create_tree(tokens,&token_num,array_func[func_index]->ptr[1],array_func[func_index] -> ptr[1] -> ptr,&(array_func[func_index] -> ptr[1] -> ptrsize));
                func_index = func_index + 1;
                array_func = realloc(array_func,sizeof(Node*)*func_index);
            }
        }
        else{
            root = specialnode(tokens,&token_num);
            token_num = token_num + 1;
            create_tree(tokens,&token_num,root->ptr[1],root -> ptr[1] -> ptr,&(root -> ptr[1] -> ptrsize));
        }
    }
      if(tokens[token_num] -> type == END)
    printtree(root);
    output->extras = extras;
    output->extra_size = extra_size;
    output->array_func = array_func;
    output->func_index = func_index;
    output->root = root; 
    return output;
}
