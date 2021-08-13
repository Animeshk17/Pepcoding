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
// The output of the online Judge for this question is wrong for 2 test cases Therefore You will get a wrong answer verdict. So don't worry. It's not you, It's the Judge.


ll getMaxGold(int** matrix, int currRow, int currCol, int n, int m, bool** visited){

    if(currRow >= n || currCol >= m || currRow < 0 || currCol < 0 || matrix[currRow][currCol]==0 || visited[currRow][currCol]){
        return 0;
    }

    visited[currRow][currCol] = true;

    ll up = getMaxGold(matrix, currRow-1, currCol, n, m, visited);
    ll down = getMaxGold(matrix, currRow+1, currCol, n, m, visited);
    ll right = getMaxGold(matrix, currRow, currCol+1, n, m, visited);
    ll left = getMaxGold(matrix, currRow, currCol-1, n, m, visited);

    ll total = up + down + left + right + matrix[currRow][currCol];
    
    return total;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);


    int n,m;
    cin>>n>>m;

    int** matrix = new int*[n];
    bool** visited = new bool*[n];
    fo(i,n){
        matrix[i] = new int[m];
        visited[i] = new bool[m];
        fo(j,m) matrix[i][j] = 0;
    }

    fo(i,n){
        fo(j,m) cin>>matrix[i][j];
    }

    ll maxGold = llmin;

    for(int i = 0; i<n; i++){

        for(int j = 0; j<m; j++){

            if(!visited[i][j] && matrix[i][j] != 0){         
                ll currGold = getMaxGold(matrix,i,j,n,m,visited);
                maxGold = max(currGold,maxGold);
            }

        }
    }

    cout << maxGold << endk;

}
