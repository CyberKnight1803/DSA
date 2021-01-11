#include<stdio.h>

int main(){
    int t; scanf("%d", &t);

    long long a, b;
    long long ans[t];

    for(int i = 0; i < t; ++i){
        scanf("%lld %lld", &a, &b);
        ans[i] = (a % b) ? (b - (a % b)) : 0; 
    }

    for(int i = 0; i < t; ++i){
        printf("%lld\n", ans[i]);
    }
}

