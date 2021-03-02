#include <stdio.h>

int fibonacci(int k);

int main(){
    int k;
    scanf("%d", &k);
    printf("%d\n", fibonacci(k));
    return 0;
}

int fibonacci(int k){
    if(k == 0){
        return 0; 
    }
    else if(k == 1){
        return 1;
    }
    else{
        return fibonacci(k-1) + fibonacci(k-2);
    }
}