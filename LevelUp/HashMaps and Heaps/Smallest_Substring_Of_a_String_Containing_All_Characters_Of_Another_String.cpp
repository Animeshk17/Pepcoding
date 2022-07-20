#include<bits/stdc++.h>
using namespace std;

string getSmallestSubstringContainingAllCharactersOfAnotherString(string& s, string& p){
    
    if(s.size()<p.size()) {

        string blank;
        return blank;
    
    }
    
    unordered_map<char,int> hash_pat;
    
    for(char c: p) {
        hash_pat[c]++;
    }
    
    unordered_map<char,int> mp;

    string ans;
    
    int matchCount = 0;
    int i = -1;
    int j = -1;
    
    while(true){

        bool flag1 = false;
        bool flag2 = false;
        int n = s.size()-1;

        
        while(i<n && matchCount<p.size()) {
            i++;
            mp[s[i]]++;
            if(mp[s[i]]<=hash_pat[s[i]]) matchCount++;
            flag1  = true;
        }
        
        
        while(j<i && matchCount == p.size()) {

            string currAns = s.substr(j+1,i-j);
            
            if(ans.size()==0 || currAns.size()<ans.size()) {
                ans = currAns;
            }
            
            j++;
            char ch  = s[j];
            
            if(mp[ch]==1) {
                mp.erase(ch);
            }else {
                mp[ch]--;
            }

            if(hash_pat[s[j]] > mp[s[j]]) {
                matchCount--;
            }

            flag2 = true;
        }
        
        if(flag1 == false && flag2 == false) break;
    }

    return ans;
}

int main(){

    string s,pat;
    cin>>s>>pat;

    string ans = getSmallestSubstringContainingAllCharactersOfAnotherString(s,pat);
    cout << ans << "\n";

}