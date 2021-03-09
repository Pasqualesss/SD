#include <stdio.h>

int find(int* v, int ac, int size);
int bsearch(int *v, int left, int right, int ac);
int main(){
    int v[]={6,7,8,1,2,3,4,5}, ac, size, aux;
    size=sizeof(v)/sizeof(v[0]);
    scanf("%d", &ac);
    aux=find(v, ac, size-1);
    if(aux!=-1){
        printf("Numarul se gaseste in vector la indexul: %d.\n", aux);
    }
}

int find(int* v, int ac, int size){
    int left=0, right=size, middle, idx;
    while(v[left]<v[left+1]){
        left++;
    }
    //Daca e mai mare decat cel mai mare element din a 2 a jumatate, cauta in prima jumatate.
    middle=left;
    left=0;
    if(ac>v[right]){
        idx=bsearch(v,left,middle,ac);
    }
    else{
        idx=bsearch(v,middle+1,right,ac);
    }
    return idx;
}

int bsearch(int *v, int left, int right, int ac){
    int middle;
    middle=(left+right)/2;
    if(ac == v[middle]){
        return middle;
    }
    else if(left>right){
        return -1;
    }
    else{
        if(v[middle]<ac){
            return bsearch(v, middle+1, right, ac);
        }
        else{
            return bsearch(v,left, middle-1,ac);
        }
    }
}