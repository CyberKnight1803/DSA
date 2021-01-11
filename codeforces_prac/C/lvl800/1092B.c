#include<stdio.h>

void sort(int n, int x[]){
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if(x[j] > x[j + 1]){
                int t = x[j];
                x[j] = x[j + 1];
                x[j + 1] = t;
            }
        }
    }
}

int main(){
    int n; scanf("%d", &n);
    int arr[n], minProbs = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
    sort(n, arr);

    for(int i = 0; i < n; i += 2){
        minProbs += arr[i + 1] - arr[i];
    }
    printf("%d", minProbs);
}

