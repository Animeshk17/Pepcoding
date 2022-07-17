#include<bits/stdc++.h>
using namespace std;

int getCountOfSubarraysWithZeroSum(vector<int>& a, int n){
    
    unordered_map<int,int> frequencyMap;
    
    int currSubarraySum = 0;
    int count = 0;

    for(int i = 0; i<n; i++){
        
        currSubarraySum += a[i];

        count += frequencyMap[currSubarraySum];
        frequencyMap[currSubarraySum]++;
        
    }

    return count;
}


int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) {
        cin>>a[i];
    }

    int ans = getCountOfSubarraysWithZeroSum(a, n);
    cout << ans << "\n";
}