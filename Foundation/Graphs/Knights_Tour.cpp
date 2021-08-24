#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define makepair(a,b) make_pair(a,b)
#define pp push_back
#define endk "\n";
#define intmax INT_MAX
#define intmin INT_MIN
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define mod 1000000007
#define tenmax 1000000000
#define all(c) c.begin(), c.end()
#define fo(i,n) for(int i = 0; i<n; i++)
#define f(i,l,r) for(int i = l; i<r ; i++)
#define rf(i,l,r) for(int i = l; i>=r ; i--)
#define setmemo(x) memset(memo,x,sizeof(memo))
#define fastIO std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define matrix(N,M) vector < vector < int > > matrix(N, vector < int > (M, -1));


void printBoard(int** board, int n){
    
    fo(i,n){
        fo(j,n)
            cout << board[i][j] << " ";
        cout << endk;
    }

    cout << endk;

}

void knightsTour(int** board, int n, int row, int col, int moveCount){

    if(row < 0 || col < 0 || row >=n || col >= n || board[row][col]) return ;
    
    if(moveCount == (n*n)){
        board[row][col] = moveCount;
        printBoard(board,n);
        board[row][col] = 0;
        return ;
    }

    board[row][col] = moveCount;
    
    knightsTour(board,n,row-2,col+1,moveCount+1);
    knightsTour(board,n,row-1,col+2,moveCount+1);
    knightsTour(board,n,row+1,col+2,moveCount+1);
    knightsTour(board,n,row+2,col+1,moveCount+1);
    knightsTour(board,n,row+2,col-1,moveCount+1);
    knightsTour(board,n,row+1,col-2,moveCount+1);
    knightsTour(board,n,row-1,col-2,moveCount+1);
    knightsTour(board,n,row-2,col-1,moveCount+1);
    
    board[row][col] = 0;
    
    return ;

}


int main(){

    fastIO

    int n;
    cin>>n;

    int startRow, startCol;
    cin>>startRow>>startCol;

    int** board = new int*[n];
    fo(i,n){
        board[i] = new int[n];
        fo(j,n) board[i][j] = 0;
    }

    knightsTour(board,n,startRow,startCol,1);
}