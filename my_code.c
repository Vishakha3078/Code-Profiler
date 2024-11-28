#include"prof.h"
#include<stdio.h>
#include<stdlib.h>
void foo(int i);
void moo(int i);
ListNode* main_cnt;
ListNode* foo_cnt;
ListNode* moo_cnt;
int main(){
main_cnt = makelist(13);
foo_cnt = makelist(2);
moo_cnt = makelist(2);
ListNode *temporary_listhead;
ListNode *temp;
temporary_listhead = main_cnt;
temporary_listhead -> val++;
liststk *st = malloc(sizeof(struct liststack));
st -> size = 10;
st -> top = -1;
st -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);
int i,j,k;
j = 2;
k = 3;
i = 5;
foo(j);
temporary_listhead = temporary_listhead -> next;
listpush(st,temporary_listhead);
while(j != 0){
temporary_listhead -> val++;
j--;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
temporary_listhead = temporary_listhead -> next;
listpush(st,temporary_listhead);
while(k != 1){
temporary_listhead -> val++;
k--;
temporary_listhead = temporary_listhead -> next;
listpush(st,temporary_listhead);
while(i > 4){
temporary_listhead -> val++;
if(j < k){
temp = temporary_listhead;
temporary_listhead = traversenext(1,temporary_listhead);
temporary_listhead -> val++;
j = k;
temporary_listhead = temp;
}
else if(j == k){
temp = temporary_listhead;
temporary_listhead = traversenext(2,temporary_listhead);
temporary_listhead -> val++;
k = j;
temporary_listhead = temp;
}
else{
temp = temporary_listhead;
temporary_listhead = traversenext(3,temporary_listhead);
temporary_listhead -> val++;
k = k;
temporary_listhead = temp;
}
temporary_listhead = traversenext(3,temporary_listhead);
i--;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
i = 5;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
i = j + k;
if(i < i){
temp = temporary_listhead;
temporary_listhead = traversenext(5,temporary_listhead);
temporary_listhead -> val++;
i=i;
temporary_listhead = temp;
}
else if(j < j){
temp = temporary_listhead;
temporary_listhead = traversenext(6,temporary_listhead);
temporary_listhead -> val++;
j=j;
temporary_listhead = temp;
}
else{
temp = temporary_listhead;
temporary_listhead = traversenext(7,temporary_listhead);
temporary_listhead -> val++;
j=j;
temporary_listhead = temp;
}
temporary_listhead = traversenext(7,temporary_listhead);
if(i < i){
temp = temporary_listhead;
temporary_listhead = traversenext(1,temporary_listhead);
temporary_listhead -> val++;
i=i;
temporary_listhead = temp;
}
else if(j < j){
temp = temporary_listhead;
temporary_listhead = traversenext(2,temporary_listhead);
temporary_listhead -> val++;
j=j;
temporary_listhead = temp;
}
else{
temp = temporary_listhead;
temporary_listhead = traversenext(3,temporary_listhead);
temporary_listhead -> val++;
j=j;
temporary_listhead = temp;
}
temporary_listhead = traversenext(3,temporary_listhead);
moo(i);
stk *s = malloc(sizeof(stk));
s -> size = 10;
s -> top = -1;
s -> arr = (int*)malloc(sizeof(int)*s-> size);
stk *if_else_condition_stk = malloc(sizeof(stk));
if_else_condition_stk -> size = 10;
if_else_condition_stk -> top = -1;
if_else_condition_stk -> arr = (int*)malloc(sizeof(int)*s-> size);
temporary_listhead = main_cnt;
printf("    int main(){ -> %d\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("    int i,j,k; -> %d\n",s ->arr[s->top]);
printf("    j = 2; -> %d\n",s ->arr[s->top]);
printf("    k = 3; -> %d\n",s ->arr[s->top]);
printf("    i = 5; -> %d\n",s ->arr[s->top]);
printf("    foo(j); -> %d\n",s ->arr[s->top]);
temporary_listhead = temporary_listhead->next;
printf("    while(j != 0){\n");
push(s,temporary_listhead->val);
printf("    j--; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
temporary_listhead = temporary_listhead->next;
printf("    while(k != 1){\n");
push(s,temporary_listhead->val);
printf("    k--; -> %d\n",s ->arr[s->top]);
temporary_listhead = temporary_listhead->next;
printf("    while(i > 4){\n");
push(s,temporary_listhead->val);
push(if_else_condition_stk,temporary_listhead -> val);
temporary_listhead = temporary_listhead->next;
printf("    if(j < k){ -> %d\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("    j = k; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
push(if_else_condition_stk,pop(if_else_condition_stk) - (temporary_listhead->val));
temporary_listhead = temporary_listhead -> next;
printf("    else if(j == k){ -> %d\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("    k = j; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
pop(if_else_condition_stk);
temporary_listhead = temporary_listhead -> next;
printf("    else{ -> %d\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("    k = k; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
pop(if_else_condition_stk);
printf("    i--; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
printf("    i = 5; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
printf("    i = j + k; -> %d\n",s ->arr[s->top]);
push(if_else_condition_stk,temporary_listhead -> val);
temporary_listhead = temporary_listhead->next;
printf("    if(i < i){ -> %d\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("    i=i; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
push(if_else_condition_stk,pop(if_else_condition_stk) - (temporary_listhead->val));
temporary_listhead = temporary_listhead -> next;
printf("    else if(j < j){ -> %d\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("    j=j; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
pop(if_else_condition_stk);
temporary_listhead = temporary_listhead -> next;
printf("    else{ -> %d\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("    j=j; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
pop(if_else_condition_stk);
push(if_else_condition_stk,temporary_listhead -> val);
temporary_listhead = temporary_listhead->next;
printf("    if(i < i){ -> %d\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("    i=i; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
push(if_else_condition_stk,pop(if_else_condition_stk) - (temporary_listhead->val));
temporary_listhead = temporary_listhead -> next;
printf("    else if(j < j){ -> %d\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("    j=j; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
pop(if_else_condition_stk);
temporary_listhead = temporary_listhead -> next;
printf("    else{ -> %d\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("    j=j; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
pop(if_else_condition_stk);
printf("    moo(i); -> %d\n",s ->arr[s->top]);
printf("    return 0; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
temporary_listhead = foo_cnt;
printf("    void foo(int i){ -> %d\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("    int j = 0; -> %d\n",s ->arr[s->top]);
temporary_listhead = temporary_listhead->next;
printf("    while(j < i){\n");
push(s,temporary_listhead->val);
printf("    j++; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
printf("    }\n");
pop(s);
temporary_listhead = moo_cnt;
printf("    void moo(int i){ -> %d\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("    int j = 0; -> %d\n",s ->arr[s->top]);
temporary_listhead = temporary_listhead->next;
printf("    while(j < i){\n");
push(s,temporary_listhead->val);
printf("    j++; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
printf("    }\n");
pop(s);
free(s);
free(st);
free(if_else_condition_stk);
return 0;
}
void foo(int i){
ListNode *temporary_listhead;
ListNode *temp;
temporary_listhead = foo_cnt;
temporary_listhead -> val++;
liststk *st = malloc(sizeof(struct liststack));
st -> size = 10;
st -> top = -1;
st -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);
int j = 0;
temporary_listhead = temporary_listhead -> next;
listpush(st,temporary_listhead);
while(j < i){
temporary_listhead -> val++;
j++;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
}
void moo(int i){
ListNode *temporary_listhead;
ListNode *temp;
temporary_listhead = moo_cnt;
temporary_listhead -> val++;
liststk *st = malloc(sizeof(struct liststack));
st -> size = 10;
st -> top = -1;
st -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);
int j = 0;
temporary_listhead = temporary_listhead -> next;
listpush(st,temporary_listhead);
while(j < i){
temporary_listhead -> val++;
j++;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
}
