#include"prof.h"

bool one_statement_flag,in_function;//one_statement flag used to know if given loop or conditional statement contains one statement
                                    //in_function shows if pointer are in function
trie_node *root;//trie data structre to store user defined variables

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

//creates unique variable by seeing user defined variables
//output -> array of unique variables
char** create_my_variable(){
    int array[]={97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,95,48,49,50,51,52,53,54,55,56,57};
    char *string = malloc(sizeof(char)*31);
    int j,val;
    char **my_var = malloc(sizeof(char*)*2);
    for (int k = 0; k < 2; k++){
        do{
            j = 0;
            srand(time(NULL));
            val = rand();
            val = val%53;
            string[j++] =(char)array[val]; 
            for(int i = 1; i < 31; i++){
                val = rand();
                val = val%63;
                string[j++] =(char)array[val]; 
            }
            string[j] = 0;
        }while(is_in_trie(root,string));
        insert_in_trie(root,string);
        my_var[k] = malloc(sizeof(char)*33);
        strcpy(my_var[k],string);
        printf("var -> %s\n",my_var[k]);
    }
    return my_var;
}

//filter outs tabs,spaces,newlines for checking whole code
void filterextras(char *current,int *index){
    while(current[*index] == 9 || current[*index] == 32 || current[*index] == 10 )
        *index = *index + 1;
    return;
}

//filter outs tabs,spaces,newlines,* for cheching parameters
void filter_variablename_extras(char *current,int *index){
    while(current[*index] == 9 || current[*index] == 32 || current[*index] == 10 || current[*index] == 42 )
        *index = *index + 1;
    return;
}

//for checking next word after else for 'else if' condition in code
//input -> buffer array of code and current buffer array pointer
//output -> true if its 'else if' condition either false
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
    if(!strcmp(newtype,"if"))
        return 1;
    else{
        if (temp != *index)
            *index = temp;
        return 0;
    }
}

//create pointers of tokens of headers
//input -> buffer array of code and current buffer array pointer
//output -> token of header
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

//parses variable names
//input -> buffer array of code and current buffer array pointer
void check_var(char *current,int *index){
    int j = 0;
    bool flg = 0;
    int end_statement;
    char *var = malloc(sizeof(char)*33);
    while(current[*index] != ';' && current[*index] != '('){
        if(current[*index] == ','){
            var[j] = 0,j = 0;
            insert_in_trie(root,var);
           *index = *index + 1;
            filter_variablename_extras(current,index);
        }
        else if(current[*index] == '=' || current[*index] == '['){    
            var[j] = 0,j = 0;
            insert_in_trie(root,var);
            *index = *index + 1;
            filter_variablename_extras(current,index);
            while(current[*index] != ',' && current[*index] != ';')
                *index = *index + 1;
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
        insert_in_trie(root,var);
    }
    return;
} 

//add variables names redeclared by typedef
//input -> buffer array of code and current buffer array pointer
void check_redeclared_names(char* current,int *index){
    while(current[*index] != '}')
        *index = *index + 1;
    *index = *index + 1;
    filter_variablename_extras(current,index);
    check_var(current,index);
    return;
}

//check data types starting from 'short' data type
//input -> buffer array of code and current buffer array pointer
//output -> gives index of buffer array from where variable names starts
int* short_type_variables(char *current,int *index){
    char *var = malloc(sizeof(char)*32);
    filter_variablename_extras(current,index);
    int i = 0;
    int tmp = *index; 
    while(isalpha(current[*index])|| isdigit(current[*index])||current[*index] == 95){
        var[i] = current[*index];
        *index = *index + 1;
    }  
    var[i] = 0,i = 0;
    if(!strcmp(var,"int")){
        filter_variablename_extras(current,index);
        return index;
    }
    else{
        *index = tmp;
        return index;
    }
}
 
//check data types starting from 'long' data type
//input -> buffer array of code and current buffer array pointer
//output -> gives index of buffer array from where variable names starts  
int* long_type_variables(char *current,int *index){
    char *var = malloc(sizeof(char)*32);
    filter_variablename_extras(current,index);
    int i = 0;
    int tmp = *index; 
    while(isalpha(current[*index])||isdigit(current[*index])||current[*index] == 95)
        var[i] = current[*index];
    var[i] = 0,i = 0;
    if(!strcmp(var,"int")||!strcmp(var,"double")){
        filter_variablename_extras(current,index);
        return index;
    }
    else if(!strcmp(var,"long")){
        filter_variablename_extras(current,index);
        tmp = *index; 
        while(isalpha(current[*index]) || isdigit(current[*index])||current[*index] == 95){
            var[i] = current[*index];
            *index = *index + 1;
        }  
        var[i] = 0,i = 0;
        if(!strcmp(var,"int")){
            filter_variablename_extras(current,index);
            return index;
        }
        else{
            *index = tmp;
            return index;
        }   
    }
    else{
        *index =tmp;
        return index;
    }
}

//check data types starting from 'signed' and 'unsigned' data type
//input -> buffer array of code and current buffer array pointer
//output -> gives index of buffer array from where variable names starts
int* signed_unsigned_type_variables(char *current,int *index){
    char *var = malloc(sizeof(char)*32);
    filter_variablename_extras(current,index);
    int i = 0;
    int tmp = *index; 
    while(isalpha(current[*index])||isdigit(current[*index])||current[*index]==95){
        var[i] = current[*index];
        *index = *index + 1;
    }  
    var[i] = 0,i = 0;
    if(!strcmp(var,"int")||!strcmp(var,"char")||!strcmp(var,"short")||!strcmp(var,"long")){
        filter_variablename_extras(current,index);
        return index;
    }
    else{
        *index = tmp;
        return index;
    }
}

//add parameters names in variables array
//input -> array of parameters and its current index
void add_parameters_name(char* newtype,int* j){
    char *var = malloc(sizeof(char)*32);
    int i = 0;
    while(isalpha(newtype[*j])||isdigit(newtype[*j])||newtype[*j] == 95){
        var[i++] = newtype[*j];
        *j = *j + 1;
    }  
    var[i] = 0;
    insert_in_trie(root,var);
    while(newtype[*j] != ',' && newtype[*j] != ')')
       *j = *j + 1;
    return;
}

//to handle the start and end of FUNCTIONs,LOOPs,CONDITIONAL_STATEMENTs checks if given string in paranthesis is condition or parameters
//input -> buffer array of code and current buffer array pointer
//output -> token pointer
Token *check_braces(char *current,int *index){
    Token *token = malloc(sizeof(Token));
    profiler_stk *st = malloc(sizeof(profiler_stk));
    st -> top = -1;
    st -> size = 10;
    st -> arr = (int*)malloc(sizeof(int)*st -> size);
    if(current[*index] == '('){
        int newsize = 10;
        int size = 0;
        char *newtype = malloc(sizeof(char)*newsize);
        profiler_push(st,1);
        newtype[size] = current[*index];
        *index = *index + 1;
        size++;
        while(st -> top != -1){
            if(current[*index] == ')')
                profiler_pop(st);
            else if(current[*index] == '(')
                profiler_push(st,1);
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
            if(in_function == 1){
                char *var = malloc(sizeof(char)*32);
                int i = 0,j = 1;
                bool flg = 0;
                while(flg != 1){
                    filterextras(newtype,&j);
                    if(newtype[j] == ')')
                        break;                
                    while(isalpha(newtype[j])||isdigit(newtype[j])||newtype[j] == 95)
                        var[i++] = newtype[j++];
                    var[i]= 0 ,i = 0;
                    if(!strcmp(var,"int")||!strcmp(var,"char")||!strcmp(var,"float")||!strcmp(var,"bool")||!strcmp(var,"_Bool")||!strcmp(var,"void")||!strcmp(var,"double")||!strcmp(var,"size_t")||!strcmp(var,"int8_t")||!strcmp(var,"uint8_t")||!strcmp(var,"int16_t")||!strcmp(var,"ptrdiff_t")){
                        filter_variablename_extras(newtype,&j);
                        if(newtype[j] == ')')
                            break;                
                        add_parameters_name(newtype,&j);
                        if(newtype[j] == ',') j++;
                        else flg = 1;
                    }
                    else if(!strcmp(var,"short")){
                        short_type_variables(newtype,&j);
                        if(newtype[j] == ')')
                            break;                
                        add_parameters_name(newtype,&j);
                        if(newtype[j] == ',') j++;
                        else flg = 1;
                    }
                    else if(!strcmp(var,"long")){
                        long_type_variables(newtype,&j);
                        if(newtype[j] == ')')
                            break;                
                        add_parameters_name(newtype,&j);
                        if(newtype[j] == ',') j++;
                        else flg = 1;
                    }
                    else if(!strcmp(var,"signed") || !strcmp(var,"unsigned")){
                        signed_unsigned_type_variables(newtype,&j);
                        if(newtype[j] == ')')
                            break;                
                        add_parameters_name(newtype,&j);
                        if(newtype[j] == ',') j++;
                        else flg = 1;
                    }
                    else if(!strcmp(var,"struct")){
                        filterextras(newtype,&j);
                        while(isalpha(newtype[j])||isdigit(newtype[j])||newtype[j] == 95)
                            j++;
                        filter_variablename_extras(newtype,&j);
                        add_parameters_name(newtype,&j);
                        if(newtype[j] == ',') j++;
                        else flg = 1;
                    }
                }
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


//check type of token if its STATEMENT,LOOP,CONDITIONAL_STATEMENT,FUNCTION
//input -> buffer array of code ,current buffer array pointer,user's file length and flag which tells if I have visited main or not
//output -> token pointer
Token *check_type(char *current,int *index,int length,bool *flag){
    Token *token = malloc(sizeof(Token));
    int newsize = 8;
    char *newtype = malloc(sizeof(char)*newsize);
    int size = 0;
    char temp[5];
    one_statement_flag = 0,in_function = 0;
    while((isalpha(current[*index])||isdigit(current[*index])||current[*index]==95) && *index < length){
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
        if(next_word(current,index)){
            token -> type = CONDITIONAL_STATEMENT;
            token -> value = "else if";
            one_statement_flag = 1;
        }
        else{
            token -> type = CONDITIONAL_STATEMENT;
            token -> value = "else";
        }
    }
    else{
        char *var = malloc(sizeof(char)*32);
        int i = 0;
        int tmp = *index;
        if(!strcmp(newtype,"int")||!strcmp(newtype,"char")||!strcmp(newtype,"float")||!strcmp(newtype,"bool")||!strcmp(newtype,"_Bool")||!strcmp(newtype,"void")||!strcmp(newtype,"double")||!strcmp(newtype,"size_t")||!strcmp(newtype,"int8_t")||!strcmp(newtype,"uint8_t")||!strcmp(newtype,"int16_t")||!strcmp(newtype,"ptrdiff_t")){
            filter_variablename_extras(current,index);
            check_var(current,index); 
        }
        else if(!strcmp(newtype,"short"))
            check_var(current,short_type_variables(current,index));
        else if(!strcmp(newtype,"long"))
            check_var(current,long_type_variables(current,index));
        else if(!strcmp(newtype,"signed") || !strcmp(newtype,"unsigned"))
            check_var(current,signed_unsigned_type_variables(current,index));
        else if(!strcmp(newtype,"struct")){
            filterextras(current,index);
            while(isalpha(current[*index])||isdigit(current[*index])||current[*index] == 95){
                var[i] = current[*index];
                *index = *index + 1;
            }  
            var[i] = 0,i = 0;
            insert_in_trie(root,var);
        }
        else if(!strcmp(newtype,"typedef")){
            filterextras(current,index);
            while(isalpha(current[*index])||isdigit(current[*index])||current[*index] == 95){
                var[i] = current[*index];
                *index = *index + 1;
            }  
            var[i] = 0,i = 0;
            filter_variablename_extras(current,index);
            if(current[*index] != '{')
                check_redeclared_names(current,index);     
            else if(!strcmp(var,"struct")){
                while(isalpha(current[*index])||isdigit(current[*index])||current[*index] == 95){
                    var[i] = current[*index];
                    *index = *index + 1;
                }  
                var[i] = 0,i = 0;
                insert_in_trie(root,var);
                check_redeclared_names(current,index);
            }  
            else if(!strcmp(var,"int")||!strcmp(var,"char")||!strcmp(var,"float")||!strcmp(var,"bool")||!strcmp(var,"_Bool")||!strcmp(var,"void")||!strcmp(var,"double")||!strcmp(var,"size_t")||!strcmp(var,"int8_t")||!strcmp(var,"uint8_t")||!strcmp(var,"int16_t")||!strcmp(var,"ptrdiff_t")){
                filter_variablename_extras(current,index);
                check_var(current,index); 
            }
            else if(!strcmp(var,"short"))
                check_var(current,short_type_variables(current,index));
            else if(!strcmp(var,"long"))
                check_var(current,long_type_variables(current,index));
            else if(!strcmp(var,"signed") || !strcmp(var,"unsigned"))
                check_var(current,signed_unsigned_type_variables(current,index));
        }
        *index = tmp;
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
            for(int i = size - 5; i < size + 1; i++)
                temp[j] = newtype[i],j++;
        }
        if(strcmp(temp," main") == 0){
            token -> type = START;
            token -> value = newtype;
            *flag = 1,in_function = 1;
        }
        else if(current[*index] == '('){
            token -> type = FUNCTION;
            token -> value = newtype;
            in_function = 1;
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
//input -> takes user's file pointer
//output -> give structure containg array of token pointers ,it's size and pointer of array of my own created variables
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
    root= create_trie_node();
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
    output -> my_variable = create_my_variable();
   // for(int i = 0; tokens[i]->type != END; i++)
     //   printtokens(tokens[i]);
    return output;
}     
