#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column

vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    
    vector<string> ans;
    vector<string> pathsFromRight;
    vector<string> pathsFromBelow;
    
    if(sr==dr && sc==dc){
        ans.push_back("");
        return ans;
    }

    if(sr>dr && sc>dc) return ans;
    
    if(sr<dr) pathsFromBelow = getMazePaths(sr+1,sc,dr,dc);
    
    if(sc<dc) pathsFromRight = getMazePaths(sr,sc+1,dr,dc);

    for(auto path: pathsFromRight) ans.push_back('h'+path);
    for(auto path : pathsFromBelow) ans.push_back('v'+path);
    
    return ans;
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
    cin >> n >> m;
    
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}