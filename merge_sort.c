#include<stdio.h>
#include<stdlib.h>

void merge(int* a, int l, int m, int r){
    int i, j , k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = malloc(sizeof(int)*n1), *R = malloc(sizeof(int)*n2);
    i = 0;

    while(i<n1){
        L[i] = a[l+i];
        i++;
    }
    i = 0;
    while(i<n2){
        R[i] = a[m+1+i];
        i++;
  }
    i=0;
    j=0;
    k=l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int* a, int l,int r){
    if(l<r){
        int m = l+ (r-l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    int a[]={1,2,3,4,5,6};
    int n= sizeof(a)/sizeof(a[0]);
    mergeSort(a,0,n-1);
    return 0;
}
