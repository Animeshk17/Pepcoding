#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& a, int n){

    int ans = INT_MIN;

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k  = j+1; k<n; k++){
                ans = max(a[i] * a[j] * a[k] , ans);
            }
        }
    }

    return ans;
}

int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    int ans = maxProduct(a,n);
    cout << ans << "\n";
}