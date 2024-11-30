#include"prof.h"
#include<stdio.h>
#include<stdlib.h>
void foo(int i);
void moo(int i);
ListNode* main_cnt;
ListNode* foo_cnt;
ListNode* moo_cnt;
int main(){
main_cnt = makelist(15);
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
int i,j,k,m;
j = 2;
k = 3;
i = 5;
m = 0;
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
listpush(st,temporary_listhead);
temporary_listhead = traversenext(1,temporary_listhead);
temporary_listhead -> val++;
j = k;
temporary_listhead = listpop(st);
}
else if(j == k){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(2,temporary_listhead);
temporary_listhead -> val++;
k = j;
temporary_listhead = listpop(st);
}
else{
listpush(st,temporary_listhead);
temporary_listhead = traversenext(3,temporary_listhead);
temporary_listhead -> val++;
k = k;
temporary_listhead = listpop(st);
}
temporary_listhead = traversenext(3,temporary_listhead);
i--;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
temporary_listhead = traversenext(4,temporary_listhead);
listpush(st,temporary_listhead);
while(m!= 1){
temporary_listhead -> val++;
m++;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
i= 5;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
i = j + k;
if(i < i){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(6,temporary_listhead);
temporary_listhead -> val++;
i=i;
temporary_listhead = listpop(st);
}
else if(j < j){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(7,temporary_listhead);
temporary_listhead -> val++;
j=j;
temporary_listhead = listpop(st);
}
else{
listpush(st,temporary_listhead);
temporary_listhead = traversenext(8,temporary_listhead);
temporary_listhead -> val++;
j=j;
if(j != 0){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(1,temporary_listhead);
temporary_listhead -> val++;
k++;
temporary_listhead = listpop(st);
}
temporary_listhead = traversenext(1,temporary_listhead);
j--;
temporary_listhead = listpop(st);
}
temporary_listhead = traversenext(9,temporary_listhead);
if(i < i){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(1,temporary_listhead);
temporary_listhead -> val++;
i=i;
temporary_listhead = listpop(st);
}
else if(j < j){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(2,temporary_listhead);
temporary_listhead -> val++;
j=j;
temporary_listhead = listpop(st);
}
else{
listpush(st,temporary_listhead);
temporary_listhead = traversenext(3,temporary_listhead);
temporary_listhead -> val++;
j=j;
temporary_listhead = listpop(st);
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
printf("    %7d    ->        int main(){\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("    %7d    ->            int i,j,k,m;\n",s ->arr[s->top]);
printf("    %7d    ->            j = 2;\n",s ->arr[s->top]);
printf("    %7d    ->            k = 3;\n",s ->arr[s->top]);
printf("    %7d    ->            i = 5;\n",s ->arr[s->top]);
printf("    %7d    ->            m = 0;\n",s ->arr[s->top]);
printf("    %7d    ->            foo(j);\n",s ->arr[s->top]);
printf("    %7d    ->            while(j != 0){\n",temporary_listhead -> next -> val + 1);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
printf("    %7d    ->                j--;\n",s ->arr[s->top]);
printf("                             }\n");
pop(s);
printf("    %7d    ->            while(k != 1){\n",temporary_listhead -> next -> val + 1);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
printf("    %7d    ->                k--;\n",s ->arr[s->top]);
printf("    %7d    ->                while(i > 4){\n",s -> arr[s -> top] + temporary_listhead -> next -> val);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
push(if_else_condition_stk,temporary_listhead -> val);
temporary_listhead = temporary_listhead->next;
printf("    %7d    ->                    if(j < k){\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("    %7d    ->                        j = k;\n",s ->arr[s->top]);
printf("                                     }\n");
pop(s);
push(if_else_condition_stk,pop(if_else_condition_stk) - (temporary_listhead->val));
temporary_listhead = temporary_listhead -> next;
printf("    %7d    ->                    else if(j == k){\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("    %7d    ->                        k = j;\n",s ->arr[s->top]);
printf("                                     }\n");
pop(s);
pop(if_else_condition_stk);
temporary_listhead = temporary_listhead -> next;
printf("    %7d    ->                    else\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("    %7d    ->                        k = k;\n",s ->arr[s->top]);
printf("                                     }\n");
pop(s);
pop(if_else_condition_stk);
printf("    %7d    ->                    i--;\n",s ->arr[s->top]);
printf("                                 }\n");
pop(s);
printf("    %7d    ->                while(m!= 1){\n",s -> arr[s -> top] + temporary_listhead -> next -> val);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
printf("    %7d    ->                    m++;\n",s ->arr[s->top]);
printf("                                 }\n");
pop(s);
printf("    %7d    ->                i= 5;\n",s ->arr[s->top]);
printf("                             }\n");
pop(s);
printf("    %7d    ->            i = j + k;\n",s ->arr[s->top]);
push(if_else_condition_stk,1);
temporary_listhead = temporary_listhead->next;
printf("    %7d    ->            if(i < i){\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("    %7d    ->                i=i;\n",s ->arr[s->top]);
printf("                             }\n");
pop(s);
push(if_else_condition_stk,pop(if_else_condition_stk) - (temporary_listhead->val));
temporary_listhead = temporary_listhead -> next;
printf("    %7d    ->            else if(j < j){\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("    %7d    ->                j=j;\n",s ->arr[s->top]);
printf("                             }\n");
pop(s);
pop(if_else_condition_stk);
temporary_listhead = temporary_listhead -> next;
printf("    %7d    ->            else\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("    %7d    ->                j=j;\n",s ->arr[s->top]);
push(if_else_condition_stk,temporary_listhead -> val);
temporary_listhead = temporary_listhead->next;
printf("    %7d    ->                if(j != 0){\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("    %7d    ->                    k++;\n",s ->arr[s->top]);
printf("                                 }\n");
pop(s);
pop(if_else_condition_stk);
printf("    %7d    ->                j--;\n",s ->arr[s->top]);
printf("                             }\n");
pop(s);
pop(if_else_condition_stk);
push(if_else_condition_stk,1);
temporary_listhead = temporary_listhead->next;
printf("    %7d    ->            if(i < i){\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("    %7d    ->                i=i;\n",s ->arr[s->top]);
printf("                             }\n");
pop(s);
push(if_else_condition_stk,pop(if_else_condition_stk) - (temporary_listhead->val));
temporary_listhead = temporary_listhead -> next;
printf("    %7d    ->            else if(j < j){\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("    %7d    ->                j=j;\n",s ->arr[s->top]);
printf("                             }\n");
pop(s);
pop(if_else_condition_stk);
temporary_listhead = temporary_listhead -> next;
printf("    %7d    ->            else\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("    %7d    ->                j=j;\n",s ->arr[s->top]);
printf("                             }\n");
pop(s);
pop(if_else_condition_stk);
printf("    %7d    ->            moo(i);\n",s ->arr[s->top]);
printf("    %7d    ->            return 0;\n",s ->arr[s->top]);
printf("                         }\n");
pop(s);
temporary_listhead = foo_cnt;
printf("    %7d    ->        void foo(int i){\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("    %7d    ->            int j = 0;\n",s ->arr[s->top]);
printf("    %7d    ->            while(j < i){\n",temporary_listhead -> next -> val + 1);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
printf("    %7d    ->                j++;\n",s ->arr[s->top]);
printf("                             }\n");
pop(s);
printf("                         }\n");
pop(s);
temporary_listhead = moo_cnt;
printf("    %7d    ->        void moo(int i){\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("    %7d    ->            int j = 0;\n",s ->arr[s->top]);
printf("    %7d    ->            while(j < i){\n",temporary_listhead -> next -> val + 1);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
printf("    %7d    ->                j++;\n",s ->arr[s->top]);
printf("                             }\n");
pop(s);
printf("                         }\n");
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
