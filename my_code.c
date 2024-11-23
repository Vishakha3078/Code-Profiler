#include<prof.h>
#include<stdio.h>
#include<stdlib.h>
void foo(int i);
void moo(int i);
ListNode* main_cnt;
ListNode* foo_cnt;
ListNode* moo_cnt;
ListNode *temporary_listhead;
int main(){
main_cnt = makelist(5);
foo_cnt = makelist(2);
moo_cnt = makelist(2);
temporary_listhead = main_cnt;
temporary_listhead -> val++;
stk *st = malloc(sizeof(stk));
st -> size = 10;
st -> top = -1;
st -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);
int i,j,k;
j = 2;
k = 3;
foo(j);
temporary_listhead = temporary_listhead -> next;
push(st,temporary_listhead);
while(j != 0){
temporary_listhead -> val++;
j--;
temporary_listhead = st-> arr[st -> top];
}
pop(st);
if(j < k){
temporary_listhead = temporary_listhead -> next;
temporary_listhead -> val++;
j = k;
}
else if(j = k){
temporary_listhead = temporary_listhead -> next;
temporary_listhead -> val++;
k = j;
}
else{
temporary_listhead = temporary_listhead -> next;
temporary_listhead -> val++;
k = k;
}
i = j + k;
moo(i);
stk *s = malloc(sizeof(stk));
s -> size = 10;
s -> top = -1;
s -> arr = (int*)malloc(sizeof(int)*s-> size);
temporary_listhead = main_cnt;
printf("    int main(){ -> %d\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("    int i,j,k; -> %d\n",s ->arr[s->top]);
printf("    j = 2; -> %d\n",s ->arr[s->top]);
printf("    k = 3; -> %d\n",s ->arr[s->top]);
printf("    foo(j); -> %d\n",s ->arr[s->top]);
temporary_listhead = temporary_listhead->next;
printf("    while(j != 0){ -> %d\n",temporary_listhead -> val + 1);
push(s,temporary_listhead->val);
printf("    j--; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
temporary_listhead = temporary_listhead->next;
printf("    if(j < k){ -> %d\n",temporary_listhead -> val + 1);
push(s,temporary_listhead->val);
printf("    j = k; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
temporary_listhead = temporary_listhead->next;
printf("    else if(j = k){ -> %d\n",temporary_listhead -> val + 1);
push(s,temporary_listhead->val);
printf("    k = j; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
temporary_listhead = temporary_listhead->next;
printf("    else{ -> %d\n",temporary_listhead -> val + 1);
push(s,temporary_listhead->val);
printf("    k = k; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
printf("    i = j + k; -> %d\n",s ->arr[s->top]);
printf("    moo(i); -> %d\n",s ->arr[s->top]);
printf("    return 0; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
temporary_listhead = foo_cnt;
printf("    void foo(int i){ -> %d\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("    int j = 0; -> %d\n",s ->arr[s->top]);
temporary_listhead = temporary_listhead->next;
printf("    while(j < i){ -> %d\n",temporary_listhead -> val + 1);
push(s,temporary_listhead->val);
printf("    printf("sdfsgsd"); -> %d\n",s ->arr[s->top]);
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
printf("    while(j < i){ -> %d\n",temporary_listhead -> val + 1);
push(s,temporary_listhead->val);
printf("    printf("sdfsgsd"); -> %d\n",s ->arr[s->top]);
printf("    j++; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
printf("    }\n");
pop(s);
free(s);
free(st);
return 0;
}
void foo(int i){
temporary_listhead = foo_cnt;
temporary_listhead -> val++;
stk *st = malloc(sizeof(stk));
st -> size = 10;
st -> top = -1;
st -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);
int j = 0;
temporary_listhead = temporary_listhead -> next;
push(st,temporary_listhead);
while(j < i){
temporary_listhead -> val++;
printf("sdfsgsd");
j++;
temporary_listhead = st-> arr[st -> top];
}
pop(st);
}
void moo(int i){
temporary_listhead = moo_cnt;
temporary_listhead -> val++;
stk *st = malloc(sizeof(stk));
st -> size = 10;
st -> top = -1;
st -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);
int j = 0;
temporary_listhead = temporary_listhead -> next;
push(st,temporary_listhead);
while(j < i){
temporary_listhead -> val++;
printf("sdfsgsd");
j++;
temporary_listhead = st-> arr[st -> top];
}
pop(st);
}
