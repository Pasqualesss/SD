#include <stdio.h>

int suma(int v[], int idx, int size);

int main(){
    int v[]={1,2,3,4,5,6,7,8,9,10,11,12,13,100000};
    int idx=0;
    int size = sizeof(v)/sizeof(v[0]);
    printf("%d\n", suma(v, idx, size));
    return 0;
}

int suma(int v[], int idx, int size){
    if(idx == size){
        return 0;
    }
    else{
        return v[idx] + suma(v, idx+1, size);
    }
}