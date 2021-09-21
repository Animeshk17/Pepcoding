#include<bits/stdc++.h>
using namespace std;

int minMovesToClimb(int* arr, int index, int n){
    
    if(index > n) return INT_MAX;
    if(index == n) return 0;
    
    int currJumpLength = arr[0];
    int ans = INT_MAX-1;

    for(int i = 1; i <= currJumpLength; i++){
        ans = min(minMovesToClimb(arr,i,n),ans);
    }
    
    return ans;
}



int main(){
    
    int n;
    cin>>n;

    int* arr = new int[n+1];
    for(int i = 1; i<=n; i++) cin>>arr[i];

    int ans = minMovesToClimb(arr,0,n);
    cout << ans << '\n';

}