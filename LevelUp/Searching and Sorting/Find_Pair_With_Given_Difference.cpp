#include<bits/stdc++.h>
using namespace std;

void printPairs(set<pair<int,int>>& pairs){
    for(auto pair : pairs){
        cout << pair.first << " " << pair.second << '\n';
    }
}

void findPairsWithDifferenceK(int* a, int n, int k){
    unordered_map<int,int> mp;
    for(int i = 0; i<n; i++) mp[a[i]]++;

    set<pair<int,int>> pairs;
    
    for(int i = 0; i<n; i++){
        int currVal = a[i];
        int required1 = a[i] - k;
        int required2 = k + a[i];

        if(mp.find(required1)!=mp.end()){
            pairs.insert(make_pair(min(required1,currVal),max(required1,currVal)));       
        }
        
        if(mp.find(required2)!=mp.end() && k!=0){
            pairs.insert(make_pair(min(required2,currVal),max(required2,currVal)));
        }

    }

    if(!pairs.empty()) printPairs(pairs);
    else cout << -1 << '\n';
}

int main(){
    int n;
    cin>>n;

    int* a = new int[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    int k;
    cin>>k;

    findPairsWithDifferenceK(a,n,k);
}