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


ll getMaxGold(ll** matrix, ll currRow, ll currCol, ll n, ll m, ll** memo){
    
    if(currRow < 0 || currCol < 0 ||  currRow >= n || currCol >=m ){
        return 0;
    }

    if(memo[currRow][currCol] != -1) return memo[currRow][currCol];

    ll gold1 =  getMaxGold(matrix,currRow-1,currCol+1,n,m,memo);
    ll gold2 =  getMaxGold(matrix,currRow,currCol+1,n,m,memo);
    ll gold3 =  getMaxGold(matrix,currRow+1,currCol+1,n,m,memo);
    
    memo[currRow][currCol] = matrix[currRow][currCol] + max(gold1,max(gold2,gold3));
    return memo[currRow][currCol];
}

int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m;
    cin>>n>>m;

    ll** matrix = new ll*[n];
    fo(i,n){
        matrix[i] = new ll[m];
        fo(j,m){
            cin>>matrix[i][j];
        }
    }

    ll maxGold = llmin;

    ll** memo = new ll*[n];
    fo(i,n){
        memo[i] = new ll[m];
        fo(j,m){
            memo[i][j] = -1;
        }
    }

    for(int i = 0; i<n; i++){
        ll goldFromThisPosition = getMaxGold(matrix,i,0,n,m,memo);
        maxGold = max(goldFromThisPosition,maxGold);
    }

    cout << maxGold << endk;

}