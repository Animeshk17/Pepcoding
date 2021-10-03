#include <iostream>
using namespace std;

void printStairPaths(int n, string psf, string& jump){

    if(n<0) return;

    if(n==0) cout << psf << "\n";
        
    printStairPaths(n-1,psf+jump[1],jump);
    printStairPaths(n-2,psf+jump[2],jump);
    printStairPaths(n-3,psf+jump[3],jump);
    
}

int main(){

    int n;
    cin >> n;

    string jump = "0123";

    printStairPaths(n, "",jump);

}