#include<bits/stdc++.h>
using namespace std;


void printSubsequence(string ques, string ans){

    if(ques.size()==0){
        cout << ans << "\n";
        return;
    }

    printSubsequence(ques.substr(1),ans+ques[0]);
    printSubsequence(ques.substr(1),ans);
}


int main(){

    string str; 
    cin>> str;
    
    printSubsequence(str,"");

}