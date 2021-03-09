#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long karatsuba(long long a, long long b);
int nrcifre(long long a);
int maxim(int num1, int num2);

int main(){
    long long a=12345678, b=1991321;
    printf("%lld\n", karatsuba(a,b));
    return 0;
}

long long karatsuba(long long a, long long b){
    long long a1, a2, b1, b2, pwr;
    int n1, n2, max, n;
    n1=nrcifre(a);
    n2=nrcifre(b);
    max=maxim(n1,n2);
    if(max<5){
        return a*b;
    }
    n=ceil(max/2);
    pwr=pow(10,n);
    a1=a/pwr;
    a2=a%pwr;
    b1=b/pwr;
    b2=b%pwr;
    long long p, q, r;
    p=karatsuba(a1,b1);
    q=karatsuba(a2,b2);
    r=karatsuba(a1+a2,b1+b2)-p-q;
    return pow(10,max)*p+pow(10,n)*r+q;
}

int nrcifre(long long a){
    int i=0;
    while(a!=0){
        a=a/10;
        i++;
    }
    return i;
}

int maxim(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}