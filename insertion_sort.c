#include<stdio.h>

int main(){
  int arr[] = {9,7,6,5,4,3,2,1};
  int n = 8;
  int temp,i,j;
  i = 1;
  while(i < n){
      temp = arr[i];
      j = i-1;
      while( j >= 0 && arr[j] > temp){
          arr[j+1] = arr[j];
          j--;
      }
      arr[j+1] = temp;
      i++;
  }
 return 0;
}
