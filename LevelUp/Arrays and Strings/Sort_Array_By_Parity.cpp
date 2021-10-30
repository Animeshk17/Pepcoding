#include<bits/stdc++.h>
using namespace std;

void sortByParity(vector<int>& a, int n){
    
    vector<int> evens;
    vector<int> odds;

    for(int &x : a){
        if(x&1) odds.push_back(x);
        else evens.push_back(x);
    }

    a.clear();
    for(int &x : evens) a.push_back(x);
    for(int &x : odds) a.push_back(x);

    return;
}

void print(vector<int>& a){
    for(int &element : a){cout << element << " ";}
}

int main(){
    
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    sortByParity(a,n);
    print(a);
}