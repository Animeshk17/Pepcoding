    #include<bits/stdc++.h>
    using namespace std;

    int minCostPath(int** maze, int row, int col, int n, int m){

        if(row >= n || col >= n) return INT_MAX;

        if(row == n-1 && col == m-1) return maze[row][col];

        int right = minCostPath(maze,row,col+1,n,m);
        int down = minCostPath(maze,row+1,col,n,m);

        return min(right,down) + maze[row][col];

    }


    int main(){
        
        int n,m;
        cin>>n>>m;

        int** maze = new int*[n];
        for(int i = 0; i<n; i++){
            maze[i] =  new int[m];
            for(int j = 0; j<m; j++){
                cin>>maze[i][j];
            }
        }

        int ans = minCostPath(maze,0,0,n,m);
        cout << ans << '\n';

    }