#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void ps(char * s){
    int i=0;
    while(1){
        if(s[i]=='\0') {
            return ;
        }
        i++;
    }
}
void rotate(char* str, int n){
    int i=0;
    char tmp=str[0];
    while(i<n-1){
        str[i]=str[i+1];
        i++;
    }
    str[n-2]=tmp;
}


int main(){
    char c[]="this is some text@";
    int n=sizeof(c);
    int i=0;
    char str[n-1][n];
    while(i<n-1){
        strcpy(str[i],c);  
        ps(str[i]);
        rotate(c,n);
        i++;
    }
    char tmp[n];
    while(i<=n){
        int j = i+1;
        while(j<=n){
            if(strcmp(str[i],str[j])>0){
                strcpy(tmp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],tmp);
            }
            j++;
        }
        i++;
    }
    i=0;
    while(i<n){
        ps(str[i]);
        i++;
    }
    i=0;
    while(i<n){
        i++;
    }
    return 0;
}

