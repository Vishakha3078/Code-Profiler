#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"ctype.h"
#include"stdbool.h"
#include"unistd.h"
#include"time.h"


typedef struct ListNode{
    struct ListNode *next;
    unsigned int val;
}ListNode;

typedef struct stack{
    int size;
    int top;
    int *arr;
}stk;

typedef struct liststack{
    int size;
    int top;
    ListNode **arr;
}liststk;


ListNode *makeNode();
ListNode *makelist(int n);
int pop(stk *s);
void push(stk *s,int val);
ListNode* listpop(liststk *s);
void listpush(liststk *s,ListNode *nd);
ListNode* traversenext(int n,ListNode* nd);
