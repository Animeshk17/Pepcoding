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

void printSudoku(int** sudoku){
    fo(i,9){
        fo(j,9){
            cout << sudoku[i][j] << " ";
        }
        cout << endk;
    }
}


bool isValid(int** sudoku, int currRow, int currCol, int value){

    for(int i = 0; i<9; i++) if(sudoku[i][currCol]==value) return false;    //checking if we already have this value in the row
    for(int i = 0; i<9; i++) if(sudoku[currRow][i]==value) return false;    //checking if we already have this value in the col

    int subMatrixRow = 3 * (currRow/3);
    int subMatrixCol = 3 * (currCol/3);

    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(sudoku[subMatrixRow+i][subMatrixCol+j]==value) return false;
        }
    }

    return true;
}

void solveSudoku(int** sudoku, int currRow, int currCol, bool& isSolved){

    if(currRow == 9){
        isSolved = true;
        printSudoku(sudoku);
        return ;
    }

    int nextRow,nextCol;

    if(currCol==8) nextRow = currRow + 1;
    else nextRow = currRow;

    if(currCol==8) nextCol = 0;
    else nextCol = currCol + 1;

    if(sudoku[currRow][currCol] != 0) solveSudoku(sudoku,nextRow,nextCol,isSolved);
    
    else{
        for(int val = 1; val<=9; val++){
            if(isValid(sudoku,currRow,currCol,val)){
                sudoku[currRow][currCol] = val;
                solveSudoku(sudoku,nextRow,nextCol,isSolved);
                if(isSolved) return ;
                sudoku[currRow][currCol] = 0;
            }
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int** sudoku = new int*[9];

    fo(i,9){
        sudoku[i] = new int[9];
        fo(j,9){
            cin>>sudoku[i][j];
        }
    }
    
    bool isSolved = false;
    solveSudoku(sudoku,0,0,isSolved);
}