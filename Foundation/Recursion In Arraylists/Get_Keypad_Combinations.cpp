#include<bits/stdc++.h>
using namespace std;

vector<string> getKeypadCombinations(string s){
    
    unordered_map<char,string> keyMap;
    
    keyMap['0'] = ".;";
    keyMap['1'] = "abc";
    keyMap['2'] = "def";
    keyMap['3'] = "ghi";
    keyMap['4'] = "jkl";
    keyMap['5'] = "mno";
    keyMap['6'] = "pqrs";
    keyMap['7'] = "tu";
    keyMap['8'] = "vwx";
    keyMap['9'] = "yz";
    
    int len = s.size();
    
    vector<string> ans;
    string blank;
    
    if(len<0){
        ans.push_back(blank);
        return ans;
    }
    
    if(len==1){
        for(char x: keyMap[s.at(0)]){
            ans.push_back(blank+x);
        }
        return ans;
    }

    vector<string> smallerAns = getKeypadCombinations(s.substr(1));
    string firstKey = keyMap[s.at(0)];
    
    for(auto x: smallerAns){
        for(auto y: firstKey){
            ans.push_back(y+x);
        }
    }
    
    return ans;

}

int main(){

    string num;
    cin>>num;

    vector<string> allKeypadCombinations = getKeypadCombinations(num);
    sort(allKeypadCombinations.begin(),allKeypadCombinations.end());

    cout << "[";

    for(auto i = 0; i<allKeypadCombinations.size(); i++){
        if(i==allKeypadCombinations.size()-1){
            cout << allKeypadCombinations[i] ;
        }else{
            cout << allKeypadCombinations[i] << ", ";
        }
    }

    cout<<"]";

}