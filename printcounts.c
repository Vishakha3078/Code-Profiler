#include"prof.h"

char *print_func_name;

void function_count(Node *root){
    char *tabs = "    ";
    char c = (char)92;
    char n = 'n';
    char quotes = (char)34;
    char *str;
    int j = 1;
    str = "printf(";
    int len = strlen(str);
    fwrite(str,sizeof(char),len,fp);    
    fwrite(&quotes,sizeof(char),1,fp);
    if(strcmp(root -> value,"else"))
        str =my_strcat(tabs,my_strcat(my_strcat(root -> value ,root->ptr[0]->value),"{ -> %d"));
    else{
        str =my_strcat(tabs,my_strcat(root -> value ,"{ -> %d"));
        j =0;
    }
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    fwrite(&c,sizeof(char),1,fp);
    fwrite(&n,sizeof(char),1,fp);
    fwrite(&quotes,sizeof(char),1,fp);
    if(root -> type == START || root -> type == FUNCTION)
       str = ",temporary_listhead -> val);\n"; 
    else
        str = ",temporary_listhead -> val + 1);\n";
    
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
            str = "temporary_listhead = temporary_listhead->next;\n"; 
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

void printcounts(parseroutput *given_func){
    char *str = "stk *s = malloc(sizeof(stk));\ns -> size = 10;\ns -> top = -1;\ns -> arr = (int*)malloc(sizeof(int)*s-> size);\n";
    int len = strlen(str);
    fwrite(str,sizeof(char),len,fp);    
    for(int i = 0; i < given_func -> func_index; i++){
        print_func_name = my_strcat(remove_return_type(given_func->array_func[i]->value),"_cnt");
        str = my_strcat(my_strcat("temporary_listhead = ",print_func_name),";\n"); 
        len = strlen(str);
        fwrite(str,sizeof(char),len,fp);
        function_count(given_func->array_func[i]);      
    }    
    str = "free(s);\nfree(st);\n"; 
    len = strlen(str);
    fwrite(str,sizeof(char),len,fp);
    return ;
}


