#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"ctype.h"
#include"stdbool.h"
#include"unistd.h"
#include"time.h"


typedef struct profiler_ListNode{
    struct profiler_ListNode *next;
    unsigned int val;
}profiler_ListNode;

typedef struct profiler_stk{
    int size;
    int top;
    int *arr;
}profiler_stk;

typedef struct profiler_liststk{
    int size;
    int top;
    profiler_ListNode **arr;
}profiler_liststk;


profiler_ListNode *profiler_makeNode();
profiler_ListNode *profiler_makelist(int n);
int profiler_pop(profiler_stk *s);
void profiler_push(profiler_stk *s,int val);
profiler_ListNode* profiler_listpop(profiler_liststk *s);
void profiler_listpush(profiler_liststk *s,profiler_ListNode *nd);
profiler_ListNode* profiler_traversenext(int n,profiler_ListNode* nd);
