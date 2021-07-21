#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int* arr, int low, int high, int target){

    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==target) return true;
        else if(arr[mid]<target) low = mid+1;
        else high = mid - 1;
    }

    return false;
}

bool searchInMatrix(int** matrix, int m, int n, int target){

    int possibleRow = -1;

    for(int i = 0; i<m; i++){
        if(matrix[i][0]<=target && matrix[i][n-1]>=target){
            possibleRow = i;
            break;
        }
    }

    if(possibleRow==-1) return false;
    return binarySearch(matrix[possibleRow],0,n,target);

}

int main(){
    
    int n,m;
    cin>>m>>n;
    
    int** matrix = new int*[m];
    for(int i = 0; i<m; i++){
        matrix[i] = new int[n];
        for(int j = 0; j<n; j++){
            cin>>matrix[i][j];
        }
    }

    int target;
    cin>>target;

    bool found = searchInMatrix(matrix,m,n,target);

    if(found){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

}