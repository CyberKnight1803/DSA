#include<stdio.h>

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

void sort(int n, int x[]){
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if(x[j] > x[j + 1]){
                swap(&x[j], &x[j+1]);
            }
        }
    }
}

void sortD(int n, int x[]){
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if(x[j] < x[j + 1]){
                swap(&x[j], &x[j+1]);
            }
        }
    }
}


int maxSum(int n, int a[], int b[], int k){
    sort(n, a); sortD(n, b);
    int sum = 0, i = 0;
    while(k != 0 && i < n){
        if(a[i] < b[i]){
            swap(&a[i], &b[i]);
            k--;
        }
        sum += a[i];
        ++i;
    }
    while(i < n){
        sum += a[i];
        ++i;
    }
    return sum;
}


int main(){
    int t; scanf("%d", &t);
    int n, k;
    int a[30], b[30], ans[200];
    
    for(int i = 0; i < t; ++i){
        scanf("%d %d", &n, &k);
        for(int j = 0; j < n; ++j){
            scanf("%d", &a[j]);
        }
        for(int j = 0; j < n; ++j){
            scanf("%d", &b[j]);
        }
        ans[i] = maxSum(n, a, b, k);
    }
    
    for(int i = 0; i < t; ++i){
        printf("%d\n",ans[i]);
    }
}

