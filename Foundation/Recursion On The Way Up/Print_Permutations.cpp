#include <iostream>
using namespace std;

void printPermutations(string str, string asf){

    if(str.size()==0) cout << asf << "\n";

    for(int i=0; i<str.size(); i++) printPermutations(str.substr(0,i)+str.substr(i+1),asf+str[i]);

}

int main(){

    string str;
    cin>>str;
    
    printPermutations(str,"");
    
}