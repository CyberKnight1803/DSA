#include<stdio.h>

void sort(long n, long x[]){
    for(long i = 0; i < n - 1; ++i){
        for(long j = 0; j < n - i - 1; ++j){
            if(x[j] > x[j + 1]){
                long T = x[j];
                x[j] = x[j + 1];
                x[j + 1] = T;
            }
        }
    }
}

int minClasslvl(long n, long a[]){
    sort(n, a);
    return a[n/2] - a[n/2 - 1];
}

int main(){
    int t; scanf("%d", &t);
    long n, a[200000];
    int ans[10000];

    for(int i = 0; i < t; ++i){
        scanf("%ld", &n);
        for(long j = 0; j < 2*n; ++j){
            scanf("%ld", &a[j]);
        }
        ans[i] = minClasslvl(2*n, a);
    }
    for(int i = 0; i < t; ++i){
        printf("%d\n", ans[i]);
    }
}