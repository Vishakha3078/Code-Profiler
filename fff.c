#include"prof.h"

bool one_statement_flag;
char **variables;
int variable_len = 15;
int variable_index = 0;

//print tokens
void printtokens(Token *token){
    printf("TOKEN VALUE : ");
    printf("'%s'",token->value);
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

//filter outs tabs,spaces,newlines
void filterextras(char *current,int *index){
    while(current[*index] == 9 || current[*index] == 32 || current[*index] == 10 )
        *index = *index + 1;
    return;
}
//filter outs tabs,spaces,newlines
void filter_variablename_extras(char *current,int *index){
    while(current[*index] == 9 || current[*index] == 32 || current[*index] == 10 || current[*index] == 42 )
        *index = *index + 1;
    return;
}


//for checking else if condition in code
bool next_word(char *current,int *index){
    int temp = *index;
    char *newtype = malloc(sizeof(char)* 33);
    int newsize = 0;
    filterextras(current,index);
    while(isalpha(current[*index])|| isdigit(current[*index])){
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

/*int* check_parameters(char* current,int *index){*/
/*    while(current[*index] != ',' || current[*index] != ')'){*/
/*        while*/
/*    }*/
/*}        */
//create pointers of token of headers 
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

void add_variable(char* var){
    if (variable_index >= variable_len){
            variable_len += 10;
            variables = realloc(variables,sizeof(char*)*variable_len);
        }
    variables[variable_index] = malloc(sizeof(char)*strlen(var)+1);
    strcpy(variables[variable_index],var);
    variable_index = variable_index + 1;
    return;    
}

void check_var(char *current,int *index){
    int j = 0;
    bool flg = 0;
    int end_statement;
    char *var = malloc(sizeof(char)*33);
    while(current[*index] != ';' && current[*index] != '('){
        if(current[*index] == ','){
            var[j] = 0;
            j = 0;
            add_variable(var);
           *index = *index + 1;
            filter_variablename_extras(current,index);
        }
        else if(current[*index] == '=' || current[*index] == '['){    
            var[j] = 0;
            j = 0;
            add_variable(var);
            *index = *index + 1;
            filter_variablename_extras(current,index);
            while(current[*index] != ',' && current[*index] != ';'){
                *index = *index + 1;
            }
            if(current[*index] == ';')
                flg = 1,end_statement = *index;
            *index = *index + 1;
            filter_variablename_extras(current,index);
        }
        var[j++] = current[*index];
        *index = *index + 1;
        filter_variablename_extras(current,index);
        if(flg == 1)
            *index = end_statement;
    }
    if(flg != 1){
        var[j] = 0;
        add_variable(var);
    }
    return;
} 

void check_redeclared_names(char* current,int *index){
    while(current[*index] != '}')
        *index = *index + 1;
    *index = *index + 1;
    filter_variablename_extras(current,index);
    check_var(current,index);
    return;
}

int* short_type_variables(char *current,int *index){
    char *var = malloc(sizeof(char)*32);
    filter_variablename_extras(current,index);
    int i = 0;
    int tmp = *index; 
    while(isalpha(current[*index])|| isdigit(current[*index])){
        var[i] = current[*index];
    }  
    var[i] = 0;
    i = 0;
    if(!strcmp(var,"int")){
        filter_variablename_extras(current,index);
        return index;
    }
    else{
        return index;
    }
}
   
int* long_type_variables(char *current,int *index){
    char *var = malloc(sizeof(char)*32);
    filter_variablename_extras(current,index);
    int i = 0;
    int tmp = *index; 
    while(isalpha(current[*index])||isdigit(current[*index])){
        var[i] = current[*index];
    }  
    var[i] = 0;
    i = 0;
    if(!strcmp(var,"int")||!strcmp(var,"double")){
        filter_variablename_extras(current,index);
        return index;
    }
    else if(!strcmp(var,"long")){
        filter_variablename_extras(current,index);
        tmp = *index; 
        while(isalpha(current[*index]) || isdigit(current[*index])){
            var[i] = current[*index];
        }  
        var[i] = 0;
        i = 0;
        if(!strcmp(var,"int")){
            filter_variablename_extras(current,index);
            return index;
        }
        else{
            return index;
        }   
    }
    else
        return index;
}


int* signed_unsigned_type_variables(char *current,int *index){
    char *var = malloc(sizeof(char)*32);
    filter_variablename_extras(current,index);
    int i = 0;
    int tmp = *index; 
    while(isalpha(current[*index])||isdigit(current[*index])){
        var[i] = current[*index];
    }  
    var[i] = 0;
    i = 0;
    if(!strcmp(var,"int")||!strcmp(var,"char")||!strcmp(var,"short")||!strcmp(var,"long")){
        filter_variablename_extras(current,index);
        return index;
    }
    else{
        return index;
    }
}

//to handle the start and end of FUNCTIONs,LOOPs,CONDITIONAL_STATEMENTs
Token *check_braces(char *current,int *index){
    Token *token = malloc(sizeof(Token));
    stk *st = malloc(sizeof(stk));
    st -> top = -1;
    st -> size = 10;
    st -> arr = (int*)malloc(sizeof(int)*st -> size);
    if(current[*index] == '('){
        int newsize = 10;
        int size = 0;
        char *newtype = malloc(sizeof(char)*newsize);
        push(st,1);
        newtype[size] = current[*index];
        *index = *index + 1;
        size++;
        while(st -> top != -1){
            if(current[*index] == ')')
                pop(st);
            else if(current[*index] == '(')
                push(st,1);
            newtype[size] = current[*index];
            *index = *index + 1;
            size++;
            if(size >= newsize){
                newsize += 8;
                newtype = realloc(newtype,sizeof(char)*newsize);
            }
        }
        filterextras(current,index);
        if(current[*index] != '{' && one_statement_flag != 1){
            while(current[*index] != ';'){
                if(size >= newsize){
                    newsize += 8;
                    newtype = realloc(newtype,sizeof(char)*newsize);
                }
                newtype[size] = current[*index];
                *index = *index + 1;
                size++;
            }
        }
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


//check_type of token if its STATEMENT,LOOP,CONDITIONAL_STATEMENT,FUNCTION
Token *check_type(char *current,int *index,int length,bool *flag){
    Token *token = malloc(sizeof(Token));
    int newsize = 8;
    char *newtype = malloc(sizeof(char)*newsize);
    int size = 0;
    char temp[5];
    one_statement_flag = 0;
    while((isalpha(current[*index])||isdigit(current[*index])) && *index < length){
        newtype[size] = current[*index];
        *index = *index + 1;
        size++;
        if(size >= newsize){
            newsize += 8;
            newtype = realloc(newtype,sizeof(char)*newsize);
        }
    } 
    newtype[size] = '\0';
  
    if(!strcmp(newtype,"while")){
        token -> type = LOOP;
        token -> value = "while";
        one_statement_flag = 1;
    }
    else if(strcmp(newtype,"if") == 0){
        token -> type = CONDITIONAL_STATEMENT;
        token -> value = "if";
        one_statement_flag = 1;
    }
    else if(!strcmp(newtype,"else")){
        *index = *index + 1;
        if(next_word(current,index)){
            token -> type = CONDITIONAL_STATEMENT;
            token -> value = "else if";
            *index = *index + 2;
            one_statement_flag = 1;
        }
        else{
            token -> type = CONDITIONAL_STATEMENT;
            token -> value = "else";
            *index = *index -1;
        }
    }
    else{
        char *var = malloc(sizeof(char)*32);
        int i = 0;
        int tmp,ttmp;
        ttmp = *index;
        if(!strcmp(newtype,"int")||!strcmp(newtype,"char")||!strcmp(newtype,"float")||!strcmp(newtype,"bool")||!strcmp(newtype,"_Bool")||!strcmp(newtype,"void")||!strcmp(newtype,"double")||!strcmp(newtype,"size_t")||!strcmp(newtype,"int8_t")||!strcmp(newtype,"uint8_t")||!strcmp(newtype,"int16_t")||!strcmp(newtype,"ptrdiff_t")){
            filter_variablename_extras(current,index);
            check_var(current,index); 
        }
        else if(!strcmp(newtype,"short")){
            check_var(current,short_type_variables(current,index));
        }
        else if(!strcmp(newtype,"long")){
            check_var(current,long_type_variables(current,index));
        }
        else if(!strcmp(newtype,"signed") || !strcmp(newtype,"unsigned")){
            check_var(current,signed_unsigned_type_variables(current,index));
        }
        else if(!strcmp(newtype,"struct")){
            filterextras(current,index);
            tmp = *index; 
            while(isalpha(current[*index])||isdigit(current[*index])){
                var[i] = current[*index];
            }  
            var[i] = 0;
            i = 0;
            add_variable(var);
        }
        else if(!strcmp(newtype,"typedef")){
            filterextras(current,index);
            tmp = *index;
            while(isalpha(current[*index])){
                var[i] = current[*index];
            }  
            var[i] = 0;
            i = 0;
            filter_variablename_extras(current,index);
            if(current[*index] != '{'){
                check_redeclared_names(current,index);     
            }
            else if(!strcmp(var,"struct")){
                while(isalpha(current[*index])||isdigit(current[*index])){
                    var[i] = current[*index];
                }  
                var[i] = 0;
                i = 0;
                add_variable(var);
                check_redeclared_names(current,index);
            }  
            else if(!strcmp(var,"int")||!strcmp(var,"char")||!strcmp(var,"float")||!strcmp(var,"bool")||!strcmp(var,"_Bool")||!strcmp(var,"void")||!strcmp(var,"double")||!strcmp(var,"size_t")||!strcmp(var,"int8_t")||!strcmp(var,"uint8_t")||!strcmp(var,"int16_t")||!strcmp(var,"ptrdiff_t")){
            filter_variablename_extras(current,index);
            check_var(current,index); 
            }
            else if(!strcmp(var,"short")){
                check_var(current,short_type_variables(current,index));
            }            
            else if(!strcmp(var,"long")){
                check_var(current,long_type_variables(current,index));
            }
            else if(!strcmp(var,"signed") || !strcmp(var,"unsigned")){
                check_var(current,signed_unsigned_type_variables(current,index));
            }
        }
        *index = ttmp;
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
    
        if(*flag != 1 && current[*index] == '('){
            int j = 0;
            for(int i = size - 5; i < size + 1; i++){
                temp[j] = newtype[i];
                j++;
            }
        }
        if(strcmp(temp," main") == 0){
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

//creates array of token pointers
lexeroutput *lexer(FILE *fp){
    int token_number= 20;//size of token array
    int index = 0;//index of cuirrent array
    bool flag = 0; 
    fseek(fp,0,SEEK_END);
    int length = ftell(fp);
    fseek(fp,0,SEEK_SET);
    char *current = malloc(sizeof(char)*length);
    fread(current,1,length,fp);
    fclose(fp);
    lexeroutput *output = malloc(sizeof(lexeroutput));
    Token **tokens = malloc(sizeof(Token*) * token_number);
    int token_index = 0;//current token
    variables = malloc(sizeof(char*)*variable_len);
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
    output -> token = tokens;
    output -> token_size = token_number;
  for (int i = 0;i < variable_index;i++) {
    printf("variables[i] = %s\n", variables[i]);
  }
    /*printf(" ");*/
    //for(int i = 0; tokens[i]->type != END; i++)
      //  printtokens(tokens[i]);
    return output;
}
