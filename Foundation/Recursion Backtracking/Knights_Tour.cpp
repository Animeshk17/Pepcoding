#include<bits/stdc++.h>
using namespace std;

void displayBoard(int** board, int boardSize){
    for(int i = 0 ; i<boardSize; i++){
        for(int j = 0 ; j<boardSize; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void printKnightsTour(int row, int col, int moveCount, int boardSize, int** board){
    
    if(row<0 || col<0 || row>=boardSize || col>=boardSize || board[row][col]>0){
        return ;
    }
    
    if(moveCount==(boardSize*boardSize)){
        
        board[row][col] = moveCount;
        displayBoard(board,boardSize);
        cout << "\n";
        board[row][col] = 0;
        return ;

    }

    board[row][col] = moveCount;

    printKnightsTour(row-2,col+1,moveCount+1,boardSize,board);
    printKnightsTour(row-1,col+2,moveCount+1,boardSize,board);
    printKnightsTour(row+1,col+2,moveCount+1,boardSize,board);
    printKnightsTour(row+2,col+1,moveCount+1,boardSize,board);
    printKnightsTour(row+2,col-1,moveCount+1,boardSize,board);
    printKnightsTour(row+1,col-2,moveCount+1,boardSize,board);
    printKnightsTour(row-1,col-2,moveCount+1,boardSize,board);
    printKnightsTour(row-2,col-1,moveCount+1,boardSize,board);

    board[row][col] = 0;

    return ;

}

int main(){

    int n ; 
    cin>>n; 

    int startRow, startCol;
    cin>> startRow >> startCol;

    int** board = new int* [n];
    for(int i = 0 ; i<n ; i++){
        board[i] =  new int[n];
        for(int j = 0; j<n; j++){
            board[i][j] = 0;
        }
    }

    printKnightsTour(startRow,startCol,1,n,board);

}