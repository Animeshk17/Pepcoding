#include<bits/stdc++.h>
using namespace std;

void print(vector<int> & a){

    for(int &x : a) cout << x << " ";
    cout << "\n";

}

void mergeTwoSortedArrays(vector<int>& arr1, vector<int>& arr2, vector<int>& a, int n){

    int i = 0, j = 0, k = 0;

    while(i < arr1.size() && j < arr2.size()){
        
        if(arr1[i] <= arr2[j]){
        
            a[k++] = arr1[i++];
        
        }else{

            a[k++] = arr2[j++];

        }

    }

    while(i < arr1.size()){
    
        a[k++] = arr1[i++];
    
    }

    while(j < arr2.size()){
    
        a[k++] = arr2[j++];
    
    }
}

void sortSquares(vector<int>& a, int n){

    int positivesStartIndex = lower_bound(a.begin(), a.end(), 0) - a.begin();

    vector<int> arr1;
    for(int i = positivesStartIndex - 1; i>=0; i--) arr1.push_back(a[i]*a[i]);

    vector<int> arr2;
    for(int i = positivesStartIndex; i<n; i++) arr2.push_back(a[i] * a[i]);

    mergeTwoSortedArrays(arr1, arr2, a, n);
    return ;

}

int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    sortSquares(a,n);
    print(a);
}