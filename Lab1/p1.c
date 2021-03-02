#include <stdio.h>

int count(int v[], int find, int size, int idx);
int main(){
    int v[]={1,0,4,6,8,12,5,-4,6,2,4,4,4,4};
    int find, idx=0;
    int size = sizeof(v)/sizeof(v[0]);
    scanf("%d", &find);
    printf("%d\n", count(v, find, size, idx));
    return 0;
}

int count(int v[], int find, int size, int idx){
    if(size == idx){
        return 0;
    }
    else{
        if(v[idx] == find){
            return 1 + count(v, find, size, idx+1);
        }
        else{
            return count(v, find, size, idx+1);
        }
    }
}