#include<bits/stdc++.h>
using namespace std;

int power(int x, int n){
    
    if(x==1 || n==0) return 1;
    else if(n==1) return x;

    int smallerAns = power(x,n/2);

    if(n%2) return smallerAns*smallerAns*x;
    else return smallerAns*smallerAns;
}

int main(){

    int x, n;
    cin>>x>>n;

    cout << power(x,n) << "\n";
}