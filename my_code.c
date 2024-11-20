#include<prof.h>
#include<stdio.h>
#include<stdlib.h>
void foo(int i);(int i);
void moo(int i);(int i);
ListNode* int main_cnt;
ListNode* void foo_cnt;
ListNode* void moo_cnt;
ListNode *temporary_listhead;
int main(){
int main_cnt = makelist(5);
void foo_cnt = makelist(2);
void moo_cnt = makelist(2);
temporary_listhead = int main_cnt;
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
return 0;
}
void foo(int i){
temporary_listhead = void foo_cnt;
temporary_listhead -> val++;
int j = 0;
temporary_listhead = temporary_listhead -> right;
while(j < i){
temporary_listhead -> val++;
printf("sdfsgsd");
}
temporary_listhead = temporary_listhead -> left;
j++;
}
void moo(int i){
temporary_listhead = void moo_cnt;
temporary_listhead -> val++;
int j = 0;
temporary_listhead = temporary_listhead -> right;
while(j < i){
temporary_listhead -> val++;
printf("sdfsgsd");
}
temporary_listhead = temporary_listhead -> left;
j++;
}
