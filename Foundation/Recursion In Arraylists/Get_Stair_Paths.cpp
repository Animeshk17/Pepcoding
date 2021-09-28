#include<bits/stdc++.h>
using namespace std;

vector<string> getStairsPath(int n){
    
    vector<string> ans;

    if(n<0) return ans;

    if(n==0){
        string blank;
        ans.push_back(blank);
        return ans;
    }
    
    vector<string> smallerPath1 = getStairsPath(n-1);
    vector<string> smallerPath2 = getStairsPath(n-2);
    vector<string> smallerPath3 = getStairsPath(n-3);
    
    for(auto paths : smallerPath1) ans.push_back('1'+paths);
    for(auto paths : smallerPath2) ans.push_back('2'+paths);
    for(auto paths : smallerPath3) ans.push_back('3'+paths);
    
    return ans;
}


int main(){
    
    int n;
    cin>>n;
    
    vector<string> ans = getStairsPath(n);
    
    cout << "[" ;
    
    for(int i = 0; i<ans.size(); i++){

        for(int j = 0; j<ans[i].size(); j++){
            cout << ans[i][j] ;
        }

        if(i==ans.size()-1){
            cout << "]";
        }else{
            cout << ", ";
        }

    }

}