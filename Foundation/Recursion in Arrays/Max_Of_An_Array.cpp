#include<bits/stdc++.h>
using namespace std;

int maxOfArray(int* a, int n){
    if(n==1) return a[0];

    int maxOfRestArray = maxOfArray(a+1,n-1);
    int currElement = a[0];
    
    return max(currElement, maxOfRestArray);
}

int main(){
    
    int n;
    cin>>n;

    int* a = new int[n];
    for(int i = 0; i<n; i++) cin>>a[i];

    int ans = maxOfArray(a,n);
    cout << ans << "\n";
}