#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindrom(char *s, int start, int end);

int main(){
    char s[100];
    scanf("%s", s);
    int start = 0;
    int end = strlen(s)-1;
    if(palindrom(s, start, end) == 0){
        printf("Este palindrom\n");
    }
    else{
        printf("Nu este palindrom\n");
    }
}

int palindrom(char *s, int start, int end){
    if(start == end){
        return 0;
    }
    else if(start == end-1){
        return 0;
    }
    if(tolower(s[start]) == tolower(s[end])){
        return palindrom(s, start+1, end-1);
    }
    else{
        return -1;
    }
}