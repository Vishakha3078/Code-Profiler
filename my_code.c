#include"prof.h"
#include<stdio.h>
#define True 1
#define False 0
ListNode* main_cnt;
int main(){
main_cnt = makelist(5);
int My_Tot_Count = 0;
ListNode *temporary_listhead;
temporary_listhead = main_cnt;
temporary_listhead -> val++;
liststk *st = malloc(sizeof(struct liststack));
st -> size = 10;
st -> top = -1;
st -> arr = (ListNode**)malloc(sizeof(ListNode*)*st-> size);
int p = 2;
int i, isPrime;
temporary_listhead = temporary_listhead -> next;
listpush(st,temporary_listhead);
while( p < 1000 ){
temporary_listhead -> val++;
isPrime = True;
i = 2;
temporary_listhead = temporary_listhead -> next;
listpush(st,temporary_listhead);
while( isPrime && i < p ){
temporary_listhead -> val++;
if(p % i == 0){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(1,temporary_listhead);
temporary_listhead -> val++;
isPrime = False;
temporary_listhead = listpop(st);
}
temporary_listhead = traversenext(1,temporary_listhead);
i = i + 1;
temporary_listhead = st-> arr[st -> top];
}
listpop(st);
if(isPrime){
listpush(st,temporary_listhead);
temporary_listhead = traversenext(2,temporary_listhead);
temporary_listhead -> val++;
printf("%d ", p);
temporary_listhead = listpop(st);
}
temporary_listhead = traversenext(2,temporary_listhead);
p = p + 1;
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
printf("\n");temporary_listhead = main_cnt;
printf("           [0;33m%7d[0m    |[0;31m    int main()[0m{\n",temporary_listhead -> val);
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |        int p = 2;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |        int i, isPrime;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |[0;34m        while( p < 1000 )[0m{\n",s -> arr[s -> top] + temporary_listhead -> next -> val);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |            isPrime = True;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |            i = 2;\n",s ->arr[s->top]);
printf("           [0;33m%7d[0m    |[0;34m            while( isPrime && i < p )[0m{\n",s -> arr[s -> top] + temporary_listhead -> next -> val);
temporary_listhead = temporary_listhead->next;
push(s,temporary_listhead->val);
push(if_else_condition_stk,s -> arr[s ->  top]);
temporary_listhead = temporary_listhead->next;
printf("           [0;33m%7d[0m    |[0;34m                if(p %% i == 0)[0m{\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |                    isPrime = False;\n",s ->arr[s->top]);
printf("                      |                }\n");
pop(s);
pop(if_else_condition_stk);
printf("           [0;33m%7d[0m    |                i = i + 1;\n",s ->arr[s->top]);
printf("                      |            }\n");
pop(s);
push(if_else_condition_stk,s -> arr[s ->  top]);
temporary_listhead = temporary_listhead->next;
printf("           [0;33m%7d[0m    |[0;34m            if(isPrime)[0m{\n",if_else_condition_stk -> arr[if_else_condition_stk -> top]);
push(s,temporary_listhead->val);
printf("           [0;33m%7d[0m    |                printf(\"%%d \", p);\n",s ->arr[s->top]);
printf("                      |            }\n");
pop(s);
pop(if_else_condition_stk);
printf("           [0;33m%7d[0m    |            p = p + 1;\n",s ->arr[s->top]);
printf("                      |        }\n");
pop(s);
printf("           [0;33m%7d[0m    |        return 0;\n",s ->arr[s->top]);
printf("                      |    }\n");
pop(s);
free(s);
free(st);
free(if_else_condition_stk);
return 0;
}
