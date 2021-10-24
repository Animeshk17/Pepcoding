#include<bits/stdc++.h>
using namespace std;

vector<int> getMajorityElement(vector<int>& a, int n){

    unordered_map<int,int> mp;
    for(int i = 0; i<n; i++) mp[a[i]]++;

    vector<int> ans;

    for(auto &p : mp){
        if(p.second > n/3){
            ans.push_back(p.first);
        }
    }

    return ans;
}


void print(vector<int> & a){
    
    int n = a.size();

    cout << "[";
    
    for(int i = 0; i<n; i++){
        
        if(i == n-1){
            cout << a[i];
            continue;
        }

        cout << a[i] << ", ";
    }
    
    cout << "]";

}


int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    vector<int> ans = getMajorityElement(a, n);
    sort(ans.begin(), ans.end());
    
    if(ans.empty()) cout << "No Majority Element exist" << "\n";
    else print(ans);

}