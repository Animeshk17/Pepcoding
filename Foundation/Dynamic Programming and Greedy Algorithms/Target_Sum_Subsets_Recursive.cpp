#include<bits/stdc++.h>
using namespace std;

bool getTargetSubsetSum(int* arr, int n, int index, int currSubsetSum, int target){
    if(index == n){                                                                          //We have reached the end of the array. Hence we have a subset
        if(currSubsetSum == target){
            return true;
        }
        return false;
    }

    bool include = getTargetSubsetSum(arr, n, index+1, currSubsetSum+arr[index], target);   //We include the current element in the subset
    bool exclude = getTargetSubsetSum(arr, n, index+1, currSubsetSum, target);              //We don't include the current element in the subset

    if(include || exclude) return true;
    return false;
}

int main(){
    
    int n;
    cin>>n;

    int* arr = new int[n];
    for(int i = 0; i<n; i++) cin>>arr[i];

    int target;
    cin>>target;

    bool gotIt = getTargetSubsetSum(arr, n, 0, 0, target);

    if(gotIt) cout << "true" << '\n';
    else cout << "false" << '\n';
    
}