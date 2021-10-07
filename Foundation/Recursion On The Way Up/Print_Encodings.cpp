#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf, string& alpha){

    if(str.size()==0){
        cout << asf << "\n";
        return;
    }
    
    int firstOne = str[0] - '0';

    if(firstOne==0) return;
    else if(firstOne>0) printEncoding(str.substr(1),asf+alpha[firstOne],alpha); 
    
    if(str.size()>1){

        int firstTwo = stoi(str.substr(0,2));
        if(firstTwo<27 && firstTwo>0) printEncoding(str.substr(2),asf+alpha[firstTwo],alpha);

    }

}

int main(){

    string str;
    cin>>str;
    
    string alpha = " abcdefghijklmnopqrstuvwxyz";

    printEncoding(str, "", alpha);
    
}