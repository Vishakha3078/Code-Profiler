#include"prof.h"

FILE *fp;
char* curr_func_name;
char* print_func_name;
int if_else_index = 0;
int len;
bool flag = 0;
parseroutput *given_func;

ListNode* makeNode(){
    ListNode* nd = (ListNode*)malloc(sizeof(ListNode));
    nd -> left = NULL;
    nd -> right = NULL;
    nd -> val = 0;
    return nd;
}

ListNode* makeNext(ListNode* node){
    ListNode* nd = (ListNode*)malloc(sizeof(ListNode));
    nd -> left = node;
    nd -> right = NULL;
    nd -> val = 0;
    node -> right = nd;
    return nd;
}

ListNode* makelist(int n){ 
    ListNode* head = makeNode();
    ListNode* temp = head;
    while( n > 1){
        temp = makeNext(temp);
        n--;
    }
    return head;
}

ListNode* traverseprev(int num,ListNode* nd){
    while(num > 0){
        nd = nd -> left;
        num--;
    }
    return nd;
}

ListNode* traversenext(int num,ListNode* nd){
    while(num > 0){
        nd = nd -> right;
        num--;
    }
    return nd;
} 

char* my_strcat(char* s1,char* s2){
    int n = strlen(s1);
    int m = strlen(s2);
    char* out = malloc(sizeof(char)*n+m);
    strcpy(out,s1);
    strcpy(out+n,s2);
    return out;
}

char* remove_return_type(char *s){
    int len = strlen(s);
    int i = len - 1;
    int j = 0;
    while(*(s+i) != ' '){
        i--;
        j++;
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
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    return;    
}

void alloc_all_lists(){
    for(int i= 0; i < given_func -> func_index; i++){
        char *str = give_alloc(remove_return_type(given_func->array_func[i]->value),givecount(given_func->array_func[i]));
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
    }
    return;
}

void function_count(Node *root){
    char *tabs = "    ";
    char c = (char)92;
    char n = 'n';
    char quotes = (char)34;
    char *str;
    int j = 1;
    str = "printf(";
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);    
    fwrite(&quotes,sizeof(char),1,fp);
    if(strcmp(root -> value,"else")){
        str =my_strcat(tabs,my_strcat(my_strcat(root -> value ,root -> ptr[0] -> value),"{")); 
    }
    else{
        str =my_strcat(tabs,my_strcat(root -> value ,"{"));
        j =0;
    }
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    if(root -> type == START || root -> type == FUNCTION){
        fwrite(&c,sizeof(char),1,fp);
        fwrite(&n,sizeof(char),1,fp);
        str = ");\n"; 
    }
    else{
        str = " -> %d";
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        fwrite(&c,sizeof(char),1,fp);
        fwrite(&n,sizeof(char),1,fp);
        fwrite(&quotes,sizeof(char),1,fp);
        str = ",temporary_listhead->val + 1);\n";
    }
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    str = "push(s,temporary_listhead->val);\n"; 
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
      
    for(int i = 0; i < root -> ptr[j] -> ptrsize; i++){
    printf("%s\n",root->ptr[j]->ptr[i]->value);
        if(root->ptr[j]->ptr[i]->type == STATEMENT || root->ptr[j]->ptr[i]->type == FUNCTION){
            str = "printf(";
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);    
            fwrite(&quotes,sizeof(char),1,fp);
            
            if(root->ptr[j]->ptr[i]->type == FUNCTION){
                str = my_strcat(my_strcat(my_strcat(tabs,root -> ptr[j]-> ptr[i] -> value),root -> ptr[j]->ptr[i+1]->value)," -> %d"); 
                i++;
            }
            else
                str = my_strcat(my_strcat(tabs,root -> ptr[j]-> ptr[i] -> value)," -> %d"); 
            
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
            fwrite(&c,sizeof(char),1,fp);
            fwrite(&n,sizeof(char),1,fp);
            fwrite(&quotes,sizeof(char),1,fp);
            str = ",s ->arr[s->top]);\n";
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
        }
       else {
            str = "temporary_listhead = temporary_listhead->right;\n"; 
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
            function_count(root ->ptr[j] -> ptr[i]);
        }
    }
    str = "printf(";
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);    
    fwrite(&quotes,sizeof(char),1,fp);
    str = my_strcat(tabs,"}");
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    fwrite(&c,sizeof(char),1,fp);
    fwrite(&n,sizeof(char),1,fp);
    fwrite(&quotes,sizeof(char),1,fp);
    str =");\n";
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    str = "pop(s);\n"; 
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    return;
}

void printcounts(){
    char *str = "stk *s = malloc(sizeof(stk));\ns -> arr = (int*)malloc(sizeof(int)*s-> size);\ns -> size = 10;\ns -> top = -1;\n";
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);    
    for(int i = 0; i < given_func -> func_index; i++){
        print_func_name = my_strcat(remove_return_type(given_func->array_func[i]->value),"_cnt");
        str = my_strcat(my_strcat("temporary_listhead = ",print_func_name),";\n"); 
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        function_count(given_func->array_func[i]);      
    }    
    str = "free(s);\n"; 
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
    char *str;
    int backward;
    int tot_index = 0;
    len = strlen(root -> value);
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
        backward = if_else_index;
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
        str = my_strcat(my_strcat("temporary_listhead = ",curr_func_name),";\n"); 
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        addcount();
    }
    
    for(int j = 0; j < root -> ptr[i] -> ptrsize;j++){
        if(root -> type == START && j == (root ->  ptr[i] -> ptrsize) -1)
            printcounts();
        if(root -> ptr[i] -> ptr[j] -> type != CONDITIONAL_STATEMENT)
            flag = 0;
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
                str = my_strcat(my_strcat("temporary_listhead = traversenext(",tmp),",temporary_listhead);\n");
                len = strlen(str);
                fwrite(str,sizeof(char),len,fp);
                push(st,tot_index+1);
            }
            else{
                str = "temporary_listhead = temporary_listhead -> right;\n";
                len = strlen(str);
                fwrite(str,sizeof(char),len,fp);
                push(st,1);
            }
            tot_index++;
            tot_index += write_func(root -> ptr[i] -> ptr[j]);
            int val = pop(st);
            if(val == 1){
                str = "temporary_listhead = temporary_listhead -> left;\n";
                len = strlen(str);
                fwrite(str,sizeof(char),len,fp);
            }
            else{
                char* tmp = malloc(10);
                sprintf(tmp, "%d",val);
                str = my_strcat(my_strcat("temporary_listhead = traverseprev(",tmp),",temporary_listhead);\n");
                len = strlen(str);
                fwrite(str,sizeof(char),len,fp);
            }
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
    }
    if(root -> type == CONDITIONAL_STATEMENT){
        char *tmp = malloc(10);
        sprintf(tmp, "%d",backward);
        str = my_strcat(my_strcat("temporary_listhead = traverseprev(",tmp),",temporary_listhead);\n");
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
    }
    str = "}\n";
    fwrite(str,sizeof(char),2,fp); 
    return tot_index;
    free(st);
}
    
void code_generator(parseroutput* output){
    fp = fopen("my_code.c","w");
    given_func = output;
    char *str = "#include<prof.h>\n";
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
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
    str = "ListNode *temporary_listhead;\n";
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
       
    for(int i = 0; i < output -> func_index; i++){
        curr_func_name = my_strcat(remove_return_type(output -> array_func[i] -> value),"_cnt");
        write_func(output -> array_func[i]);
    }
    fclose(fp);
    return;
}

