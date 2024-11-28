#include"prof.h"

int pop(stk *st){
    st -> top = (st -> top) - 1;
    return st -> arr[(st -> top) + 1];
}

void push(stk *st,int val){
    if((st -> top)+1 == st -> size){
        st -> size = (st -> size) + 10;
        st = realloc(st, sizeof(int)*st ->size);
    }
    st -> top = st -> top + 1;
    st -> arr[st -> top] = val;
    return;
}

ListNode* listpop(liststk *st){
    st -> top = (st -> top) - 1;
    return st -> arr[(st -> top) + 1];
}

void listpush(liststk *st,ListNode *p){
    if((st -> top)+1 == st -> size){
        st -> size = (st -> size) + 10;
        st = realloc(st, sizeof(ListNode*)*st ->size);
    }
    st -> top = st -> top + 1;
    st -> arr[st -> top] = p;
    return;
}

ListNode* makeNode(){
    ListNode* nd = (ListNode*)malloc(sizeof(ListNode));
    nd -> next = NULL;
    nd -> val = 0;
    return nd;
}

ListNode* makelist(int n){ 
    ListNode* head = makeNode();
    ListNode* temp = head;
    while( n > 1){
        temp -> next = makeNode();
        temp = temp -> next;
        n--;
    }
    return head;
}

ListNode* traversenext(int n,ListNode *nd){
    while(n > 0){
        nd = nd -> next;
        n--;
    }
    return nd;
}


