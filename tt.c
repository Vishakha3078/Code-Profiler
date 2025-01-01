
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int array[]={97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,95,48,49,50,51,52,53,54,55,56,57};
  char *string = malloc(sizeof(char)*31);
  int j = 0;
  int val;
  srand(time(NULL));
  val = rand();
  val = val%53;
  string[j++] =(char)array[val]; 
  for(int i = 1; i < 31; i++){
      val = rand();
      val = val%63;
      string[j++] =(char)array[val]; 
  }
    printf("string = %s\n", string);
 return 0;    
}
