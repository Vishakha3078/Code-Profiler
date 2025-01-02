#include<stdio.h>
#define True 1
#define False 0

int main(void) {
    int i, isPrime;
    int pr[200], k = 4;
    pr[0] = 2;
    pr[1] = 3;
    pr[2] = 5;
    pr[3] = 7;
    int p = 9;
    int cnt = 4;
    
    while ( p < 1000 ) {
        isPrime = True;
        i = 0;
        while ( isPrime && i < k && pr[i]*pr[i] <= p ) {
            if(p % pr[i] == 0) {
                isPrime = False;
            }
            i = i + 1;
        }
        if(isPrime){
	    pr[k] = p;
            k++;
            cnt++;
        }
        p = p + 2;
    }
    return 0;
}


