/* 
        Exceeds time limit
 */

#include<stdio.h>

struct element{
    long long index;
    long long income;
};

void sort(int n, struct element a[]){
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if(a[j].index > a[j + 1].index){
                struct element t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}


long long max(int n, struct element a[], int m, struct element b[]){
    sort(n, a); sort(m, b);
    long long maxIncome = 0;
    int  i = 0, j = 0;
    while(i < n && j < m){
        if(a[i].index > b[j].index){
            maxIncome += b[j].income;
            j++;
        }
        else if (a[i].index < b[j].index){
            maxIncome += a[i].income;
            i++;
        }
        else{
            maxIncome += (a[i].income >= b[j].income) ? a[i].income : b[j].income;
            i++;
            j++;
        }   
    }
    while(i < n){
        maxIncome += a[i].income;
        i++;
    }
    while(j < m){
        maxIncome += b[j].income;
    }
    return maxIncome;
}

int main(){
    int n, m;
    scanf("%d", &n); struct element a[n];
    for(int i = 0; i < n; ++i){
        scanf("%lld %lld", &a[i].index, &a[i].income);
    }
    scanf("%d", &m); struct element b[m];
    for(int i = 0; i < m; ++i){
        scanf("%lld %lld", &b[i].index, &b[i].income);
    }
    printf("%lld", max(n, a, m, b));
}

