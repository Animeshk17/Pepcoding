#include<bits/stdc++.h>
using namespace std;

int firstIndexOfOccurence(int* a, int n, int x){
    
    if(n==0) return -1;

    if(a[0]==x) return 0;

    int firstIndexInRemainingArray = firstIndexOfOccurence(a+1, n-1 , x);
    
    if(firstIndexInRemainingArray == -1) return -1;
    return firstIndexInRemainingArray + 1;
}

int main(){

    int n;
    cin>>n;

    int* a = new int[n];
    for(int i = 0; i<n; i++) cin>>a[i];

    int x;
    cin>>x;

    int ans = firstIndexOfOccurence(a,n,x);
    cout << ans << "\n";
}