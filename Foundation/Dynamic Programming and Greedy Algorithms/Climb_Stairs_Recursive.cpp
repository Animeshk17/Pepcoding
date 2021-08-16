#include<bits/stdc++.h>
using namespace std;

int waysToClimb(int n){
    
    if(n < 0) return 0;
    else if(n == 0 || n==1) return 1;
    
    return waysToClimb(n-1) + waysToClimb(n-2) + waysToClimb(n-3);
}

int main(){
    
    int n;
    cin>>n;
    
    int ans = waysToClimb(n);
    cout << ans << '\n';

}