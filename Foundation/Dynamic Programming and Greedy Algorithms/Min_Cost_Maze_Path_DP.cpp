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

int minCostPath(int** maze, int n, int m){
    
    int** dp = new int*[n];                                 //We will make a 2d array of (n*m)
    fo(i,n) dp[i] = new int[m];                             //dp[i][j] stores minm cost to reach bottom-right cell from (i,j)th cell

    dp[n-1][m-1] = maze[n-1][m-1];                          //Cost to reach bottom-right cell from bottom-right cell is nothing but cost of only that cell

    for(int i = n-2; i>=0; i--){
        dp[i][m-1] = dp[i+1][m-1] + maze[i][m-1];           //We can only move down
    }

    for(int j = m-2; j>=0; j--){
        dp[n-1][j] = dp[n-1][j+1] + maze[n-1][j];           //We can only move right
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = m-2; j>=0; j--){
            dp[i][j] = min(dp[i+1][j],dp[i][j+1]) + maze[i][j];
        }
    }

    int ans = dp[0][0];

    fo(i,n) delete[] dp[i];
    delete[] dp;

    return ans;

}


int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    int** maze = new int*[n];
    for(int i = 0; i<n; i++){
        maze[i] =  new int[m];
        for(int j = 0; j<m; j++){
            cin>>maze[i][j];
        }
    }

    int ans = minCostPath(maze,n,m);
    cout << ans << endk;
}

