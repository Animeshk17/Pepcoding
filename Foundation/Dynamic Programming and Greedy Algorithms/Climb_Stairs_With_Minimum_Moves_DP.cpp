#include<bits/stdc++.h>
using namespace std;

int minMovesToClimb(int* arr, int n){

    int* dp = new int[n+1];
    dp[n] = 0;

    for(int i = n-1; i>=0; i--){

        dp[i] = INT_MAX-1;
        int currJumpLength = arr[i];
        
        for(int j = i+1; j <= min(n,i+currJumpLength); j++){
            dp[i] = min(dp[i],dp[j]);
        }

        dp[i] += 1;
    }
    
    return dp[0];
}


int main(){
    
    int n;
    cin>>n;

    int* a = new int[n];
    for(int i = 0; i<n; i++) cin>>a[i];

    int ans = minMovesToClimb(a,n);
    cout << ans << '\n';
}