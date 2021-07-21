#include<bits/stdc++.h>
using namespace std;

template <typename T>
void printVector(vector<T>& a){
    
    for(int i = 0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << '\n';

}

void checkAndPush(vector<int>& ans, int& ansIndex, int* a, int& iter1, int* b, int& iter2){
    if(ans.empty()){
        ans.push_back(a[iter1]);
        iter1++;
        iter2++;
        ansIndex++;
    }else{
        if(ans[ansIndex-1]!=a[iter1]){
            ans.push_back(a[iter1]);
            iter1++;
            iter2++;
            ansIndex++;
        }else{
            iter1++;
            iter2++;
        }
    }
}
void checkAndPush(vector<int>& ans, int& ansIndex, int* arr , int& iter){

    if(ans.empty()){
        ans.push_back(arr[iter]);
        iter++;
        ansIndex++;
    }else{
        if(ans[ansIndex-1]!=arr[iter]){
            ans.push_back(arr[iter]);
            iter++;
            ansIndex++;
        }else{
            iter++;
        }
    }

}

void unionOfTwoArrays(int* a, int n, int* b, int m, vector<int>& ans){
    
    int i = 0, j = 0, k = 0;

    while(i<n && j<m){

        if(a[i]<b[j]){

            checkAndPush(ans,k,a,i);
        
        }else if(a[i]==b[j]){
        
            checkAndPush(ans,k,a,i,b,j);
            
        
        }else{

            checkAndPush(ans,k,b,j);

        }

    }

    while(i<n){
        checkAndPush(ans,k,a,i);
    }

    while(j<m){
        checkAndPush(ans,k,b,j);
    }

    return ;

}

int main(){

    int n,m;
    
    cin>>n;
    int* a = new int[n];

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    cin>>m;
    int* b = new int[m];
    
    for(int i = 0; i<m; i++){
        cin>>b[i];
    }

    vector<int> ans;
    unionOfTwoArrays(a,n,b,m,ans);
    printVector(ans);
}