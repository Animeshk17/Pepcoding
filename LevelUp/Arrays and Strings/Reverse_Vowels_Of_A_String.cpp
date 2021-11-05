#include<bits/stdc++.h>
using namespace std;

void reverseVowels(string& s){

    unordered_map<char, int> vowels;
    vowels['a'] = 1;
    vowels['e'] = 1;
    vowels['i'] = 1;
    vowels['o'] = 1;
    vowels['u'] = 1;

    vector<int> indices;
    string vowelsInString;

    for(int i = 0; i<s.size(); i++){
        char c = s[i];
        if(vowels.find(tolower(c))!= vowels.end()){
            vowelsInString.push_back(c);
            indices.push_back(i);
        }
    }
    
    int j = 0;
    reverse(vowelsInString.begin(),vowelsInString.end());
    for(int index : indices){
        s[index] = vowelsInString[j++];
    }

}

int main(){ 
    
    string s;
    cin>>s;

    reverseVowels(s);
    cout << s << "\n";
}