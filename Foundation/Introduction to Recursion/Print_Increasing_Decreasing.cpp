#include<bits/stdc++.h>
using namespace std;

void printIncreasingDecreasing(int n){
    
    if(n==0) return;

    cout << n << "\n";

    printIncreasingDecreasing(n-1);
    
    cout << n << "\n";
    
}
int main(){

    int n;
    cin>>n;
    
    printIncreasingDecreasing(n);

}