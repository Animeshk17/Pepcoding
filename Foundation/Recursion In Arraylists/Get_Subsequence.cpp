#include<bits/stdc++.h>
using namespace std;

vector<string> getSubsequences(string s){

    vector<string> ans;
    string blank;
    
    if(s.empty()){
        ans.push_back(blank);
        return ans;
    }

    vector<string> smallerAns = getSubsequences(s.substr(1,s.size()-1));
    
    for(auto x: smallerAns) ans.push_back(x);
    for(auto x: smallerAns) ans.push_back(s[0]+x);
    
    return ans;
    
}

int main(){

    string s;
    cin >> s;
    
    vector<string> ans = getSubsequences(s);
    int count = 0;

    cout << '[';
    for (string str : ans){
        if (count != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        count++;
    }
    cout << ']';
}