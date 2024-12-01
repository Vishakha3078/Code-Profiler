#include"prof.h"

FILE *fp;
char* curr_func_name;
parseroutput *given_func;
int if_else_index = 0;
bool flag = 0;
stk *while_count_stk;
char *tabs = "    ";

char* my_strcat(char* s1,char* s2){
    int n = strlen(s1);
    int m = strlen(s2);
    char* out = malloc(sizeof(char)*n+m);
    strcpy(out,s1);
    strcpy(out+n,s2);
    return out;
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
    char* buf = ");\n";
    char* cnt = my_strcat(a,my_strcat(my_strcat("_cnt = makelist(",tmp),buf));
    return cnt;
}

void addnewline(){
    char *newline = "\n";
    fwrite(newline,sizeof(char),1,fp); 
    return;
}

void addcount(){
    char *str = "temporary_listhead -> val++;\n";
    int len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    return;    
}

void alloc_all_lists(){
    for(int i= 0; i < given_func -> func_index; i++){
        char *str = give_alloc(remove_return_type(given_func->array_func[i]->value),givecount(given_func->array_func[i]));
        int len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
    }
    return;
}

void function_count(Node *root){
    char c = (char)92;
    char n = 'n';
    char quotes = (char)34;
    char *str;
    int j = 1;
    str = "printf(";
    int len = strlen(str);
    fwrite(str,sizeof(char),len,fp);    
    fwrite(&quotes,sizeof(char),1,fp);

    if(!strcmp(root -> value,"else")){
        str = my_strcat("    %7d    ->    ",my_strcat(tabs,root -> value));
        j =0;
    }
    else
        str =my_strcat("    %7d    ->    ",my_strcat(tabs,my_strcat(my_strcat(root -> value ,root->ptr[0]->value),"{")));
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    fwrite(&c,sizeof(char),1,fp);
    fwrite(&n,sizeof(char),1,fp);
    fwrite(&quotes,sizeof(char),1,fp);
    if(root -> type == START || root -> type == FUNCTION || !strcmp(root ->value,"else"))
        str = ",temporary_listhead -> val);\n"; 
    else if(root -> type == CONDITIONAL_STATEMENT)
        str = ",if_else_condition_stk -> arr[if_else_condition_stk -> top]);\n";
    else{
        if(while_count_stk -> top != -1)
            str = ",s -> arr[s -> top] + temporary_listhead -> next -> val);\ntemporary_listhead = temporary_listhead->next;\n"; 
        else 
            str = ",temporary_listhead -> next -> val + 1);\ntemporary_listhead = temporary_listhead->next;\n";
       push(while_count_stk,1);   
    }
    
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    str = "push(s,temporary_listhead->val);\n"; 
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
                str = my_strcat("    %7d    ->    ",my_strcat(my_strcat(tabs,root -> ptr[j]-> ptr[i] -> value),root -> ptr[j]->ptr[i+1]->value)); 
                i++;
            }
            else
                str = my_strcat("    %7d    ->    ",my_strcat(tabs,root->ptr[j]->ptr[i]->value)); 
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
            fwrite(&c,sizeof(char),1,fp);
            fwrite(&n,sizeof(char),1,fp);
            fwrite(&quotes,sizeof(char),1,fp);
            str = ",s ->arr[s->top]);\n";
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
        }
        else if(root->ptr[j]->ptr[i]->type == LOOP){
           function_count(root ->ptr[j] -> ptr[i]);
        }
        else{
            push(while_count_stk,1);
            if(!strcmp(root->ptr[j]->ptr[i]->value,"if") && (root -> type == LOOP || root -> type == CONDITIONAL_STATEMENT))
                str = "push(if_else_condition_stk,temporary_listhead -> val);\ntemporary_listhead = temporary_listhead->next;\n";
            else if(!strcmp(root->ptr[j]->ptr[i]->value,"if"))
                str = "push(if_else_condition_stk,1);\ntemporary_listhead = temporary_listhead->next;\n";
            else if(!strcmp(root->ptr[j]->ptr[i]->value,"else if"))
                str = "push(if_else_condition_stk,pop(if_else_condition_stk) - (temporary_listhead->val));\ntemporary_listhead = temporary_listhead -> next;\n";
            else
                str = "temporary_listhead = temporary_listhead -> next;\n";
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
            function_count(root -> ptr[j] -> ptr[i]);
            if(strcmp(root->ptr[j]->ptr[i+1]->value,"else if")){
                str = "pop(if_else_condition_stk);\n";
                len = strlen(str);
                fwrite(str,sizeof(char),len,fp);
            }
        }
    }
    tabs = decrease_space(tabs);
    str = "printf(";
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);    
    fwrite(&quotes,sizeof(char),1,fp);
    str = my_strcat(tabs,"                     }");
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    fwrite(&c,sizeof(char),1,fp);
    fwrite(&n,sizeof(char),1,fp);
    fwrite(&quotes,sizeof(char),1,fp);
    str = ");\npop(s);\n"; 
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    if(root -> type == LOOP || root -> type == CONDITIONAL_STATEMENT)
        pop(while_count_stk);
    return;
}

void printcounts(){
    char *str = "stk *s = malloc(sizeof(stk));\ns -> size = 10;\ns -> top = -1;\ns -> arr = (int*)malloc(sizeof(int)*s-> size);\nstk *if_else_condition_stk = malloc(sizeof(stk));\nif_else_condition_stk -> size = 10;\nif_else_condition_stk -> top = -1;\nif_else_condition_stk -> arr = (int*)malloc(sizeof(int)*s-> size);\n";
    int len = strlen(str);
    fwrite(str,sizeof(char),len,fp);    
    for(int i = 0; i < given_func -> func_index; i++){
        char *print_func_name = my_strcat(remove_return_type(given_func->array_func[i]->value),"_cnt");
        str = my_strcat(my_strcat("temporary_listhead = ",print_func_name),";\n"); 
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        function_count(given_func->array_func[i]);      
    }    
    str = "free(s);\nfree(st);\nfree(if_else_condition_stk);\n"; 
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    return ;
}

int write_func(Node *root){
    stk *st = malloc(sizeof(stk));
    st -> arr = (int*)malloc(sizeof(int)*st-> size);
    st -> size = 10;
    st -> top = -1;
    int i = 0;
    int val = 0;
    char *str;
    int backward;
    int tot_index = 0;
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
        str = "listpush(st,temporary_listhead);\n";
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        char* tmp = malloc(10);
        sprintf(tmp, "%d",if_else_index);
        str = my_strcat(my_strcat("temporary_listhead = traversenext(",tmp),",temporary_listhead);\n");
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        addcount();
    }
    else{
        if(root -> type == START)
            alloc_all_lists();
        str = "ListNode *temporary_listhead;\n";
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        str = my_strcat(my_strcat("temporary_listhead = ",curr_func_name),";\n"); 
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        addcount();
        str = "liststk *st = malloc(sizeof(struct liststack));\nst -> size = 10;\nst -> top = -1;\nst -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);\n";
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);    
 }
    
    for(int j = 0; j < root -> ptr[i] -> ptrsize;j++){
        if(root -> type == START && j == (root ->  ptr[i] -> ptrsize) -1)
            printcounts();
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
                str = my_strcat(my_strcat("temporary_listhead = traversenext(",tmp),",temporary_listhead);\nlistpush(st,temporary_listhead);\n");
                len = strlen(str);
                fwrite(str,sizeof(char),len,fp);
                push(st,tot_index+1);
            }
            else{
                str = "temporary_listhead = temporary_listhead -> next;\nlistpush(st,temporary_listhead);\n";
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
        if(root->ptr[i]->ptr[j]->type==CONDITIONAL_STATEMENT && (!strcmp(root->ptr[i]->ptr[j+1]-> value,"if") || (root -> ptr[i]->ptr[j+1]->type != CONDITIONAL_STATEMENT))){
            char* tmp = malloc(10);
            sprintf(tmp, "%d",tot_index);
            str = my_strcat(my_strcat("temporary_listhead = traversenext(",tmp),",temporary_listhead);\n");
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
            flag = 0;
            val += tot_index;
            tot_index = 0;
        }
      }
    if(root -> type == CONDITIONAL_STATEMENT){
          str = "temporary_listhead = listpop(st);\n}\n";
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
    }
    else if(root -> type == LOOP){
        str = "temporary_listhead = st-> arr[st -> top];\n}\nlistpop(st);\n";
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
    while_count_stk = malloc(sizeof(stk));
    while_count_stk -> size = 10;
    while_count_stk -> top = -1;
    while_count_stk -> arr = (int*)malloc(sizeof(int));

    given_func = output;
    char *str = "#include";
    char quotes = (char)34;
    int len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    fwrite(&quotes,sizeof(char),1,fp);
    str = "prof.h";
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

    for(int i = 0; i < output -> func_index ;i++){
        str = give_declaration(remove_return_type(output -> array_func[i]-> value));
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
    }
      
    for(int i = 0; i < output -> func_index; i++){
        curr_func_name = my_strcat(remove_return_type(output -> array_func[i] -> value),"_cnt");
        write_func(output -> array_func[i]);
    }
    fclose(fp);
    return;
}

