#include<bits/stdc++.h>
using namespace std;

char getMaxFreqCharacter(string& s){

    char ans;
    int maxFreq = -1;
    unordered_map<char, int> mp;
    
    for(char &c : s){
    
        mp[c]++;
    
        if(mp[c] > maxFreq){
            ans = c;
            maxFreq = mp[c];
        }
    
    }

    return ans;
}

int main(){

    string s;
    cin>>s;

    char maxFreqCharacter = getMaxFreqCharacter(s);
    cout << maxFreqCharacter << "\n";
}