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

ll coinChangeCombinations(vll& coinDenominations, ll n, ll target){
    
    vll dp(target+1,0);                         //dp[i] will store no. of coin combinations which give i
    dp[0] = 1;

    for(auto currCoin : coinDenominations){         //after each iteration the effect of that particular coin denomination will get registered in our dp array i.e ways to give change using the coins upto that particular coin denomination
        for(int i = currCoin; i<=target; i++){      //therefore after all the iterations dp[target] will hold the no. of combinations which will produce sum equal to target using all the coin denominations.
            dp[i] += dp[i-currCoin];
        }
    }

    return dp[target];
}

int main(){

    fastIO

    ll n;
    cin>>n;

    vll coinDenominations(n);    
    fo(i,n) cin>>coinDenominations[i];

    ll target;
    cin>>target;

    ll ans = coinChangeCombinations(coinDenominations,n, target);
    cout << ans << endk;

}