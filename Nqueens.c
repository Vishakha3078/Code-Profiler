#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void pmat(int **mat ,int n){
    int i=0;
    int j=0;
    while(i<n){
        j=0;
        while(j<n){
            printf("%d ",mat[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

bool issafe(int** board,int n,int x,int y,int cnt){
    int i=x;
    int j=y;
    cnt++;
    while(i>=0){
        if(board[i][j]==1){
            return false;
        }
        i--;
    }
    i=x;
    while(j>=0){
        if(board[i][j]==1){
            return false;
        }
        j--;
    }
    j=y;
    while(i>=0 && j>=0){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j--;
    }
    i=x;
    j=y;
    while(i>=0 && j<n){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void nqueen_helper(int **board,int n, int i,int toput,int sol){
    if(toput == 0) {
        pmat(board,n);
        sol++;
        return ;
    }
    if(i==n)return;
    int j=0;
    while(j<n){
        if(issafe(board,n,i,j,0)){
            board[i][j]=1;
            nqueen_helper(board,n,i+1,toput-1,sol);
            board[i][j]=0;
        }
        j++;
    }
    return ;
}

void nqueen(int n){
    int **board = malloc(sizeof(int*)*n);
    int i = 0;
    while(i<n){
        board[i]=malloc(sizeof(int)*n);
        i++;
    }
    nqueen_helper(board,n,0,n,0);
}


int main(){
    int n = 5;
    nqueen(n);
    return 0;
}
