#include"prof.h"
#include<stdio.h>
ListNode* main_cnt;
int main(){
main_cnt = makelist(3);
ListNode *temporary_listhead;
temporary_listhead = main_cnt;
temporary_listhead -> val++;
liststk *st = malloc(sizeof(struct liststack));
st -> size = 10;
st -> top = -1;
st -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);
int arr[] = {9,7,6,5,4,3,2,1};
int n = 8;
int temp,i,j;
i = 1;
temporary_listhead = temporary_listhead -> next;
listpush(st,temporary_listhead);
while(i < n){
temporary_listhead -> val++;
temp = arr[i];
j = i-1;
temporary_listhead = temporary_listhead -> next;
listpush(st,temporary_listhead);
while( j >= 0 && arr[j] > temp){
temporary_listhead -> val++;
arr[j+1] = arr[j];
j--;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
arr[j+1] = temp;
i++;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
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
printf("    %7d    ->            int arr[] = {9,7,6,5,4,3,2,1};\n",s ->arr[s->top]);
printf("    %7d    ->            int n = 8;\n",s ->arr[s->top]);
printf("    %7d    ->            int temp,i,j;\n",s ->arr[s->top]);
printf("    %7d    ->            i = 1;\n",s ->arr[s->top]);
printf("    %7d    ->            while(i < n){\n",temporary_listhead -> next -> val + 1);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
printf("    %7d    ->                temp = arr[i];\n",s ->arr[s->top]);
printf("    %7d    ->                j = i-1;\n",s ->arr[s->top]);
printf("    %7d    ->                while( j >= 0 && arr[j] > temp){\n",s -> arr[s -> top] + temporary_listhead -> next -> val);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
printf("    %7d    ->                    arr[j+1] = arr[j];\n",s ->arr[s->top]);
printf("    %7d    ->                    j--;\n",s ->arr[s->top]);
printf("                                 }\n");
pop(s);
printf("    %7d    ->                arr[j+1] = temp;\n",s ->arr[s->top]);
printf("    %7d    ->                i++;\n",s ->arr[s->top]);
printf("                             }\n");
pop(s);
printf("    %7d    ->            return 0;\n",s ->arr[s->top]);
printf("                         }\n");
pop(s);
free(s);
free(st);
free(if_else_condition_stk);
return 0;
}
