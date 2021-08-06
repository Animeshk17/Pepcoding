#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
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
#define charToDigit(ch) ch-'0'
#define digitToChar(n) char(n+'0')
#define all(c) c.begin(), c.end()
#define fo(i,n) for(int i = 0; i<n; i++)
#define f(i,l,r) for(int i = l; i<r ; i++)
#define rf(i,l,r) for(int i = l; i>=r ; i--)
#define setmemo(x) memset(memo,x,sizeof(memo))
#define takeArrayInput(a,n) fo(i,n) cin>>a[i];
#define matrix(N,M) vector < vector < int > > matrix(N, vector < int > (M, -1));

void printBoard(vector<vector<int>>& board, int size){

    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            if(board[i][j]){
                cout << i << "-" << j << ", ";
            }
        }
    }

    cout << "." << endk;
}

void placeNQueens(vector<vector<int>>& board, int currRow, int n, vector<bool>& unsafeColumns, vector<bool>& unsafeDiagonals, vector<bool>& unsafeDiagonals2){
    
    if(currRow==n){
        printBoard(board,n);
    }

    for(int currCol = 0; currCol<n ; currCol++){
        if(!unsafeColumns[currCol] && !unsafeDiagonals[currRow+currCol] && !unsafeDiagonals2[currRow-currCol+n-1]){

            board[currRow][currCol] = 1;
            unsafeColumns[currCol] = true;
            unsafeDiagonals[currRow+currCol] = true;
            unsafeDiagonals2[currRow-currCol+n-1] = true;
            placeNQueens(board,currRow+1,n,unsafeColumns,unsafeDiagonals,unsafeDiagonals2);
            board[currRow][currCol] = 0;
            unsafeColumns[currCol] = false;
            unsafeDiagonals[currRow+currCol] = false;
            unsafeDiagonals2[currRow-currCol+n-1] = false;

        }
    }
}


int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> board(n, vector<int> (n, 0)) ;
    vector<bool> unsafeColumns(n,false);
    vector<bool> unsafeDiagonals((2*n-1),false);
    vector<bool> unsafeDiagonals2((2*n-1),false);

    placeNQueens(board,0,n,unsafeColumns,unsafeDiagonals,unsafeDiagonals2);
    
}