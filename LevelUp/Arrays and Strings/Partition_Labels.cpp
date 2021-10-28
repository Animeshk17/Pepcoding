#include<bits/stdc++.h>
using namespace std;

vector<int> getPartitions(string& s){

    int n = s.size();
    vector<int> ans;
    unordered_map<char, int> mp;
    
    for(int i = 0; i<n; i++) mp[s[i]] = i;

    int start = 0; 
    int stop = mp[s[0]];

    while(start < n && stop < n){
    
        int i = start;

        while(start < n && start < stop){
            start++;
            stop = max(stop, mp[s[start]]);
        }

        ans.push_back(stop+1 - i);
        start++;
        stop = mp[s[start]];
  
    }

    return ans;
}

int main(){

    string s;
    cin>>s;

    vector<int> ans = getPartitions(s);
    for(int partitionLength : ans ) cout << partitionLength << " ";
}