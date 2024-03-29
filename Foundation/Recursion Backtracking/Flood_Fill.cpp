#include<bits/stdc++.h>
using namespace std;

void floodfill(vector<vector<int>> maze,int row, int col, string ans, vector<vector<bool>> visited) {

    if(row<0 || col<0 || row==maze.size() || col==maze[0].size() || maze[row][col]==1 || visited[row][col])  return;  
    if(row==maze.size()-1 && col==maze[0].size()-1) cout << (ans) << '\n';
    
    visited[row][col] = true;

    floodfill(maze,row-1,col,ans+'t',visited);
    floodfill(maze,row,col-1,ans+'l',visited);
    floodfill(maze,row+1,col,ans+'d',visited);
    floodfill(maze,row,col+1,ans+'r',visited);

    visited[row][col] = false;

}


int main() {

    int n,m;
    cin >> n >>m;

    vector < vector < int >> arr(n, vector < int > (m));
    vector<vector<bool>> visited(n, vector<bool> (m,false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    floodfill(arr,0,0,"",visited);

}