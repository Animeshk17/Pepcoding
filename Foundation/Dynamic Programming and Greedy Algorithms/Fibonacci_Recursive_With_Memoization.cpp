#include<bits/stdc++.h>
using namespace std;

int getFibonacciTerm(int n, vector<int>& alreadyFound){

    if(n==0 || n==1) return n;
    
    if(alreadyFound[n]) return alreadyFound[n];
    
    int ans = getFibonacciTerm(n-1,alreadyFound) + getFibonacciTerm(n-2,alreadyFound);
    alreadyFound[n] = ans;
    
    return ans;
}

int main(){
    
    int n;
    cin>>n;

    vector<int> alreadyFound(n+1,0);

    int ans = getFibonacciTerm(n,alreadyFound);
    cout << ans << '\n';
}

//Time Complexity : O(n) [Linear] Because we are calculating each term only once
//Space Complexity : O(n) [Linear] We Need an array to store our results