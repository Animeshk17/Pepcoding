#include<bits/stdc++.h>
using namespace std;

int lastManStanding(int n, int k){
    
    if(n==1) return 0;
    
    int x = lastManStanding(n-1,k);
    int ans = (x+k)%n;
    return ans;
    
}

int main(){
    
    int n,k;
    cin>>n>>k;

    int ans = lastManStanding(n,k);
    cout << ans << endl;
}