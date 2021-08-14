#include<bits/stdc++.h>
using namespace std;

int getNthFibonacciTerm(int n){
    
    int* fibonacciTerms = new int[n+1];

    fibonacciTerms[0] = 0;
    fibonacciTerms[1] = 1;

    for(int i = 2; i<=n; i++){
        fibonacciTerms[i] = fibonacciTerms[i-1] + fibonacciTerms[i-2];
    }

    int ans = fibonacciTerms[n];
    delete[] fibonacciTerms;
    return ans;
}

int main(){
    
    int n;
    cin>>n;

    int ans = getNthFibonacciTerm(n);
    cout << ans << '\n';
}

//Time Complexity : O(n) [Linear] Because we are calculating each term only once
//Space Complexity : O(n) [Linear] We Need an array to store our results