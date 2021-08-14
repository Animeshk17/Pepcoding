#include<bits/stdc++.h>
using namespace std;

int getFibonacciTerm(int n){
    if(n==0 || n==1) return n;
    return getFibonacciTerm(n-1) + getFibonacciTerm(n-2);
}

int main(){
    
    int n;
    cin>>n;

    int ans = getFibonacciTerm(n);
    cout << ans << '\n';
}

//Time Complexity : O(2^n) [Exponential]
//Space Complexity : O(1) [Constant Space]
