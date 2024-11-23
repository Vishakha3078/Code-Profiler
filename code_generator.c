#include"prof.h"

char* curr_func_name;
parseroutput *given_func;

ListNode* makeNode(){
    ListNode* nd = (ListNode*)malloc(sizeof(ListNode));
    nd -> next = NULL;
    nd -> val = 0;
    return nd;
}

ListNode* makeNext(ListNode* node){
    ListNode* nd = (ListNode*)malloc(sizeof(ListNode));
    nd -> next = NULL;
    nd -> val = 0;
    node -> next = nd;
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

void write_func(Node *root){
    int i = 0;
    char *str;
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
        str = "temporary_listhead = temporary_listhead -> next;\n";
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
        str = "stk *st = malloc(sizeof(stk));\nst -> size = 10;\nst -> top = -1;\nst -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);\n";
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);    
    }
       
    for(int j = 0; j < root -> ptr[i] -> ptrsize;j++){
        if(root -> type == START && j == (root ->  ptr[i] -> ptrsize) -1)
            printcounts(given_func);
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
            str ="temporary_listhead = temporary_listhead -> next;\npush(st,temporary_listhead);\n";
            len = strlen(str);
            fwrite(str,sizeof(char),len,fp);
            write_func(root -> ptr[i] -> ptr[j]);    
        }
        else{
            write_func(root -> ptr[i] -> ptr[j]);    
        }
    }
    
    if(root -> type == LOOP)
        str = "temporary_listhead = st-> arr[st -> top];\n}\npop(st);\n";
    else 
        str = "}\n";
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
}
   
void code_generator(parseroutput* output){
    fp = fopen("my_code.c","w");
    given_func = output;
    char *str = "#include<prof.h>\n";
    int len = strlen(str);
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

