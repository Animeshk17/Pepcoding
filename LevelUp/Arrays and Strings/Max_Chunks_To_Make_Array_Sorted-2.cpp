#include<bits/stdc++.h>
using namespace std;

int maxChunks(vector<int>& a, int n){
    
    int chunks = 0;
    
    vector<int> minmToTheRight(n+1);
    minmToTheRight[n] = INT_MAX;

    for(int i = n-1; i>=0; i--){
        minmToTheRight[i] = min(minmToTheRight[i+1], a[i]);
    }

    int maxSoFar = INT_MIN;
    for(int i = 0; i<n; i++){
        maxSoFar = max(maxSoFar, a[i]);
        if(maxSoFar <= minmToTheRight[i+1]) chunks++;
    }

    return chunks;
}

int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    int ans = maxChunks(a,n);
    cout << ans << "\n";    
}