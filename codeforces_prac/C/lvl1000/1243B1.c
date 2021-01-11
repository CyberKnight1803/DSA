#include<stdio.h>
#include<string.h>

void swap(char *a, char *b){
    char t = *a;
    *a = *b;
    *b = t;
}

void checkS(int n, char a[], char b[]){
    int f = 1;
    for(int i = 0; i < n; ++i){
        if(a[i] != b[i]){
            for(int j = i + 1; j < n && f; ++j){
                if(a[j] != b[j]){
                    swap(&a[i], &b[j]);
                    f = 0;
                }
            }
        }
    }
    strcmp(a, b)? printf("No\n"): printf("Yes\n");
}

int main(){
    int n, t; scanf("%d", &t);
    for(int i = 0; i < t; ++i){
        scanf("%d\n", &n);
        char a[n + 1], b[n + 1];
        for(int j = 0; j < n; ++j){
            scanf("%c", &a[j]);
        }
        scanf("\n");
        a[n] = '\0';
        for(int j = 0; j < n; ++j){
            scanf("%c", &b[j]);
        }
        b[n] = '\0';
        checkS(n, a, b);
    }
}

