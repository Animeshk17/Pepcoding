#include<bits/stdc++.h>
using namespace std;

void printZigZag(int n){

    if(n == 1){
        cout << "1 1 1 " ;
        return ;
    }

    cout << n << " ";
    
    for(int i = 0; i<2; i++){
        printZigZag(n-1);
        cout << n << " " ;
    }

}


int main(){

    int n;
    cin>>n;

    printZigZag(n);
    
}