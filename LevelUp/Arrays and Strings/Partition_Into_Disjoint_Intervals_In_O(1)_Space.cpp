#include<bits/stdc++.h>
using namespace std;

int doPartition(vector<int>& a, int n){

    int leftMax = a[0];
    int greater = a[0];
    int ans = 0;

    for(int i = 1; i<n; i++){
        if(a[i] > greater){
            greater = a[i];
        }else if(a[i] < leftMax){
            leftMax = greater;
            ans = i + 1;
        }
    }

    return ans;
}

int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    int leftPartitionLength = doPartition(a,n);
    cout << leftPartitionLength << "\n";
}