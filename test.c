#include<stdio.h>
#include<stdlib.h>

void foo(int i);
void moo(int i);
int main(){
  int i,j,k;  
  j = 2;
  k = 3;
  i = 5;
foo(j);
  while (j != 0){
    j--;
    }
  while(k != 1){
    k--; 
    while(i > 4){
       if(j < k){
          j = k;
       }
       else if(j == k){
          k = j;
       }
       else{
          k = k;
       }
    i--;
    }
    i = 5;
  }
  i = j + k;
  if(i < i){
    i=i;
  }
  else if(j < j){
    j=j;
  }
  else{
    j=j;
  }
   if(i < i){
    i=i;
  }
  else if(j < j){
    j=j;
  }
  else{
    j=j;
  }
  
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


