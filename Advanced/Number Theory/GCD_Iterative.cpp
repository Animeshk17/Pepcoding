#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    
    while((a%b) != 0){
        int rem = (a%b);
        a = b;
        b = rem;
    }

    return b;
}

int main(){
    int a,b;
    cin>>a>>b;

    int GCD = gcd(a,b);

    cout << GCD << '\n';
}