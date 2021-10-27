#include<bits/stdc++.h>
using namespace std;

vector<int> getProductArray(vector<int>& a, int n){
    
    vector<int> prefix(n);
    prefix[0] = a[0];

    for(int i = 1; i<n; i++){
        prefix[i] = a[i] * prefix[i-1];
    }


    vector<int> suffix(n);
    suffix[n-1] = a[n-1];

    for(int i = n-2; i>=0; i--){
        suffix[i] = a[i] * suffix[i+1];
    }

    vector<int> ans(n);
    ans[0] = suffix[1];
    ans[n-1] = prefix[n-2]; 

    for(int i = 1; i<n-1; i++){
        ans[i] = prefix[i-1] * suffix[i+1];
    }

    return ans;
}

void print(vector<int>& a){
    for(int &x : a) cout << x << " ";
    cout << "\n";
}

int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    vector<int> ans = getProductArray(a, n);
    print(ans);
}