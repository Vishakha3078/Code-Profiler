#include"new_code.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
ListNode** j1EniQTv_r5J3qMC0BuhFist3C0BCEb;
void ps(char * s){
ListNode *D820LPMlJ52FZ042SEU3FHTuZ3DWRF2;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = j1EniQTv_r5J3qMC0BuhFist3C0BCEb[0];
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val++;
liststk *profiler_listnode_stack = malloc(sizeof(struct liststack));
profiler_listnode_stack -> size = 10;
profiler_listnode_stack -> top = -1;
profiler_listnode_stack -> arr = (ListNode**)malloc(sizeof(ListNode*)*profiler_listnode_stack-> size);
int i=0;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
listpush(profiler_listnode_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2);
while(1){
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val++;
if(s[i]=='\0'){
listpush(profiler_listnode_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = traversenext(1,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val++;
return ;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = listpop(profiler_listnode_stack);
}
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = traversenext(1,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2);
i++;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = profiler_listnode_stack-> arr[profiler_listnode_stack -> top];
}
listpop(profiler_listnode_stack);
}
void rotate(char* str, int n){
ListNode *D820LPMlJ52FZ042SEU3FHTuZ3DWRF2;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = j1EniQTv_r5J3qMC0BuhFist3C0BCEb[1];
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val++;
liststk *profiler_listnode_stack = malloc(sizeof(struct liststack));
profiler_listnode_stack -> size = 10;
profiler_listnode_stack -> top = -1;
profiler_listnode_stack -> arr = (ListNode**)malloc(sizeof(ListNode*)*profiler_listnode_stack-> size);
int i=0;
char tmp=str[0];
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
listpush(profiler_listnode_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2);
while(i<n-1){
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val++;
str[i]=str[i+1];
i++;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = profiler_listnode_stack-> arr[profiler_listnode_stack -> top];
}
listpop(profiler_listnode_stack);
str[n-2]=tmp;
}
int main(){
j1EniQTv_r5J3qMC0BuhFist3C0BCEb=malloc(sizeof(ListNode*)*3);
j1EniQTv_r5J3qMC0BuhFist3C0BCEb[0] = makelist(3);
j1EniQTv_r5J3qMC0BuhFist3C0BCEb[1] = makelist(2);
j1EniQTv_r5J3qMC0BuhFist3C0BCEb[2] = makelist(7);
ListNode *D820LPMlJ52FZ042SEU3FHTuZ3DWRF2;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = j1EniQTv_r5J3qMC0BuhFist3C0BCEb[2];
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val++;
liststk *profiler_listnode_stack = malloc(sizeof(struct liststack));
profiler_listnode_stack -> size = 10;
profiler_listnode_stack -> top = -1;
profiler_listnode_stack -> arr = (ListNode**)malloc(sizeof(ListNode*)*profiler_listnode_stack-> size);
char c[]="this is some text@";
int n=sizeof(c);
int i=0;
char str[n-1][n];
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
listpush(profiler_listnode_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2);
while(i<n-1){
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val++;
strcpy(str[i],c);
ps(str[i]);
rotate(c,n);
i++;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = profiler_listnode_stack-> arr[profiler_listnode_stack -> top];
}
listpop(profiler_listnode_stack);
char tmp[n];
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
listpush(profiler_listnode_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2);
while(i<=n){
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val++;
int j = i+1;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
listpush(profiler_listnode_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2);
while(j<=n){
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val++;
if(strcmp(str[i],str[j])>0){
listpush(profiler_listnode_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = traversenext(1,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val++;
strcpy(tmp,str[i]);
strcpy(str[i],str[j]);
strcpy(str[j],tmp);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = listpop(profiler_listnode_stack);
}
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = traversenext(1,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2);
j++;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = profiler_listnode_stack-> arr[profiler_listnode_stack -> top];
}
listpop(profiler_listnode_stack);
i++;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = profiler_listnode_stack-> arr[profiler_listnode_stack -> top];
}
listpop(profiler_listnode_stack);
i=0;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = traversenext(3,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2);
listpush(profiler_listnode_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2);
while(i<n){
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val++;
ps(str[i]);
i++;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = profiler_listnode_stack-> arr[profiler_listnode_stack -> top];
}
listpop(profiler_listnode_stack);
i=0;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
listpush(profiler_listnode_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2);
while(i<n){
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val++;
i++;
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = profiler_listnode_stack-> arr[profiler_listnode_stack -> top];
}
listpop(profiler_listnode_stack);
free(profiler_listnode_stack);
stk *profiler_stack = malloc(sizeof(stk));
profiler_stack -> size = 10;
profiler_stack -> top = -1;
profiler_stack -> arr = (int*)malloc(sizeof(int)*profiler_stack-> size);
stk *profiler_if_else_condition_stk = malloc(sizeof(stk));
profiler_if_else_condition_stk -> size = 10;
profiler_if_else_condition_stk -> top = -1;
profiler_if_else_condition_stk -> arr = (int*)malloc(sizeof(int)*profiler_stack-> size);
printf("\n");D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = j1EniQTv_r5J3qMC0BuhFist3C0BCEb[0];
printf("           [0;33m%7d[0m    |[0;31m    void ps(char * s)[0m{\n",D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
push(profiler_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
printf("           [0;33m%7d[0m    |        int i=0;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |[0;34m        while(1)[0m{\n",profiler_stack -> arr[profiler_stack -> top] +D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next -> val);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
push(profiler_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
push(profiler_if_else_condition_stk,profiler_stack -> arr[profiler_stack ->  top]);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
;
printf("           [0;33m%7d[0m    |[0;34m            if(s[i]=='\\0')[0m{\n",profiler_if_else_condition_stk -> arr[profiler_if_else_condition_stk -> top]);
push(profiler_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
printf("           [0;33m%7d[0m    |                return ;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |            }\n");
pop(profiler_stack);
pop(profiler_if_else_condition_stk);
printf("           [0;33m%7d[0m    |            i++;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |        }\n");
pop(profiler_stack);
printf("                      |    }\n");
pop(profiler_stack);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = j1EniQTv_r5J3qMC0BuhFist3C0BCEb[1];
printf("           [0;33m%7d[0m    |[0;31m    void rotate(char* str, int n)[0m{\n",D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
push(profiler_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
printf("           [0;33m%7d[0m    |        int i=0;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |        char tmp=str[0];\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |[0;34m        while(i<n-1)[0m{\n",profiler_stack -> arr[profiler_stack -> top] +D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next -> val);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
push(profiler_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
printf("           [0;33m%7d[0m    |            str[i]=str[i+1];\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |            i++;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |        }\n");
pop(profiler_stack);
printf("           [0;33m%7d[0m    |        str[n-2]=tmp;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |    }\n");
pop(profiler_stack);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = j1EniQTv_r5J3qMC0BuhFist3C0BCEb[2];
printf("           [0;33m%7d[0m    |[0;31m    int main()[0m{\n",D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
push(profiler_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
printf("           [0;33m%7d[0m    |        char c[]=\"this is some text@\";\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |        int n=sizeof(c);\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |        int i=0;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |        char str[n-1][n];\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |[0;34m        while(i<n-1)[0m{\n",profiler_stack -> arr[profiler_stack -> top] +D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next -> val);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
push(profiler_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
printf("           [0;33m%7d[0m    |            strcpy(str[i],c);\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |            ps(str[i]);\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |            rotate(c,n);\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |            i++;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |        }\n");
pop(profiler_stack);
printf("           [0;33m%7d[0m    |        char tmp[n];\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |[0;34m        while(i<=n)[0m{\n",profiler_stack -> arr[profiler_stack -> top] +D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next -> val);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
push(profiler_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
printf("           [0;33m%7d[0m    |            int j = i+1;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |[0;34m            while(j<=n)[0m{\n",profiler_stack -> arr[profiler_stack -> top] +D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next -> val);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
push(profiler_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
push(profiler_if_else_condition_stk,profiler_stack -> arr[profiler_stack ->  top]);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
;
printf("           [0;33m%7d[0m    |[0;34m                if(strcmp(str[i],str[j])>0)[0m{\n",profiler_if_else_condition_stk -> arr[profiler_if_else_condition_stk -> top]);
push(profiler_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
printf("           [0;33m%7d[0m    |                    strcpy(tmp,str[i]);\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |                    strcpy(str[i],str[j]);\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |                    strcpy(str[j],tmp);\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |                }\n");
pop(profiler_stack);
pop(profiler_if_else_condition_stk);
printf("           [0;33m%7d[0m    |                j++;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |            }\n");
pop(profiler_stack);
printf("           [0;33m%7d[0m    |            i++;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |        }\n");
pop(profiler_stack);
printf("           [0;33m%7d[0m    |        i=0;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |[0;34m        while(i<n)[0m{\n",profiler_stack -> arr[profiler_stack -> top] +D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next -> val);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
push(profiler_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
printf("           [0;33m%7d[0m    |            ps(str[i]);\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |            i++;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |        }\n");
pop(profiler_stack);
printf("           [0;33m%7d[0m    |        i=0;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |[0;34m        while(i<n)[0m{\n",profiler_stack -> arr[profiler_stack -> top] +D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next -> val);
D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 = D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> next;
push(profiler_stack,D820LPMlJ52FZ042SEU3FHTuZ3DWRF2 -> val);
printf("           [0;33m%7d[0m    |            i++;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |        }\n");
pop(profiler_stack);
printf("           [0;33m%7d[0m    |        return 0;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |    }\n");
pop(profiler_stack);
free(profiler_stack);
free(profiler_if_else_condition_stk);
return 0;
}
