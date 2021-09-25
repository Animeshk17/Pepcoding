#include<bits/stdc++.h>
using namespace std;

void getAllIndicesOfOccurence(vector<int>& a, int currIndex, int x, vector<int>& ans){
    
    if(currIndex == a.size()) return;

    if(a[currIndex] == x) ans.push_back(currIndex);
    
    getAllIndicesOfOccurence(a, currIndex+1, x, ans);

}

int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    int x;
    cin>>x;

    vector<int> ans;
    getAllIndicesOfOccurence(a,0,x,ans);

    for(int index : ans) cout << index << "\n";

}