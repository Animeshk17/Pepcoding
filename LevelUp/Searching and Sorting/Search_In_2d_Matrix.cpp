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

int binarySearchRow(int** matrix, int row, int col, int target){
    
    int low = 0, high = row-1;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        if(matrix[mid][0] <= target && matrix[mid][col-1]>=target) return mid;
        else if(matrix[mid][0] < target) low = mid+1;
        else high = mid - 1;
    }

    return -1;
}

bool searchInMatrix(int** matrix, int m, int n, int target){

    int possibleRow = binarySearchRow(matrix,m,n,target);
    

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