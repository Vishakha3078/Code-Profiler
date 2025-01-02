#include"prof.h"

//pops out int from stack
int profiler_pop(profiler_stk *st){
    st -> top = (st -> top) - 1;
    return st -> arr[(st -> top) + 1];
}

//pushes int in stack
void profiler_push(profiler_stk *st,int val){
    if((st -> top)+1 == st -> size){
        st -> size = (st -> size) + 10;
        st = realloc(st, sizeof(int)*st ->size);
    }
    st -> top = st -> top + 1;
    st -> arr[st -> top] = val;
    return;
}

//pop out address of linked list node from stack
profiler_ListNode* profiler_listpop(profiler_liststk *st){
    st -> top = (st -> top) - 1;
    return st -> arr[(st -> top) + 1];
}

//pushes address of linked list node from stack
void profiler_listpush(profiler_liststk *st,profiler_ListNode *p){
    if((st -> top)+1 == st -> size){
        st -> size = (st -> size) + 10;
        st = realloc(st, sizeof(profiler_ListNode*)*st ->size);
    }
    st -> top = st -> top + 1;
    st -> arr[st -> top] = p;
    return;
}

//creates linked list node
profiler_ListNode* profiler_makeNode(){
    profiler_ListNode* nd = (profiler_ListNode*)malloc(sizeof(profiler_ListNode));
    nd -> next = NULL;
    nd -> val = 0;
    return nd;
}

//creates linked list of given size
profiler_ListNode* profiler_makelist(int n){ 
    profiler_ListNode* head = profiler_makeNode();
    profiler_ListNode* temp = head;
    while( n > 1){
        temp -> next = profiler_makeNode();
        temp = temp -> next;
        n--;
    }
    return head;
}

//traverses in linked list
profiler_ListNode* profiler_traversenext(int n,profiler_ListNode *nd){
    while(n > 0){
        nd = nd -> next;
        n--;
    }
    return nd;
}


