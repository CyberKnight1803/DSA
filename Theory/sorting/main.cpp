#include<iostream>
#include"sorts.h"
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    bubbleSort(n, arr);

    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}