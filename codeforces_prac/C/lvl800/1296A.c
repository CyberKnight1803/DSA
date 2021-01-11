#include<stdio.h>

int checkSum(int n, int a[]){
    long long sum = 0;
    int r1 = 0, r2 = 0;

    for(int i = 0; i < n; ++i){
        sum += a[i];
        if(a[i] % 2) ++r1;
        else ++r2;
    }
    if(sum % 2) return 1;
    else{
        return (r2 && r1)? 1 : 0;
    }
}

int main(){
    int n, t; scanf("%d", &t);
    int a[2000];
    int ans[t];
    for(int i = 0; i < t; ++i){
        scanf("%d", &n);
        for(int j = 0; j < n; ++j){
            scanf("%d", &a[j]);
        }
        ans[i] = checkSum(n, a);
    }
    for(int i = 0; i < t; ++i){
        if(ans[i]) printf("YES\n");
        else printf("NO\n");
    }
}