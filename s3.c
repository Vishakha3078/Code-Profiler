#include<stdio.h>
#define True 1
#define False 0

int main(void) {
    int p = 2;
    int i, isPrime;
    int cnt = 1;
    while ( p < 1000 ) {
        isPrime = True;
        if (p % 2 == 0) {
            isPrime = False;
        }
        i = 3;
        while ( isPrime && i*i <= p ) {
            if(p % i == 0) {
                isPrime = False;
            }
            i = i + 2;
        }
        if(isPrime){
            cnt++;
        }
        p = p + 1;
    }
    return 0;
}


