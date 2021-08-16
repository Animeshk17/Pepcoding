#include<bits/stdc++.h>
using namespace std;

int waysToClimb(int* arr, int n){
    
    if(n < 0) return 0;
    else if(n==0) return 1;

    int currJumpLength = arr[0];
    int totalWaysToClimb = 0;
    
    for(int i = 1; i<=currJumpLength; i++){
        totalWaysToClimb += waysToClimb(arr+i,n-i);
    }

    return totalWaysToClimb;
}

int main(){
    
    int n;
    cin>>n;

    int* arr = new int[n];
    for(int i = 0; i<n; i++) cin>>arr[i];

    int ans = waysToClimb(arr,n);
    cout << ans << '\n';

}