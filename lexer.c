#include"prof.h"

void printtokens(Token *token){
    printf("TOKEN VALUE : ");
    printf("'");
    for(int i = 0; token->value[i] != '\0'; i++)
        printf("%c",token->value[i]);
    printf("'");
    switch(token->type){
        case STATEMENT:
            printf(" TOKEN TYPE: STATEMENT\n");
            break;
        case CONDITIONAL_STATEMENT:
            printf(" TOKEN TYPE: CONDITIONAL_STATEMENT\n");
            break;
        case FUNCTION:
            printf(" TOKEN TYPE: FUNCTION\n");
            break;
        case LOOP:
            printf(" TOKEN TYPE: LOOP\n");
            break;
        case HEADER:
            printf(" TOKEN TYPE: HEADER\n");
            break;
        case START:
            printf(" TOKEN TYPE: START\n");
            break;
        case FUNC_CALL:
            printf(" TOKEN TYPE: FUNC_CALL\n");
            break;
        case CURLY:
            printf(" TOKEN TYPE: CURLY\n");
            break;
    }        
}

void filterextras(char *current,int *index){
    while(current[*index] == 9 || current[*index] == 32 || current[*index] == '\n')
        *index = *index + 1;
    return;
}

bool next_two_char(char *current,int *index){
    int temp = *index;
    char *newtype = malloc(sizeof(char)* 3);
    int newsize = 0;
    while(isalpha(current[*index]) && newsize < 3){
        newtype[newsize] = current[*index];
        *index = *index + 1;
        newsize++;
    }
    newtype[newsize] = '\0';
    if(strcmp(newtype,"if"))
        return 0;
    else{
        if (temp != *index)
            *index = temp;
        return 1;
    }
}

Token *check_braces(char *current,int *index){
    Token *token = malloc(sizeof(Token));
    if(current[*index] == '('){
        int newsize = 10;
        int size = 0;
        char *newtype = malloc(sizeof(char)*newsize);
        while(current[*index] != ')'){
            newtype[size] = current[*index];
            *index = *index + 1;
            size++;
            if(size >= newsize){
                newsize += 8;
                newtype = realloc(newtype,sizeof(char)*newsize);
            }
        }
        newtype[size] = current[*index];
        *index = *index + 1;
        size++;
        filterextras(current,index);
        if(size >= newsize)
            newtype = realloc(newtype,sizeof(char)*(newsize+2));
        
        if(current[*index] == ';'){
            newtype[size] = current[*index];
            size++;
            newtype[size] = '\0';
            token -> type = FUNC_CALL;
            token -> value = newtype;
            *index = *index + 1;
        }
        else{
            newtype[size] = '\0';
            token -> type = STATEMENT;
            token -> value = newtype;
        }
    } 
    else if(current[*index] == '{'){
        token -> type = CURLY;
        token -> value = "{";
        *index = *index + 1;
    }
    else if(current[*index] == '}'){
        token -> type = CURLY;
        token -> value = "}";
        *index = *index + 1;
    }
    filterextras(current,index);
    return token;
}

Token *create_lib(char *current,int *index){
    Token *token = malloc(sizeof(Token));
    int newsize = 10;
    char *newtype = malloc(sizeof(char) * newsize);
    int size = 0;

    while(current[*index] != '\n'){
        newtype[size] = current[*index];
        *index = *index + 1;
        size++;
        if(size >= newsize){
            newsize += 8;
            newtype = realloc(newtype,sizeof(char)*newsize);
        }
    }
    newtype[size] = '\0';
    token -> type = HEADER;
    token -> value = newtype;
    filterextras(current,index);
    return token;
}

Token *check_type(char *current,int *index,int length,bool *flag){
    Token *token = malloc(sizeof(Token));
    int newsize = 8;
    char *newtype = malloc(sizeof(char)*newsize);
    int size = 0;
    char temp[5];

    while(isalpha(current[*index]) && *index < length){
        newtype[size] = current[*index];
        *index = *index + 1;
        size++;
        if(size >= newsize){
            newsize += 8;
            newtype = realloc(newtype,sizeof(char)*newsize);
        }
    } 
    newtype[size] = '\0';
    if (strcmp(newtype,"while") == 0){
        token -> type = LOOP;
        token -> value = "while";
    }
    else if(strcmp(newtype,"if") == 0){
        token -> type = CONDITIONAL_STATEMENT;
        token -> value = "if";
    }
    else if(strcmp(newtype,"else") == 0){
        *index = *index + 1;
        if(next_two_char(current,index)){
            token -> type = CONDITIONAL_STATEMENT;
            token -> value = "else if";
            *index = *index + 2;

        }
        else{
            token -> type = CONDITIONAL_STATEMENT;
            token -> value = "else";
            *index = *index -1;
        }
    }
    else{
        if(current[*index] == '('){
            int val = *index;
            *index = *index + 1;
            filterextras(current,index);
            if(current[*index]== '"'){
                newtype[size] = '(';
                size++;
                if(size >= newsize)
                    newtype = realloc(newtype,sizeof(char)*(newsize+1));
                *index = val + 1;
            }
            else
                *index = val;
        }
                
        while(current[*index] != ';' && current[*index] != '('){
            newtype[size] = current[*index];
            *index = *index + 1;
            size++;
            if(size >= newsize){
                newsize += 8;
                newtype = realloc(newtype,sizeof(char)*newsize);
            }
        }

        if(current[*index] == ';'){
            newtype[size] = ';';
            size++;
            *index = *index + 1;
        }            

        if(size >= newsize)
            newtype = realloc(newtype,sizeof(char)*(newsize+1));
        newtype[size] = '\0';
    
        if(*flag != 1){
            int j = 0;
            for(int i = size - 5; i < size + 1; i++){
                temp[j] = newtype[i];
                j++;
            }
        }
        if(strcmp(temp," main") == 0 && *flag != 1){
            token -> type = START;
            token -> value = newtype;
            *flag = 1;
        }
        else if(current[*index] == '('){
            token -> type = FUNCTION;
            token -> value = newtype;
        }
        else{
            token -> type  = STATEMENT;
            token -> value = newtype;
        }
    }
    filterextras(current,index);
    return token;
}


Token **lexer(FILE *f){
    int token_number= 20;//size of token array
    int index = 0;//index of cuirrent array
    bool flag = 0; 
    fseek(f,0,SEEK_END);
    int length = ftell(f);
    fseek(f,0,SEEK_SET);
    char *current = malloc(sizeof(char)*length);
    fread(current,1,length,f);
    fclose(f);
    Token **tokens = malloc(sizeof(Token*) * token_number);
    int token_index = 0;//current token

    while(index < length){
        if(current[index] == '#'){
            tokens[token_index] = create_lib(current,&index);
            token_index++;
        }
        else if(isalpha(current[index])){
            tokens[token_index] = check_type(current,&index,length,&flag);
            token_index++;
        }
        else{
            tokens[token_index] = check_braces(current,&index);
            token_index++;
        }
        if (token_index >= token_number){
            token_number += 20;
            tokens = realloc(tokens,sizeof(Token*)*token_number);
        }
    }  
    Token *newtype= malloc(sizeof(Token*));
    newtype ->type = END;
    newtype ->value = "\0";
    tokens[token_index] = newtype;

  // for(int i = 0; tokens[i]->type != END; i++)
    //   printtokens(tokens[i]);
    return tokens;
}
