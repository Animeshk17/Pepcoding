#include<bits/stdc++.h>
using namespace std;

void display_array(vector<int> a, int index){

    if(index==a.size()) return;
    
    cout << a.at(index) << "\n";
    display_array(a,index+1);

}


int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    display_array(a,0);
}
