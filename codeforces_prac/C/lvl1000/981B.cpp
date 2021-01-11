#include<iostream>
#include<map>
using namespace std;

#define ll long long

int main(){
    ll n, m, maxIncome = 0;
    map<ll, ll>mp;
    ll index, income;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin>>index>>income;
        mp[index] = income;
    }    
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> index >> income;
        if(mp[index] < income){
            mp[index] = income;
        }
    }

    for(auto x : mp){
        maxIncome += x.second;
    }
    cout<<maxIncome;
}