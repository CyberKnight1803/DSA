#include<iostream>
#include<unordered_map>

using namespace std;

int minSum(int n, int arr[]){
    unordered_map<int, int> mp;
    int sum = 0, min = 0;

    for(int i = 0; i < n; ++i){
        min += arr[i];
    }

    for(int i = 0; i < n; ++i){
        ++mp[arr[i]];
    }
    for(auto x : mp){
        if(x.second == 2 || x.second == 3){
            sum = (sum > x.first * x.second) ? sum : x.first * x.second;
        }
        else if(x.second > 3){
            sum = (sum > x.first * 3) ? sum : x.first * 3;
        }
    }
    return min - sum;
}

int main(){
    int a[5];
    for(int i = 0; i < 5; ++i){
        cin>>a[i];
    }
    cout<<minSum(5, a);
}


