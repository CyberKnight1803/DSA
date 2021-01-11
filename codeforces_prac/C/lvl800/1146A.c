#include<stdio.h>
#include<string.h>

int main(){
    char S[50]; scanf("%s", S);
    int f = 0;
    for(int i = 0; i < strlen(S); ++i){
        if(S[i] == 'a'){
            f++;
        }
    }
    if(f > strlen(S) / 2){
        printf("%d", strlen(S));
    }
    else{
        printf("%d", 2*f - 1);
    }
}