#include<bits/stdc++.h>
using namespace std;

int waysToClimb(int* arr, int n){

    int* waysToClimbStairsFrom = new int[n+1];
    waysToClimbStairsFrom[n] = 1;

    for(int i = n-1; i>=0; i--){

        waysToClimbStairsFrom[i] = 0;
        
        int j = 1;
        while(j<=arr[i] && (i+j)<=n){
            
            waysToClimbStairsFrom[i] += waysToClimbStairsFrom[i+j];
            j++;
        
        }
    }

    int ans = waysToClimbStairsFrom[0];
    delete[] waysToClimbStairsFrom;
    return ans;
}


int main(){
    
    int n;
    cin>>n;

    int* arr = new int[n];
    for(int i = 0; i<n; i++) cin>>arr[i];

    int ans = waysToClimb(arr,n);
    cout << ans << '\n';

}