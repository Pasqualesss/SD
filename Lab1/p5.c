#include <stdio.h>

float pwr(float nr, int exp);

int main(){
    float nr;
    int exp;
    scanf("%f %d", &nr, &exp);
    if(exp > 0){
        printf("%.2f\n", pwr(nr, exp));
    }
    else{
        printf("%f\n", 1/pwr(nr, exp));
    }
    return 0;
}

float pwr(float nr, int exp){
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