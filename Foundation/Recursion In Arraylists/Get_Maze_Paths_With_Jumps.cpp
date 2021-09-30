#include<bits/stdc++.h>
using namespace std;


// sr - source row
// sc - source column
// dr - destination row
// dc - destination column

void printMazePaths(int sr, int sc, int dr, int dc, string pathSoFar, vector<string>& ans) {
    // write your code here
    if(sr>dr || sc>dc){
        return;
    }
    
    if(sr==dr && sc==dc){
        ans.push_back(pathSoFar);
        return;
    }        
    
    for(int i = 1; i<=dc-sc; i++){
        printMazePaths(sr,sc+i,dr,dc,pathSoFar+"h"+to_string(i),ans);
    }
    for(int i = 1; i<=dr-sr; i++){
        printMazePaths(sr+i,sc,dr,dc,pathSoFar+"v"+to_string(i),ans);
    }
    for(int i = 1; i<=dr-sr && i<=dc-sc; i++){
        printMazePaths(sr+i,sc+i,dr,dc,pathSoFar+"d"+to_string(i),ans);
    }
    
    
}

void display(vector<string>& arr){

    cout << "[";
    
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}

int main() {

    int n,m;
    cin>>n>>m;

    vector<string> ans;
    printMazePaths(0, 0, n - 1, m - 1, "",ans);
    display(ans);
}