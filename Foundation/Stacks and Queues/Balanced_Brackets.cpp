#include<bits/stdc++.h>
using namespace std;

bool areBracketsBalanced(string& expression){

    stack<char> stck;

    for(char& c: expression) {
        if(c == '(' || c == '[' || c == '{') {
            stck.push(c);
        }else if(c == ')') {
            if(stck.empty() || stck.top() != '(') {
                return false;
            }
            stck.pop();
        }else if(c == ']') {
            if(stck.empty() || stck.top() != '[') {
                return false;
            }
            stck.pop();
        }else if(c == '}') {
            if(stck.empty() || stck.top() != '{') {
                return false;
            }
            stck.pop();
        }
    }

    return stck.empty() == true;
}

int main(){

    string expression;
    getline(cin,expression);

    if(areBracketsBalanced(expression)){
        cout << "true" << "\n";
    }else{
        cout << "false" << "\n";
    }

}