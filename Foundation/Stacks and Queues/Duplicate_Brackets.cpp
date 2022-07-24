#include<bits/stdc++.h>
using namespace std;

bool areDuplicateBracketsPresent(string& expression){

    stack<char> st;

    for(char& c : expression){
        
        if(c == ' ') continue;
        
        if(c == ')') {

            if(st.top() == '('){
                return true;
            }

            while(st.top() != '('){
                st.pop();
            }
            st.pop();
       
        }else{
            st.push(c);
        }
    }

    return false;

}


int main(){

    string s;
    getline(cin,s);

    if(areDuplicateBracketsPresent(s)){
        cout << "true" << "\n";
    }else{
        cout << "false" << "\n";
    }
}