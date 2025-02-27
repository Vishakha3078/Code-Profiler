#include"new_code.h"
#include<stdio.h>
#define True 1
#define False 0
profiler_ListNode** H6Lyzm4K_yjrPXPToKqyJjaztSJBiIC;
int main(void){
H6Lyzm4K_yjrPXPToKqyJjaztSJBiIC=malloc(sizeof(profiler_ListNode*)*1);
H6Lyzm4K_yjrPXPToKqyJjaztSJBiIC[0] = profiler_makelist(6);
profiler_ListNode *Z4lMwPlX3PwCmb187sGbQVTXunyEyTN;
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = H6Lyzm4K_yjrPXPToKqyJjaztSJBiIC[0];
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> val++;
profiler_liststk *profiler_listnode_stack = malloc(sizeof(struct profiler_liststk));
profiler_listnode_stack -> size = 10;
profiler_listnode_stack -> top = -1;
profiler_listnode_stack -> arr = (profiler_ListNode**)malloc(sizeof(profiler_ListNode*)*profiler_listnode_stack-> size);
int i, isPrime;
int p = 7;
int cnt = 4;
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> next;
profiler_listpush(profiler_listnode_stack,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN);
while( p < 1000 ){
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> val++;
isPrime = True;
if(p % 3 == 0 || p % 5 == 0 || p % 7 == 0){
profiler_listpush(profiler_listnode_stack,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN);
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = profiler_traversenext(1,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN);
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> val++;
isPrime = False;
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = profiler_listpop(profiler_listnode_stack);
}
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = profiler_traversenext(1,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN);
i = 7;
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> next;
profiler_listpush(profiler_listnode_stack,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN);
while( isPrime && i*i <= p ){
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> val++;
if(p % i == 0){
profiler_listpush(profiler_listnode_stack,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN);
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = profiler_traversenext(1,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN);
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> val++;
isPrime = False;
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = profiler_listpop(profiler_listnode_stack);
}
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = profiler_traversenext(1,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN);
i = i + 2;
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = profiler_listnode_stack-> arr[profiler_listnode_stack -> top];
}
profiler_listpop(profiler_listnode_stack);
if(isPrime){
profiler_listpush(profiler_listnode_stack,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN);
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = profiler_traversenext(2,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN);
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> val++;
cnt++;
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = profiler_listpop(profiler_listnode_stack);
}
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = profiler_traversenext(2,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN);
p = p + 2;
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = profiler_listnode_stack-> arr[profiler_listnode_stack -> top];
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
printf("\n");Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = H6Lyzm4K_yjrPXPToKqyJjaztSJBiIC[0];
printf("           [0;33m%7d[0m    |[0;31m    int main(void)[0m{\n",Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> val);
profiler_push(profiler_stack,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> val);
printf("           [0;33m%7d[0m    |        int i, isPrime;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |        int p = 7;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |        int cnt = 4;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |[0;34m        while( p < 1000 )[0m{\n",profiler_stack -> arr[profiler_stack -> top] +Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> next -> val);
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> next;
profiler_push(profiler_stack,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> val);
printf("           [0;33m%7d[0m    |            isPrime = True;\n",profiler_stack ->arr[profiler_stack->top]);
profiler_push(profiler_if_else_condition_stk,profiler_stack -> arr[profiler_stack ->  top]);
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> next;
;
printf("           [0;33m%7d[0m    |[0;34m            if(p %% 3 == 0 || p %% 5 == 0 || p %% 7 == 0)[0m{\n",profiler_if_else_condition_stk -> arr[profiler_if_else_condition_stk -> top]);
profiler_push(profiler_stack,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> val);
printf("           [0;33m%7d[0m    |                isPrime = False;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |            }\n");
profiler_pop(profiler_stack);
profiler_pop(profiler_if_else_condition_stk);
printf("           [0;33m%7d[0m    |            i = 7;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |[0;34m            while( isPrime && i*i <= p )[0m{\n",profiler_stack -> arr[profiler_stack -> top] +Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> next -> val);
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> next;
profiler_push(profiler_stack,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> val);
profiler_push(profiler_if_else_condition_stk,profiler_stack -> arr[profiler_stack ->  top]);
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> next;
;
printf("           [0;33m%7d[0m    |[0;34m                if(p %% i == 0)[0m{\n",profiler_if_else_condition_stk -> arr[profiler_if_else_condition_stk -> top]);
profiler_push(profiler_stack,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> val);
printf("           [0;33m%7d[0m    |                    isPrime = False;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |                }\n");
profiler_pop(profiler_stack);
profiler_pop(profiler_if_else_condition_stk);
printf("           [0;33m%7d[0m    |                i = i + 2;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |            }\n");
profiler_pop(profiler_stack);
profiler_push(profiler_if_else_condition_stk,profiler_stack -> arr[profiler_stack ->  top]);
Z4lMwPlX3PwCmb187sGbQVTXunyEyTN = Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> next;
;
printf("           [0;33m%7d[0m    |[0;34m            if(isPrime)[0m{\n",profiler_if_else_condition_stk -> arr[profiler_if_else_condition_stk -> top]);
profiler_push(profiler_stack,Z4lMwPlX3PwCmb187sGbQVTXunyEyTN -> val);
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
