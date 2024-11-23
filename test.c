#include<stdio.h>
#include<stdlib.h>

void foo(int i);
void moo(int i);
int main(){
  int i,j,k;  
  j = 2;
  k = 3;
foo(j);
  while (j != 0){
    j--;
    }
    if(j < k){
        j = k;
    }
    else if(j = k){
        k = j;
    }
    else{
        k = k;
    }
  i = j + k;
 moo(i);
  return 0;
}

void foo(int i){
    int j = 0;
    while(j < i){
        j++;
    }
}

void moo(int i){
    int j = 0;
    while(j < i){
        j++;
    }
}


