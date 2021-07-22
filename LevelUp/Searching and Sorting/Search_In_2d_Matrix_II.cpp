#include<bits/stdc++.h>
using namespace std;

bool searchInMatrix(int** matrix, int row, int col, int target){
    int currRow = 0, currCol = col-1;
    while(currRow < row && currCol >= 0){
        int currElement = matrix[currRow][currCol];
        if(currElement==target) return true;
        else if(currElement < target) currRow++;
        else currCol--;
    }
    return false;
}

int main(){
    int m,n;
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