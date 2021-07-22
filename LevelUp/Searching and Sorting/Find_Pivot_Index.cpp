#include<bits/stdc++.h>
using namespace std;

int findPivotIndex(int* arr, int n){

    int* prefixSum = new int[n];
    prefixSum[0] = arr[0];

    for(int i = 1; i<n; i++){
        prefixSum[i] = arr[i] + prefixSum[i-1];
    }

    int totalArraySum = prefixSum[n-1];
    int ans = -1;
    
    if(totalArraySum-arr[0]==0) return 0;
    
    for(int i = 1; i<n; i++){
        int leftSum = prefixSum[i] - arr[i];
        int rightSum = totalArraySum - prefixSum[i];
        if(leftSum==rightSum){
            ans = i;
            break;
        }
    }

    return ans;
}


int main(){
    int n;
    cin>>n;

    int* a = new int[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    int pivotIndex = findPivotIndex(a,n);

    cout << pivotIndex << '\n';
}