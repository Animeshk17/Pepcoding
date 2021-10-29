#include<bits/stdc++.h>
using namespace std;

int doPartition(vector<int>& a, int n){

    int ans = 0; 

    for(int i = 0; i<n-2; i++){

        int smallers = 0;

        for(int j = i+1; j<n; j++){
            if(a[j] < a[i]) smallers++;
        }

        if(smallers == 0) ans = i+1;
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