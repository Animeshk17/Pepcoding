#include <iostream>
using namespace std;


void printKeypadCombinations(string ques, string ans, string codes[]){

    if(ques.size()==0){
        cout << ans << "\n";
        return;
    }

    string firstKey = codes[ques[0]-'0'];

    for(auto x: firstKey) printKeypadCombinations(ques.substr(1), ans+x, codes);
    
}

int main(){

    string str;
    cin >> str;
    
    string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
    
    printKeypadCombinations(str, "", codes);
}