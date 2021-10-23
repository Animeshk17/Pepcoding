#include<bits/stdc++.h>
using namespace std;

int getMajorityElement(vector<int>& a, int n){

    unordered_map<int,int> mp;
    for(int i = 0; i<n; i++) mp[a[i]]++;

    for(auto &p : mp){
        if(p.second > n/2){
            return p.first;
        }
    }

    return INT_MIN;
}

int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    int ans = getMajorityElement(a, n);
    
    if(ans == INT_MIN) cout << "No Majority Element exist" << "\n";
    else cout << ans << "\n";

}