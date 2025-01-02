#include<stdio.h>
#define True 1
#define False 0

int main(void) {
    int i, isPrime;
    int p = 7;
    int cnt = 4;
    
    while ( p < 1000 ) {
        isPrime = True;
        if (p % 3 == 0 || p % 5 == 0 || p % 7 == 0) {
            isPrime = False;
        }
        i = 7;
        while ( isPrime && i*i <= p ) {
            if(p % i == 0) {
                isPrime = False;
            }
            i = i + 2;
        }
        if(isPrime){
            cnt++;
        }
        p = p + 2;
    }
    return 0;
}


