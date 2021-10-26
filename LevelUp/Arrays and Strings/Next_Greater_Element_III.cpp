#include<bits/stdc++.h>
using namespace std;

string nextGreaterNumber(string s){
    
    string ans;
    int n = s.size();

    int i = n-2;
    while(i >= 0 && s[i] >= s[i+1]){
        i--;
    }

    if(i == -1) return "-1";

    int j = n-1;
    while(s[i] >= s[j]){
        j--;
    }

    swap(s[i],s[j]);    
    int criticalPoint = i+1;

    reverse(s.begin() + criticalPoint, s.end());
    return s;

}

int main(){

    string s;
    cin>>s;

    string ans = nextGreaterNumber(s);
    cout << ans << "\n";

}