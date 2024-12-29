#include"prof.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
ListNode* pmat_cnt;
ListNode* issafe_cnt;
ListNode* nqueen_helper_cnt;
ListNode* nqueen_cnt;
ListNode* main_cnt;
void pmat(int **mat ,int n){
int My_Tot_Count = 0;
ListNode *temporary_listhead;
temporary_listhead = pmat_cnt;
temporary_listhead -> val++;
liststk *st = malloc(sizeof(struct liststack));
st -> size = 10;
st -> top = -1;
st -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);
int i=0;
int j=0;
temporary_listhead = temporary_listhead -> next;
listpush(st,temporary_listhead);
while(i<n){
temporary_listhead -> val++;
j=0;
temporary_listhead = temporary_listhead -> next;
listpush(st,temporary_listhead);
while(j<n){
temporary_listhead -> val++;
printf("%d ",mat[i][j]);
j++;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
printf("\n");
i++;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
}
bool issafe(int** board,int n,int x,int y,int cnt){
int My_Tot_Count = 0;
ListNode *temporary_listhead;
temporary_listhead = issafe_cnt;
temporary_listhead -> val++;
liststk *st = malloc(sizeof(struct liststack));
st -> size = 10;
st -> top = -1;
st -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);
int i=x;
int j=y;
cnt++;
temporary_listhead = temporary_listhead -> next;
listpush(st,temporary_listhead);
while(i>=0){
temporary_listhead -> val++;
if(board[i][j]==1){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(1,temporary_listhead);
temporary_listhead -> val++;
return false;
temporary_listhead = listpop(st);
}
temporary_listhead = traversenext(1,temporary_listhead);
i--;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
i=x;
temporary_listhead = traversenext(2,temporary_listhead);
listpush(st,temporary_listhead);
while(j>=0){
temporary_listhead -> val++;
if(board[i][j]==1){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(1,temporary_listhead);
temporary_listhead -> val++;
return false;
temporary_listhead = listpop(st);
}
temporary_listhead = traversenext(1,temporary_listhead);
j--;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
j=y;
temporary_listhead = traversenext(2,temporary_listhead);
listpush(st,temporary_listhead);
while(i>=0 && j>=0){
temporary_listhead -> val++;
if(board[i][j]==1){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(1,temporary_listhead);
temporary_listhead -> val++;
return false;
temporary_listhead = listpop(st);
}
temporary_listhead = traversenext(1,temporary_listhead);
i--;
j--;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
i=x;
j=y;
temporary_listhead = traversenext(2,temporary_listhead);
listpush(st,temporary_listhead);
while(i>=0 && j<n){
temporary_listhead -> val++;
if(board[i][j]==1){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(1,temporary_listhead);
temporary_listhead -> val++;
return false;
temporary_listhead = listpop(st);
}
temporary_listhead = traversenext(1,temporary_listhead);
i--;
j++;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
return true;
}
void nqueen_helper(int **board,int n, int i,int toput,int sol){
int My_Tot_Count = 0;
ListNode *temporary_listhead;
temporary_listhead = nqueen_helper_cnt;
temporary_listhead -> val++;
liststk *st = malloc(sizeof(struct liststack));
st -> size = 10;
st -> top = -1;
st -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);
if(toput == 0){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(1,temporary_listhead);
temporary_listhead -> val++;
pmat(board,n);
sol++;
return ;
temporary_listhead = listpop(st);
}
temporary_listhead = traversenext(1,temporary_listhead);
if(i==n){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(1,temporary_listhead);
temporary_listhead -> val++;
return;
temporary_listhead = listpop(st);
}
temporary_listhead = traversenext(1,temporary_listhead);
int j=0;
temporary_listhead = temporary_listhead -> next;
listpush(st,temporary_listhead);
while(j<n){
temporary_listhead -> val++;
if(issafe(board,n,i,j,0)){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(1,temporary_listhead);
temporary_listhead -> val++;
board[i][j]=1;
nqueen_helper(board,n,i+1,toput-1,sol);
board[i][j]=0;
temporary_listhead = listpop(st);
}
temporary_listhead = traversenext(1,temporary_listhead);
j++;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
return ;
}
void nqueen(int n){
int My_Tot_Count = 0;
ListNode *temporary_listhead;
temporary_listhead = nqueen_cnt;
temporary_listhead -> val++;
liststk *st = malloc(sizeof(struct liststack));
st -> size = 10;
st -> top = -1;
st -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);
int **board = malloc(sizeof(int*)*n);
int i = 0;
temporary_listhead = temporary_listhead -> next;
listpush(st,temporary_listhead);
while(i<n){
temporary_listhead -> val++;
board[i]=malloc(sizeof(int)*n);
i++;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
nqueen_helper(board,n,0,n,0);
}
int main(){
pmat_cnt = makelist(3);
issafe_cnt = makelist(9);
nqueen_helper_cnt = makelist(5);
nqueen_cnt = makelist(2);
main_cnt = makelist(1);
int My_Tot_Count = 0;
ListNode *temporary_listhead;
temporary_listhead = main_cnt;
temporary_listhead -> val++;
liststk *st = malloc(sizeof(struct liststack));
st -> size = 10;
st -> top = -1;
st -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);
int n = 5;
nqueen(n);
stk *s = malloc(sizeof(stk));
s -> size = 10;
s -> top = -1;
s -> arr = (int*)malloc(sizeof(int)*s-> size);
stk *if_else_condition_stk = malloc(sizeof(stk));
if_else_condition_stk -> size = 10;
if_else_condition_stk -> top = -1;
if_else_condition_stk -> arr = (int*)malloc(sizeof(int)*s-> size);
printf("\n");temporary_listhead = pmat_cnt;
printf("           [0;33m%7d[0m    |[0;31m    void pmat(int **mat ,int n)[0m{\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |        int i=0;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |        int j=0;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |[0;34m        while(i<n)[0m{\n",s -> arr[s -> top] + temporary_listhead -> next -> val);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |            j=0;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |[0;34m            while(j<n)[0m{\n",s -> arr[s -> top] + temporary_listhead -> next -> val);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |                printf(\"%%d \",mat[i][j]);\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |                j++;\n",s ->arr[s->top]);
printf("                      |            }\n");
pop(s);
printf("           [0;33m%7d[0m    |            printf(\"\\n\");\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |            i++;\n",s ->arr[s->top]);
printf("                      |        }\n");
pop(s);
printf("                      |    }\n");
pop(s);
temporary_listhead = issafe_cnt;
printf("           [0;33m%7d[0m    |[0;31m    bool issafe(int** board,int n,int x,int y,int cnt)[0m{\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |        int i=x;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |        int j=y;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |        cnt++;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |[0;34m        while(i>=0)[0m{\n",s -> arr[s -> top] + temporary_listhead -> next -> val);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
push(if_else_condition_stk,s -> arr[s ->  top]);
temporary_listhead = temporary_listhead->next;
printf("           [0;33m%7d[0m    |[0;34m            if(board[i][j]==1)[0m{\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |                return false;\n",s ->arr[s->top]);
printf("                      |            }\n");
pop(s);
pop(if_else_condition_stk);
printf("           [0;33m%7d[0m    |            i--;\n",s ->arr[s->top]);
printf("                      |        }\n");
pop(s);
printf("           [0;33m%7d[0m    |        i=x;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |[0;34m        while(j>=0)[0m{\n",s -> arr[s -> top] + temporary_listhead -> next -> val);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
push(if_else_condition_stk,s -> arr[s ->  top]);
temporary_listhead = temporary_listhead->next;
printf("           [0;33m%7d[0m    |[0;34m            if(board[i][j]==1)[0m{\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |                return false;\n",s ->arr[s->top]);
printf("                      |            }\n");
pop(s);
pop(if_else_condition_stk);
printf("           [0;33m%7d[0m    |            j--;\n",s ->arr[s->top]);
printf("                      |        }\n");
pop(s);
printf("           [0;33m%7d[0m    |        j=y;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |[0;34m        while(i>=0 && j>=0)[0m{\n",s -> arr[s -> top] + temporary_listhead -> next -> val);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
push(if_else_condition_stk,s -> arr[s ->  top]);
temporary_listhead = temporary_listhead->next;
printf("           [0;33m%7d[0m    |[0;34m            if(board[i][j]==1)[0m{\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |                return false;\n",s ->arr[s->top]);
printf("                      |            }\n");
pop(s);
pop(if_else_condition_stk);
printf("           [0;33m%7d[0m    |            i--;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |            j--;\n",s ->arr[s->top]);
printf("                      |        }\n");
pop(s);
printf("           [0;33m%7d[0m    |        i=x;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |        j=y;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |[0;34m        while(i>=0 && j<n)[0m{\n",s -> arr[s -> top] + temporary_listhead -> next -> val);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
push(if_else_condition_stk,s -> arr[s ->  top]);
temporary_listhead = temporary_listhead->next;
printf("           [0;33m%7d[0m    |[0;34m            if(board[i][j]==1)[0m{\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |                return false;\n",s ->arr[s->top]);
printf("                      |            }\n");
pop(s);
pop(if_else_condition_stk);
printf("           [0;33m%7d[0m    |            i--;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |            j++;\n",s ->arr[s->top]);
printf("                      |        }\n");
pop(s);
printf("           [0;33m%7d[0m    |        return true;\n",s ->arr[s->top]);
printf("                      |    }\n");
pop(s);
temporary_listhead = nqueen_helper_cnt;
printf("           [0;33m%7d[0m    |[0;31m    void nqueen_helper(int **board,int n, int i,int toput,int sol)[0m{\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
push(if_else_condition_stk,s -> arr[s ->  top]);
temporary_listhead = temporary_listhead->next;
printf("           [0;33m%7d[0m    |[0;34m        if(toput == 0)[0m{\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |            pmat(board,n);\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |            sol++;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |            return ;\n",s ->arr[s->top]);
printf("                      |        }\n");
pop(s);
pop(if_else_condition_stk);
push(if_else_condition_stk,s -> arr[s ->  top]);
temporary_listhead = temporary_listhead->next;
printf("           [0;33m%7d[0m    |[0;34m        if(i==n)[0m{\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |            return;\n",s ->arr[s->top]);
printf("                      |        }\n");
pop(s);
pop(if_else_condition_stk);
printf("           [0;33m%7d[0m    |        int j=0;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |[0;34m        while(j<n)[0m{\n",s -> arr[s -> top] + temporary_listhead -> next -> val);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
push(if_else_condition_stk,s -> arr[s ->  top]);
temporary_listhead = temporary_listhead->next;
printf("           [0;33m%7d[0m    |[0;34m            if(issafe(board,n,i,j,0))[0m{\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |                board[i][j]=1;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |                nqueen_helper(board,n,i+1,toput-1,sol);\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |                board[i][j]=0;\n",s ->arr[s->top]);
printf("                      |            }\n");
pop(s);
pop(if_else_condition_stk);
printf("           [0;33m%7d[0m    |            j++;\n",s ->arr[s->top]);
printf("                      |        }\n");
pop(s);
printf("           [0;33m%7d[0m    |        return ;\n",s ->arr[s->top]);
printf("                      |    }\n");
pop(s);
temporary_listhead = nqueen_cnt;
printf("           [0;33m%7d[0m    |[0;31m    void nqueen(int n)[0m{\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |        int **board = malloc(sizeof(int*)*n);\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |        int i = 0;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |[0;34m        while(i<n)[0m{\n",s -> arr[s -> top] + temporary_listhead -> next -> val);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |            board[i]=malloc(sizeof(int)*n);\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |            i++;\n",s ->arr[s->top]);
printf("                      |        }\n");
pop(s);
printf("           [0;33m%7d[0m    |        nqueen_helper(board,n,0,n,0);\n",s ->arr[s->top]);
printf("                      |    }\n");
pop(s);
temporary_listhead = main_cnt;
printf("           [0;33m%7d[0m    |[0;31m    int main()[0m{\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |        int n = 5;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |        nqueen(n);\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |        return 0;\n",s ->arr[s->top]);
printf("                      |    }\n");
pop(s);
free(s);
free(st);
free(if_else_condition_stk);
return 0;
}
