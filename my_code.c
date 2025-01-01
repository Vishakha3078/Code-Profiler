#include"new_code.h"
#include<stdio.h>
#define True 1
#define False 0
profiler_ListNode** gY1Vbjw_SIBWojPPWMQowOvAWo1kkBJ;
int main(){
gY1Vbjw_SIBWojPPWMQowOvAWo1kkBJ=malloc(sizeof(profiler_ListNode*)*1);
gY1Vbjw_SIBWojPPWMQowOvAWo1kkBJ[0] = profiler_makelist(5);
profiler_ListNode *l3K4skaIR43q4zYuuySWdnr7xL3C7bL;
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = gY1Vbjw_SIBWojPPWMQowOvAWo1kkBJ[0];
l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> val++;
profiler_liststk *profiler_listnode_stack = malloc(sizeof(struct profiler_liststk));
profiler_listnode_stack -> size = 10;
profiler_listnode_stack -> top = -1;
profiler_listnode_stack -> arr = (profiler_ListNode**)malloc(sizeof(profiler_ListNode*)*profiler_listnode_stack-> size);
int p = 2;
int i, isPrime;
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> next;
profiler_listpush(profiler_listnode_stack,l3K4skaIR43q4zYuuySWdnr7xL3C7bL);
while( p < 1000 ){
l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> val++;
isPrime = True;
i = 2;
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> next;
profiler_listpush(profiler_listnode_stack,l3K4skaIR43q4zYuuySWdnr7xL3C7bL);
while( isPrime && i < p ){
l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> val++;
if(p % i == 0){
profiler_listpush(profiler_listnode_stack,l3K4skaIR43q4zYuuySWdnr7xL3C7bL);
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = profiler_traversenext(1,l3K4skaIR43q4zYuuySWdnr7xL3C7bL);
l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> val++;
isPrime = False;
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = profiler_listpop(profiler_listnode_stack);
}
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = profiler_traversenext(1,l3K4skaIR43q4zYuuySWdnr7xL3C7bL);
i = i + 1;
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = profiler_listnode_stack-> arr[profiler_listnode_stack -> top];
}
profiler_listpop(profiler_listnode_stack);
if(isPrime){
profiler_listpush(profiler_listnode_stack,l3K4skaIR43q4zYuuySWdnr7xL3C7bL);
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = profiler_traversenext(2,l3K4skaIR43q4zYuuySWdnr7xL3C7bL);
l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> val++;
printf("%d ", p);
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = profiler_listpop(profiler_listnode_stack);
}
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = profiler_traversenext(2,l3K4skaIR43q4zYuuySWdnr7xL3C7bL);
p = p + 1;
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = profiler_listnode_stack-> arr[profiler_listnode_stack -> top];
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
printf("\n");l3K4skaIR43q4zYuuySWdnr7xL3C7bL = gY1Vbjw_SIBWojPPWMQowOvAWo1kkBJ[0];
printf("           [0;33m%7d[0m    |[0;31m    int main()[0m{\n",l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> val);
profiler_push(profiler_stack,l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> val);
printf("           [0;33m%7d[0m    |        int p = 2;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |        int i, isPrime;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |[0;34m        while( p < 1000 )[0m{\n",profiler_stack -> arr[profiler_stack -> top] +l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> next -> val);
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> next;
profiler_push(profiler_stack,l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> val);
printf("           [0;33m%7d[0m    |            isPrime = True;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |            i = 2;\n",profiler_stack ->arr[profiler_stack->top]);
printf("           [0;33m%7d[0m    |[0;34m            while( isPrime && i < p )[0m{\n",profiler_stack -> arr[profiler_stack -> top] +l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> next -> val);
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> next;
profiler_push(profiler_stack,l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> val);
profiler_push(profiler_if_else_condition_stk,profiler_stack -> arr[profiler_stack ->  top]);
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> next;
;
printf("           [0;33m%7d[0m    |[0;34m                if(p %% i == 0)[0m{\n",profiler_if_else_condition_stk -> arr[profiler_if_else_condition_stk -> top]);
profiler_push(profiler_stack,l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> val);
printf("           [0;33m%7d[0m    |                    isPrime = False;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |                }\n");
profiler_pop(profiler_stack);
profiler_pop(profiler_if_else_condition_stk);
printf("           [0;33m%7d[0m    |                i = i + 1;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |            }\n");
profiler_pop(profiler_stack);
profiler_push(profiler_if_else_condition_stk,profiler_stack -> arr[profiler_stack ->  top]);
l3K4skaIR43q4zYuuySWdnr7xL3C7bL = l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> next;
;
printf("           [0;33m%7d[0m    |[0;34m            if(isPrime)[0m{\n",profiler_if_else_condition_stk -> arr[profiler_if_else_condition_stk -> top]);
profiler_push(profiler_stack,l3K4skaIR43q4zYuuySWdnr7xL3C7bL -> val);
printf("           [0;33m%7d[0m    |                printf(\"%%d \", p);\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |            }\n");
profiler_pop(profiler_stack);
profiler_pop(profiler_if_else_condition_stk);
printf("           [0;33m%7d[0m    |            p = p + 1;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |        }\n");
profiler_pop(profiler_stack);
printf("           [0;33m%7d[0m    |        return 0;\n",profiler_stack ->arr[profiler_stack->top]);
printf("                      |    }\n");
profiler_pop(profiler_stack);
free(profiler_stack);
free(profiler_if_else_condition_stk);
return 0;
}
