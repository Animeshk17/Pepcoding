#include<bits/stdc++.h>
using namespace std;

int getLargestSubarrayWithZeroSum(vector<int>& a, int n){
    
    unordered_map<int,int> mp;

    int currSubarraySum = 0;
    int maxSubarrayLengthWithZeroSum = 0;
    mp[currSubarraySum] = -1;

    for(int i = 0; i<n; i++){
        
        currSubarraySum += a[i];
        if(mp.find(currSubarraySum) != mp.end()){
            maxSubarrayLengthWithZeroSum = max(maxSubarrayLengthWithZeroSum, i - mp[currSubarraySum]);
        }else{
            mp[currSubarraySum] = i;
        }
    }

    return maxSubarrayLengthWithZeroSum;
}


int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) {
        cin>>a[i];
    }

    int ans = getLargestSubarrayWithZeroSum(a, n);
    cout << ans << "\n";
}