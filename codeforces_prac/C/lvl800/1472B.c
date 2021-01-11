#include<stdio.h>

int ifPossible(int n, int x[]){
    int r1 = 0, r2 = 0, sum = 0;
    for(int i = 0; i < n; ++i){
        sum += x[i];
        if(x[i] == 1) ++r1;
        else ++r2;
    }
    if(sum % 2){
        return 0;
    }
    else{
        if(r2 % 2 == 1 && r1 != 0){
            return (r1 % 2) ? 0 : 1;
        }
        else if (r2 % 2 == 1 && r1 == 0) return 0;
        else return 1;
    }
}

int main(){
    int t, n; scanf("%d", &t);
    int a[100];
    int ans[t];
    for(int i = 0; i < t; ++i){
        scanf("%d", &n);
        for(int j = 0; j < n; ++j){
            scanf("%d", &a[j]);
        }
        ans[i] = ifPossible(n, a);
    }
    for(int i = 0; i < t; ++i){
        if(ans[i]) printf("YES\n");
        else printf("NO\n");
    }
}

