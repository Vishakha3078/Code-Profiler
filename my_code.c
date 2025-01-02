#include"new_code.h"
#include<stdio.h>
#define True 1
#define False 0
profiler_ListNode** I77GuuP3G3QdwKR6g1qVW6kJx1_0jOB;
int main(void){
I77GuuP3G3QdwKR6g1qVW6kJx1_0jOB=malloc(sizeof(profiler_ListNode*)*1);
I77GuuP3G3QdwKR6g1qVW6kJx1_0jOB[0] = profiler_makelist(6);
profiler_ListNode *LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao;
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = I77GuuP3G3QdwKR6g1qVW6kJx1_0jOB[0];
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> val++;
profiler_liststk *profiler_listnode_stack = malloc(sizeof(struct profiler_liststk));
profiler_listnode_stack -> size = 10;
profiler_listnode_stack -> top = -1;
profiler_listnode_stack -> arr = (profiler_ListNode**)malloc(sizeof(profiler_ListNode*)*profiler_listnode_stack-> size);
int i, isPrime;
int p = 7;
int cnt = 4;
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> next;
profiler_listpush(profiler_listnode_stack,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao);
while( p < 1000 ){
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> val++;
isPrime = True;
if(p % 3 == 0 || p % 5 == 0 || p % 7 == 0){
profiler_listpush(profiler_listnode_stack,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao);
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = profiler_traversenext(1,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao);
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> val++;
isPrime = False;
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = profiler_listpop(profiler_listnode_stack);
}
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = profiler_traversenext(1,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao);
i = 7;
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> next;
profiler_listpush(profiler_listnode_stack,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao);
while( isPrime && i*i <= p ){
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> val++;
if(p % i == 0){
profiler_listpush(profiler_listnode_stack,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao);
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = profiler_traversenext(1,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao);
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> val++;
isPrime = False;
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = profiler_listpop(profiler_listnode_stack);
}
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = profiler_traversenext(1,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao);
i = i + 2;
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = profiler_listnode_stack-> arr[profiler_listnode_stack -> top];
}
profiler_listpop(profiler_listnode_stack);
if(isPrime){
profiler_listpush(profiler_listnode_stack,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao);
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = profiler_traversenext(2,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao);
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> val++;
cnt++;
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = profiler_listpop(profiler_listnode_stack);
}
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = profiler_traversenext(2,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao);
p = p + 2;
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = profiler_listnode_stack-> arr[profiler_listnode_stack -> top];
}
profiler_listpop(profiler_listnode_stack);
free(profiler_listnode_stack);
profiler_stk *profiler_stack = malloc(sizeof(profiler_stk));
profiler_stack -> size = 10;
profiler_stack -> top = -1;
profiler_stack -> arr = (int*)malloc(sizeof(int)*profiler_stack-> size);
profiler_stk *profiler_if_else_condition_stk = malloc(sizeof(profiler_stk));
profiler_if_else_condition_stk -> size = 10;
profiler_if_else_condition_stk -> top = -1;
profiler_if_else_condition_stk -> arr = (int*)malloc(sizeof(int)*profiler_stack-> size);
printf("\n");LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = I77GuuP3G3QdwKR6g1qVW6kJx1_0jOB[0];
printf("           [0;33m%7d[0m    |[0;31m    int main(void)[0m{\n",LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> val);
profiler_push(profiler_stack,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> val);
printf("           [0;33m%7d[0m    |        int i, isPrime;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |        int p = 7;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |        int cnt = 4;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |[0;34m        while( p < 1000 )[0m{\n",profiler_stack -> arr[profiler_stack -> top] +LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> next -> val);
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> next;
profiler_push(profiler_stack,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> val);
printf("           [0;33m%7d[0m    |            isPrime = True;\n",profiler_stack ->arr[profiler_stack->top]);
profiler_push(profiler_if_else_condition_stk,profiler_stack -> arr[profiler_stack ->  top]);
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> next;
;
printf("           [0;33m%7d[0m    |[0;34m            if(p %% 3 == 0 || p %% 5 == 0 || p %% 7 == 0)[0m{\n",profiler_if_else_condition_stk -> arr[profiler_if_else_condition_stk -> top]);
profiler_push(profiler_stack,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> val);
printf("           [0;33m%7d[0m    |                isPrime = False;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |            }\n");
profiler_pop(profiler_stack);
profiler_pop(profiler_if_else_condition_stk);
printf("           [0;33m%7d[0m    |            i = 7;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |[0;34m            while( isPrime && i*i <= p )[0m{\n",profiler_stack -> arr[profiler_stack -> top] +LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> next -> val);
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> next;
profiler_push(profiler_stack,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> val);
profiler_push(profiler_if_else_condition_stk,profiler_stack -> arr[profiler_stack ->  top]);
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> next;
;
printf("           [0;33m%7d[0m    |[0;34m                if(p %% i == 0)[0m{\n",profiler_if_else_condition_stk -> arr[profiler_if_else_condition_stk -> top]);
profiler_push(profiler_stack,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> val);
printf("           [0;33m%7d[0m    |                    isPrime = False;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |                }\n");
profiler_pop(profiler_stack);
profiler_pop(profiler_if_else_condition_stk);
printf("           [0;33m%7d[0m    |                i = i + 2;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |            }\n");
profiler_pop(profiler_stack);
profiler_push(profiler_if_else_condition_stk,profiler_stack -> arr[profiler_stack ->  top]);
LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao = LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> next;
;
printf("           [0;33m%7d[0m    |[0;34m            if(isPrime)[0m{\n",profiler_if_else_condition_stk -> arr[profiler_if_else_condition_stk -> top]);
profiler_push(profiler_stack,LQ0YgfhNyoRggx_o3Xx6q51jV9Wfjao -> val);
printf("           [0;33m%7d[0m    |                cnt++;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |            }\n");
profiler_pop(profiler_stack);
profiler_pop(profiler_if_else_condition_stk);
printf("           [0;33m%7d[0m    |            p = p + 2;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |        }\n");
profiler_pop(profiler_stack);
printf("           [0;33m%7d[0m    |        return 0;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |    }\n");
profiler_pop(profiler_stack);
free(profiler_stack);
free(profiler_if_else_condition_stk);
return 0;
}
