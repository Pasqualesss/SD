#include <stdio.h>

float radical(float n, float l, float r);

int main(){
    float n;
    scanf("%f", &n);
    printf("%.3f\n", radical(n, 0, 100));
    return 0;
}

float radical(float n, float l, float r){
    float aux, eps=0.001;
    aux = (l+r)/2;
    if(aux*aux == n){
        return aux;
    }
    if((aux*aux > n-eps) && (aux*aux < n+eps)){
        return aux;
    }
    if(aux*aux > n){
        r=aux;
        return radical(n, l, aux);
    }
    else{
        l=aux;
        return radical(n, aux, r);
    }
}