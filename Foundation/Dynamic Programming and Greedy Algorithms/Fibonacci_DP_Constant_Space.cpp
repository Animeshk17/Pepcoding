#include<bits/stdc++.h>
using namespace std;

int getNthFibonacciTerm(int n){
    
    if(n==0 || n==1) return n;
    
    int penultimate = 0;
    int prev = 1;
    int current;
    
    for(int i = 2; i<=n; i++){
        current = prev + penultimate;
        penultimate = prev;
        prev = current;
    }

    return current;
}

int main(){
    
    int n;
    cin>>n;

    int ans = getNthFibonacciTerm(n);
    cout << ans << '\n';
}

//Time Complexity : O(n) [Linear] Because we are calculating each term only once
//Space Complexity : O(1) [Constant Space] Because we are using only two integer variables