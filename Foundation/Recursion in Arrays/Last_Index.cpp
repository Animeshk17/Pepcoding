#include<bits/stdc++.h>
using namespace std;

int lastIndexOfOccurence(int* a, int n, int target){

    if(n==0) return -1;
    if(a[n-1] == target) return n-1;

    return lastIndexOfOccurence(a, n-1, target);
}

int main(){
    int n;
    cin>>n;

    int* a = new int[n];
    for(int i = 0; i<n; i++) cin>>a[i];

    int x;
    cin>>x;

    int ans = lastIndexOfOccurence(a,n,x);
    cout << ans << "\n";
}