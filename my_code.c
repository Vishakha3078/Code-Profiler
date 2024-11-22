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
int i,j,k;
j = 2;
k = 3;
foo(j);
temporary_listhead = temporary_listhead -> right;
while(j != 0){
temporary_listhead -> val++;
j--;
}
temporary_listhead = temporary_listhead -> left;
if(j < k){
temporary_listhead = traversenext(2,temporary_listhead);
temporary_listhead -> val++;
j = k;
temporary_listhead = traverseprev(2,temporary_listhead);
}
else if(j = k){
temporary_listhead = traversenext(3,temporary_listhead);
temporary_listhead -> val++;
k = j;
temporary_listhead = traverseprev(3,temporary_listhead);
}
else{
temporary_listhead = traversenext(4,temporary_listhead);
temporary_listhead -> val++;
k = k;
temporary_listhead = traverseprev(4,temporary_listhead);
}
i = j + k;
moo(i);
stk *s = malloc(sizeof(stk));
s -> arr = (int*)malloc(sizeof(int)*s-> size);
s -> size = 10;
s -> top = -1;
temporary_listhead = main_cnt;
printf("    int main(){\n);
push(s,temporary_listhead->val);
printf("    int i,j,k; -> %d\n",s ->arr[s->top]);
printf("    j = 2; -> %d\n",s ->arr[s->top]);
printf("    k = 3; -> %d\n",s ->arr[s->top]);
printf("    foo(j); -> %d\n",s ->arr[s->top]);
temporary_listhead = temporary_listhead->right;
printf("    while(j != 0){ -> %d\n",temporary_listhead->val + 1);
push(s,temporary_listhead->val);
printf("    j--; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
temporary_listhead = temporary_listhead->right;
printf("    if(j < k){ -> %d\n",temporary_listhead->val + 1);
push(s,temporary_listhead->val);
printf("    j = k; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
temporary_listhead = temporary_listhead->right;
printf("    else if(j = k){ -> %d\n",temporary_listhead->val + 1);
push(s,temporary_listhead->val);
printf("    k = j; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
temporary_listhead = temporary_listhead->right;
printf("    else{ -> %d\n",temporary_listhead->val + 1);
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
printf("    void foo(int i){\n);
push(s,temporary_listhead->val);
printf("    int j = 0; -> %d\n",s ->arr[s->top]);
temporary_listhead = temporary_listhead->right;
printf("    while(j < i){ -> %d\n",temporary_listhead->val + 1);
push(s,temporary_listhead->val);
printf("    printf("sdfsgsd"); -> %d\n",s ->arr[s->top]);
printf("    j++; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
printf("    }\n");
pop(s);
temporary_listhead = moo_cnt;
printf("    void moo(int i){\n);
push(s,temporary_listhead->val);
printf("    int j = 0; -> %d\n",s ->arr[s->top]);
temporary_listhead = temporary_listhead->right;
printf("    while(j < i){ -> %d\n",temporary_listhead->val + 1);
push(s,temporary_listhead->val);
printf("    printf("sdfsgsd"); -> %d\n",s ->arr[s->top]);
printf("    j++; -> %d\n",s ->arr[s->top]);
printf("    }\n");
pop(s);
printf("    }\n");
pop(s);
free(s);
return 0;
}
void foo(int i){
temporary_listhead = foo_cnt;
temporary_listhead -> val++;
int j = 0;
temporary_listhead = temporary_listhead -> right;
while(j < i){
temporary_listhead -> val++;
printf("sdfsgsd");
j++;
}
temporary_listhead = temporary_listhead -> left;
}
void moo(int i){
temporary_listhead = moo_cnt;
temporary_listhead -> val++;
int j = 0;
temporary_listhead = temporary_listhead -> right;
while(j < i){
temporary_listhead -> val++;
printf("sdfsgsd");
j++;
}
temporary_listhead = temporary_listhead -> left;
}
