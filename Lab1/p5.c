#include <stdio.h>

int pwr(int nr, int exp);

int main(){
    int nr, exp;
    scanf("%d %d", &nr, &exp);
    printf("%d\n", pwr(nr, exp));
    return 0;
}

int pwr(int nr, int exp){
    if(exp == 1){
        return nr;
    }
    else if(exp == 2){
        return nr*nr;
    }
    else if(exp == 0){
        return 1;
    }
    else{
        if(exp%2 == 0){
            return pwr(nr, exp/2)*pwr(nr, exp/2);
        }
        else{
            return pwr(nr, exp/2)*pwr(nr, exp/2)*nr;
        }
    }
}