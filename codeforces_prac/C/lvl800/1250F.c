#include<stdio.h>

int main(){
    int n; scanf("%d", &n);
    int pmin = 2*n + 2;
    int p;
    for(int i = 1; i <= n; ++i){
        if(n % i == 0){
            int x = n / i;
            p = 2 *(x + i); 
        }
        pmin = (pmin < p) ? pmin : p;
    }
    printf("%d", pmin);
}

