#include"prof.h"

FILE *fp;
char* curr_func_name;
int if_else_index = 0;
int len;
bool flag = 0;
parseroutput *given_func;

typedef struct stack{
    int size;
    int top;
    int *arr;
}stk;

int pop(stk *st){
    st -> top = (st -> top) - 1;
    return st -> arr[(st -> top) + 1];
}

void push(stk *st,int val){
    if((st -> top)+1 == st -> size){
        st -> size = (st -> size) + 10;
        st = realloc(st, sizeof(int)*st ->size);
    }
    st -> top = st -> top + 1;
    st -> arr[st -> top] = val;
    return;
}

typedef struct ListNode{
    struct ListNode *left;
    struct ListNode *right;
    unsigned int val;
}ListNode;

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

void startbrac(){
    char *brac = "{\n";
    fwrite(brac,sizeof(char),2,fp); 
    return;
}

void endbrac(){
    char *brac = "}\n";
    fwrite(brac,sizeof(char),2,fp); 
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
        char *str = give_alloc(given_func -> array_func[i] ->value,givecount(given_func->array_func[i]));
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
    }
    return;
}

void write_func(Node *root){
    printf("i am in func\n");
    stk *st;
    st -> size = 10;
    st -> top = -1;
    st -> arr = (int*)malloc(sizeof(int)*st-> size);
    int i = 0;
    char *str;
    int backward;
    int tot_index = 0;
    len = strlen(root -> value);
    fwrite(root ->value,sizeof(char),len,fp);
    if(root -> value != "else"){
        len = strlen(root -> ptr[0] -> value);
        fwrite(root -> ptr[0]->value,sizeof(char),len,fp);
        i = 1;
    }
    startbrac();

    if(root -> type == LOOP){
        addcount();
    }
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
     printf("%s\n",root->ptr[i]->ptr[j]->value); 
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
                printf("i am here\n");
                str = "temporary_listhead = temporary_listhead -> right;\n";
                len = strlen(str);
                fwrite(str,sizeof(char),len,fp);
                push(st,1);
            }
            tot_index++;
            write_func(root -> ptr[i] -> ptr[j]);
    printf("i am here\n");
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
            else{
                if_else_index = tot_index;
            }
            flag = 1;
            tot_index++;
            write_func(root -> ptr[i] -> ptr[j]);    
        }
    }
    if(root -> type == CONDITIONAL_STATEMENT){
        char *tmp = malloc(10);
        sprintf(tmp, "%d",backward);
        str = my_strcat(my_strcat("temporary_listhead = traverseprev(",tmp),",temporary_listhead);\n");
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        addcount();    
    }
    endbrac();
}
    
void code_generator(parseroutput* output){
    fp = fopen("my_code.c","w");
    given_func = output;
    char *str = "#include<prof.h>\n";
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    for(int i = 0; i < output -> extra_size; i++){
        len = strlen(output-> extras[i].value);
        fwrite(output->extras[i].value,sizeof(char),len,fp);
        addnewline();
    }

    for(int i = 0; i < output -> func_index ;i++){
        str = give_declaration(output -> array_func[i]-> value);
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
    }
    str = "ListNode *temporary_listhead;\n";
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
       
    for(int i = 0; i < output -> func_index; i++){
        curr_func_name = my_strcat(output -> array_func[i] -> value,"_cnt");
    printf("%s\n",curr_func_name);
        write_func(output -> array_func[i]);
    }    
    printf("in here\n");
    return;
}
