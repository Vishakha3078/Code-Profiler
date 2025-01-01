#include"prof.h"
/*
FILE *fp;
char* curr_func_name;
parseroutput *given_func;
int if_else_index = 0;
bool flag = 0;
char *tabs = "    ";
char c = (char)92;
char n = 'n';
char quotes = (char)34;
char *my_unique_variable,*temporary_listhead,*temp_head_val,*temp_head_val_plus,*temp_head_next,*temp_head_traverse;

char* my_strcat(char* s1,char* s2){
    int n = strlen(s1);
    int m = strlen(s2);
    char* out = malloc(sizeof(char)*n+m+1);
    strcpy(out,s1);
    strcpy(out+n,s2);
    strcpy(out+n+m,"\0");
    return out;
}

char* print_check(char* s){
    int len = strlen(s);
    int j = 1;
    int i = 0,k = 0,l = 0,m = 0;
    char *str = malloc(sizeof(char)*len+1);
    for(i = 0; i < len; i++){
        if(s[i] == '%'){
            j++;
            str = realloc(str,sizeof(char)*(len+j));
            str[k] = s[i];
            k++;
        }
        else if(s[i] == (char)34){
            m++;
            str = realloc(str,sizeof(char)*(len+m));
            str[k] = (char)92;
            k++;
        }
        else if(s[i] == (char)92){
            l++;
            str = realloc(str,sizeof(char)*(len+l));
            str[k] = (char)92;
            k++;
        }str[k] = s[i];
        k++;
    }
    return str;
}

char* increase_space(char *string1){
    char *string2 = "    ";
    int n = strlen(string1);
    int m = strlen(string2);
    char* res = malloc(sizeof(char)*n+m);
    strcpy(res,string1);
    strcpy(res+n,string2);
    return res;
}

char* decrease_space(char* string){
    int n = strlen(string);
    string[n-4] = '\0';
    return string;
}

char* remove_return_type(char *s){
    int len = strlen(s);
    int i = len - 1;
    int j = 0;
    while(*(s+i) != ' '){
        i--;j++;
    }
    char *str = &s[len-j];
    return str;
}

char* give_declaration(char* a){
    return my_strcat(my_strcat("ListNode* ",a),"_cnt;\n");
}

char* give_alloc(char* a,int count){
    char* tmp = malloc(10);
    sprintf(tmp, "%d",count);
    char* cnt = my_strcat(a,my_strcat(my_strcat(" = makelist(",tmp),");\n"));
    return cnt;
}

void addnewline(){
    char *newline = "\n";
    fwrite(newline,sizeof(char),1,fp); 
    return;
}

void addcount(){
    char *str = my_strcat(temporary_listhead," -> val++;\n");
    int len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    return;    
}

void alloc_all_lists(){
    char* tmp = malloc(10);
    sprintf(tmp, "%d",given_func -> func_index);
    char *str = my_strcat(my_strcat(my_strcat(my_unique_variable, "=malloc(sizeof(ListNode*)*"),tmp),");\n");
    int len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    for(int i= 0; i < given_func -> func_index; i++){
        sprintf(tmp,"%d",i);
        str = give_alloc(my_strcat(my_strcat(my_strcat(my_unique_variable,"["),tmp),"]"),givecount(given_func->array_func[i]));
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
    }
    return;
}

void function_count(Node *root){
    char *str;
    int j = 1;
    str = "printf(";
    int len = strlen(str);
    fwrite(str,sizeof(char),len,fp);    
    fwrite(&quotes,sizeof(char),1,fp);

    if(!strcmp(root -> value,"else")){
        str = my_strcat("           \033[0;33m%7d\033[0m    |\033[0;34m",my_strcat(my_strcat(tabs,root -> value),"\033[0m{"));
        j =0;
    }
    else if(root -> type == START || root -> type == FUNCTION)
        str =my_strcat("           \033[0;33m%7d\033[0m    |\033[0;31m",my_strcat(tabs,my_strcat(my_strcat(root -> value ,print_check(root->ptr[0]->value)),"\033[0m{")));
    else
         str =my_strcat("           \033[0;33m%7d\033[0m    |\033[0;34m",my_strcat(tabs,my_strcat(my_strcat(root -> value ,print_check(root->ptr[0]->value)),"\033[0m{")));
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    fwrite(&c,sizeof(char),1,fp);
    fwrite(&n,sizeof(char),1,fp);     
    fwrite(&quotes,sizeof(char),1,fp);
    if(root -> type == START || root -> type == FUNCTION || !strcmp(root ->value,"else")){
        str = my_strcat(",",my_strcat(my_strcat(temp_head_val,");\npush(profiler_stack,"),my_strcat(temp_head_val,");\n"))); 
    }
    else if(root -> type == CONDITIONAL_STATEMENT)
        str = my_strcat(my_strcat(",profiler_if_else_condition_stk -> arr[profiler_if_else_condition_stk -> top]);\npush(profiler_stack,",temp_head_val),");\n");
    else{
            str = my_strcat(",profiler_stack -> arr[profiler_stack -> top] +",my_strcat(my_strcat(my_strcat(temporary_listhead," -> next -> val);\n"),temp_head_next),my_strcat(my_strcat("push(profiler_stack,",temp_head_val),");\n"))); 
    }
    
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    tabs = increase_space(tabs);  
    for(int i = 0; i < root -> ptr[j] -> ptrsize; i++){
        if(root->ptr[j]->ptr[i]->type == STATEMENT || root->ptr[j]->ptr[i]->type == FUNCTION){
            str = "printf(";
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);    
            fwrite(&quotes,sizeof(char),1,fp);
            
            if(root->ptr[j]->ptr[i]->type == FUNCTION){
                str = my_strcat("           \033[0;33m%7d\033[0m    |",my_strcat(my_strcat(tabs,root -> ptr[j]-> ptr[i] -> value),print_check(root -> ptr[j]->ptr[i+1]->value))); 
                i++;
            }
            else{
                str = my_strcat("           \033[0;33m%7d\033[0m    |",my_strcat(tabs,print_check(root->ptr[j]->ptr[i]->value)));
            }
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
            fwrite(&c,sizeof(char),1,fp);
            fwrite(&n,sizeof(char),1,fp);
            fwrite(&quotes,sizeof(char),1,fp);
            str = ",profiler_stack ->arr[profiler_stack->top]);\n";
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
        }
        else if(root->ptr[j]->ptr[i]->type == LOOP){
           function_count(root ->ptr[j] -> ptr[i]);
        }
        else{
            if(!strcmp(root->ptr[j]->ptr[i]->value,"if"))
                str = my_strcat(my_strcat("push(profiler_if_else_condition_stk,profiler_stack -> arr[profiler_stack ->  top]);\n",temp_head_next),";\n");
            else if(!strcmp(root->ptr[j]->ptr[i]->value,"else if"))
                str = my_strcat(my_strcat("push(profiler_if_else_condition_stk,pop(profiler_if_else_condition_stk) - (",temp_head_val),my_strcat(");\n",temp_head_next));
            else
                str = temp_head_next;
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
            function_count(root -> ptr[j] -> ptr[i]);
            if(i+1 < root -> ptr[j] -> ptrsize){
            if(strcmp(root->ptr[j]->ptr[i+1]->value,"else if")){
                str = "pop(profiler_if_else_condition_stk);\n";
                len = strlen(str);
                fwrite(str,sizeof(char),len,fp);
            }
            }
        }
    }
    tabs = decrease_space(tabs);
    str = "printf(";
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);    
    fwrite(&quotes,sizeof(char),1,fp);
    str = my_strcat("                      |",my_strcat(tabs,"}"));
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    fwrite(&c,sizeof(char),1,fp);
    fwrite(&n,sizeof(char),1,fp);
    fwrite(&quotes,sizeof(char),1,fp);
    str = ");\npop(profiler_stack);\n"; 
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    return;
}

void printcounts(){
    char *str = "free(profiler_listnode_stack);\nstk *profiler_stack = malloc(sizeof(stk));\nprofiler_stack -> size = 10;\nprofiler_stack -> top = -1;\nprofiler_stack -> arr = (int*)malloc(sizeof(int)*profiler_stack-> size);\nstk *profiler_if_else_condition_stk = malloc(sizeof(stk));\nprofiler_if_else_condition_stk -> size = 10;\nprofiler_if_else_condition_stk -> top = -1;\nprofiler_if_else_condition_stk -> arr = (int*)malloc(sizeof(int)*profiler_stack-> size);\n";
    int len = strlen(str);
    fwrite(str,sizeof(char),len,fp);    
    str = "printf(";
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);    
    fwrite(&quotes,sizeof(char),1,fp);
    fwrite(&c,sizeof(char),1,fp);
    fwrite(&n,sizeof(char),1,fp);
    fwrite(&quotes,sizeof(char),1,fp);
    str = ");";
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);    
    for(int i = 0; i < given_func -> func_index; i++){
        char* tmp = malloc(10);
        sprintf(tmp,"%d",i);
        char *print_func_name = my_strcat(my_strcat(my_strcat(my_unique_variable,"["),tmp),"];\n");
        str = my_strcat(my_strcat(temporary_listhead," = "),print_func_name); 
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        function_count(given_func->array_func[i]);      
    }    
    str = "free(profiler_stack);\nfree(profiler_if_else_condition_stk);\n"; 
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    return ;
}

int write_func(Node *root){
    stk *st = malloc(sizeof(stk));
    st -> arr = (int*)malloc(sizeof(int)*st-> size);
    st -> size = 10;
    st -> top = -1;
    int i = 0,val = 0,tot_index = 0;
    char *str;
    int backward;
    int len = strlen(root -> value);
    fwrite(root -> value,sizeof(char),len,fp);
    if(strcmp(root -> value,"else")){
        len = strlen(root -> ptr[0] -> value);
        fwrite(root -> ptr[0]->value,sizeof(char),len,fp);
        i = 1;
    }
    str = "{\n";
    fwrite(str,sizeof(char),2,fp); 

    if(root -> type == LOOP)
        addcount();
    else if(root -> type == CONDITIONAL_STATEMENT){
        if_else_index++;
        str = my_strcat(my_strcat("listpush(profiler_listnode_stack,",temporary_listhead),");\n");
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        char* tmp = malloc(10);
        sprintf(tmp, "%d",if_else_index);
        str = my_strcat(my_strcat(my_strcat(my_strcat(temp_head_traverse,tmp),","),temporary_listhead),");\n");
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        addcount();
    }
    else{
        if(root -> type == START)
            alloc_all_lists();
        str = my_strcat(my_strcat("ListNode *",temporary_listhead),";\n");
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        str = my_strcat(temporary_listhead,my_strcat(" = ",curr_func_name)); 
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        addcount();
        str = "liststk *profiler_listnode_stack = malloc(sizeof(struct liststack));\nprofiler_listnode_stack -> size = 10;\nprofiler_listnode_stack -> top = -1;\nprofiler_listnode_stack -> arr = (ListNode**)malloc(sizeof(ListNode*)*profiler_listnode_stack-> size);\n";
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);    
    }
    for(int j = 0; j < root -> ptr[i] -> ptrsize;j++){
        if(root -> type == START && j == (root ->  ptr[i] -> ptrsize) -1){
            printcounts();
        }
        if(root -> ptr[i] -> ptr[j] -> type == STATEMENT){
            str = root -> ptr[i] -> ptr[j] -> value;
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);            
            addnewline();
        }
        else if(root -> ptr[i] -> ptr[j] -> type == FUNCTION ){
            str = my_strcat(root ->ptr[i] -> ptr[j] -> value,root -> ptr[i] -> ptr[j+1] -> value);
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
            j++;
            addnewline();
        }
        else if(root -> ptr[i] -> ptr[j] -> type == LOOP){
            if(st -> top == -1 && tot_index != 0){
                char* tmp = malloc(10);
                sprintf(tmp, "%d",tot_index+1);
                str = my_strcat(my_strcat(my_strcat(temp_head_traverse,tmp),","),my_strcat(my_strcat(temporary_listhead,");\nlistpush(profiler_listnode_stack,"),my_strcat(temporary_listhead,");\n")));
                len = strlen(str);
                fwrite(str,sizeof(char),len,fp);
                push(st,tot_index+1);
                val += tot_index;
                tot_index = 0;
            }
            else{
                str = my_strcat(temp_head_next,my_strcat(my_strcat("listpush(profiler_listnode_stack,",temporary_listhead),");\n"));
                len = strlen(str);
                fwrite(str,sizeof(char),len,fp);
                push(st,1);
            }
            tot_index++;
            tot_index += write_func(root -> ptr[i] -> ptr[j]);
            tot_index--;
            val++;
            pop(st);
        }
        else{
            if(flag != 1 && st -> top != -1)
                if_else_index = 0;
            else
                if_else_index = tot_index;
            flag = 1;
            tot_index++;
            tot_index += write_func(root -> ptr[i] -> ptr[j]);    
        }
        if( j+1 < root -> ptr[i] -> ptrsize){
        if(root->ptr[i]->ptr[j]->type==CONDITIONAL_STATEMENT && (!strcmp(root->ptr[i]->ptr[j+1]-> value,"if") || (root -> ptr[i]->ptr[j+1]->type != CONDITIONAL_STATEMENT))){
            char* tmp = malloc(10);
            sprintf(tmp, "%d",tot_index);
            str = my_strcat(my_strcat(my_strcat(my_strcat(temp_head_traverse,tmp),","),temporary_listhead),");\n");
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
            flag = 0;
            val += tot_index;
            tot_index = 0;
        }}
      }
    if(root -> type == CONDITIONAL_STATEMENT){
        str = my_strcat(temporary_listhead," = listpop(profiler_listnode_stack);\n}\n");
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
    }
    else if(root -> type == LOOP){
        str = my_strcat(temporary_listhead," = profiler_listnode_stack-> arr[profiler_listnode_stack -> top];\n}\nlistpop(profiler_listnode_stack);\n");
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        flag = 0;
    }
    else{
        str = "}\n";
        fwrite(str,sizeof(char),2,fp); 
    }
    return tot_index + val;
    free(st);
}
   
void code_generator(parseroutput* output){
    fp = fopen("my_code.c","w");
    given_func = output;
    my_unique_variable = output -> my_variable[0];
    temporary_listhead = output -> my_variable[1];
    temp_head_next = my_strcat(my_strcat(temporary_listhead," = "),my_strcat(temporary_listhead," -> next;\n"));
    temp_head_val = my_strcat(temporary_listhead," -> val");
    temp_head_val_plus = my_strcat(temporary_listhead," -> val++;\n");
    temp_head_traverse = my_strcat(temporary_listhead," = traversenext(");
    char *str = "#include";
    char quotes = (char)34;
    int len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    fwrite(&quotes,sizeof(char),1,fp);
    str = "new_code.h";
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    fwrite(&quotes,sizeof(char),1,fp);
    addnewline();
    for(int i = 0; i < output -> extra_size; i++){
        if(output -> extras[i].type == FUNCTION){
            str = my_strcat(output->extras[i].value,output->extras[i+1].value);
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
            i++;
        }
        else{
            len = strlen(output-> extras[i].value);
            fwrite(output->extras[i].value,sizeof(char),len,fp);
        }
        addnewline();
    }
    str = my_strcat(my_strcat( "ListNode** ",my_unique_variable),";\n");
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);

    for(int i = 0; i < output -> func_index; i++){
        char* tmp = malloc(10);
        sprintf(tmp,"%d",i);
        curr_func_name = my_strcat(my_strcat(my_strcat(my_unique_variable,"["),tmp),"];\n");
        write_func(output -> array_func[i]);
    }
    fclose(fp);
    return;
}
*/
