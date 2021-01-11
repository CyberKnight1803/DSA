#include<stdio.h>

void swap(int *a, int *b){
    int T = *a;
    *a = *b;
    *b = T;
}

int minMoves(int n, int a[]){
    int min = 0, flag = 0;
    for(int i = 0; i < n; ++i){
        if(i % 2 != a[i] % 2){
            flag = 1;
            for(int j = i + 1; j < n && flag; j += 2){
                if(j % 2 != a[j] % 2){
                    swap(&a[i], &a[j]);
                    ++min;
                    flag = 0;
                }
            }
        }
    }
    return (flag == 0) ? min : -1;
}

int main(){
    int a[40], n, t;
    scanf("%d\n", &t);
    int ans[1000];

    for(int i = 0; i < t; ++i){
        scanf("%d\n", &n);
        for(int j = 0; j < n; ++j){
            scanf("%d", &a[j]);
        }
        ans[i] = minMoves(n, a);
    }
    for(int i = 0; i < t; ++i){
        printf("%d\n", ans[i]);
    }
}


