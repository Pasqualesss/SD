#include <stdio.h>
#include <stdlib.h>
int fib_mem(int *res, int k);

int main(){
    int k, *res;
    scanf("%d", &k);
    res = malloc(sizeof(int)*k);
    //Primele doua elemente sunt cunoscute.
    int i;
    res[0] = 0;
    res[1] = 1;
    //Umplem restul vectorului cu -1.
    for(i=2;i<k;i++){
        res[i] = -1;
    }
    printf("%d\n", fib_mem(res, k-1));
    free(res);
    return 0;
}

int fib_mem(int *res, int k){
    if(res[k] == -1){
        res[k] = fib_mem(res, k-1) + fib_mem(res, k-2);
    }
    return res[k];
}