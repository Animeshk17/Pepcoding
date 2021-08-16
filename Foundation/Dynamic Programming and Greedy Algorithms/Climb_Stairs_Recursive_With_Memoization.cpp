#include<bits/stdc++.h>
using namespace std;

int waysToClimb(int n, vector<int>& alreadyFound){

    if(n < 0) return 0;
    else if(n==0 || n==1) return 1;
    else if(alreadyFound[n]) return alreadyFound[n];

    int ans = waysToClimb(n-1,alreadyFound) + waysToClimb(n-2,alreadyFound) + waysToClimb(n-3,alreadyFound);
    alreadyFound[n] = ans;
    return ans;
}

int main(){
    
    int n;
    cin>>n;

    vector<int> alreadyFound(n+1, 0);
    int ans = waysToClimb(n,alreadyFound);
    cout<< ans << '\n';
}