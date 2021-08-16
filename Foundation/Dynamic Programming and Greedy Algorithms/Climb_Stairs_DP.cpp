#include<bits/stdc++.h>
using namespace std;

int waysToClimb(int n){
    
    int* waysToClimbStairs = new int[n+1];
    waysToClimbStairs[0] = 1;
    waysToClimbStairs[1] = 1;
    waysToClimbStairs[2] = 2;

    for(int i = 3; i<=n; i++){
        waysToClimbStairs[i] = waysToClimbStairs[i-1] + waysToClimbStairs[i-2] + waysToClimbStairs[i-3];
    }

    int ans = waysToClimbStairs[n];
    delete[] waysToClimbStairs;
    return ans;
}

int main(){
    
    int n;
    cin>>n;

    int ans = waysToClimb(n);
    cout << ans << '\n';

}