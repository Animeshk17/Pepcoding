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

bool getTargetSubsetSum(vll& arr, ll n, ll target){

    bool** dp = new bool*[n+1];                                                             //We will create a 2-d bool array of (n+1)*(target+1)
    fo(i,n+1) dp[i] = new bool[target+1];                                                   //dp[i][j] will denote if we can get a subset sum of j using any subset formed by arr[0] -> arr[i]

    for(int i = 0; i<=n; i++){                                                               
        dp[i][0] = true;                                                                    //We can always get a subset sum of zero (because every array has an empty subset)
    }

    for(int j = 1; j<=target; j++){                                                          
        dp[0][j] = false;                                                                   //We can never get a non-zero subset sum from an empty array
    }

    dp[1][arr[0]] = true;                                                                   //We can get a subset sum equal to the first element of array by using that element

    for(int i = 2; i<=n; i++){
        for(int j = 1; j<=target; j++){
            if(j >= arr[i-1])  dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
            else  dp[i][j] = dp[i-1][j];
        }        
    }

    ll ans = dp[n][target];

    fo(i,n+1) delete[] dp[i];
    delete dp; 

    return ans;
}


int main(){

    fastIO
    
    ll n;
    cin>>n;

    vll arr(n);    
    fo(i,n) cin>>arr[i];

    ll target;
    cin>>target;

    bool gotIt = getTargetSubsetSum(arr,n,target);

    if(gotIt) cout << "true" << '\n';
    else cout << "false" << '\n';

}