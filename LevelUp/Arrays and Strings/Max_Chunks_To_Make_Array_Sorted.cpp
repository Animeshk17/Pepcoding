#include<bits/stdc++.h>
using namespace std;

int maxChunks(vector<int>& a, int n){

    int maxIndexOfImpact = -1;
    int chunks = 0;

    for(int i = 0; i<n; i++){
        maxIndexOfImpact = max(maxIndexOfImpact , a[i]);
        if(maxIndexOfImpact == i) chunks++;
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