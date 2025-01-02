#include<stdio.h>
#define True 1
#define False 0

int main(){
    int p = 2;
    int i, isPrime;
    while ( p < 1000 ) {
        isPrime = True;
        i = 2;
        while ( isPrime && i < p ) {
            if(p % i == 0) {
                isPrime = False;
            }
            i = i + 1;
        }
        if(isPrime) {
            printf("%d ", p);
        }
        p = p + 1;
    }
    return 0;
}


