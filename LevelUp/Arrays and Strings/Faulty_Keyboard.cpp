#include<bits/stdc++.h>
using namespace std;

bool check(string& name , string& typedName){
    
    int i = 0, j = 0;

    while (j < typedName.size()) {
        if (i < name.size() && name[i] == typedName[j]) ++i, ++j;
        else if (i > 0 && name[i - 1] == typedName[j]) ++j;
        else return false;
    }
    
    return i == name.size();
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