#include<bits/stdc++.h>
using namespace std;

void print(vector<int> & a){

    for(int &x : a) cout << x << " ";
    cout << "\n";

}

void sortSquares(vector<int>& a, int n){

    for(int i = 0; i<n; i++){
        a[i] = a[i] * a[i];
    }

    sort(a.begin(), a.end());

}

int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    sortSquares(a,n);
    print(a);
}