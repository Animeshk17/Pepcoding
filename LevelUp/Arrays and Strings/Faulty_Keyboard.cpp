#include<bits/stdc++.h>
using namespace std;

bool check(string& name , string& typedName){

    int i = 0, j = 0;

    while(i < name.size() && j < typedName.size()){
        if(name[i] == typedName[j]){
            i++;
            j++;
        }else{
            j++;
        }
    }

    return (i==name.size());
}


int main(){

    string name, typedName;
    cin>>name>>typedName;

    bool isPossible = check(name, typedName);

    if(isPossible){
        cout << "true" << "\n";
    }
    else{
        cout << "false" << "\n";
    }
}