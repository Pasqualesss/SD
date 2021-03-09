#include <stdio.h>
#include <stdlib.h>
int fib(int k);

int main(){
    int k;
    scanf("%d", &k);
    printf("%d\n", fib(k));
    return 0;
}
//T(n) = O(1.6180)^n
int fib(int k){
    if(k <= 1){
        return 1; 
    }
    return fib(k-1) + fib(k-2);
}