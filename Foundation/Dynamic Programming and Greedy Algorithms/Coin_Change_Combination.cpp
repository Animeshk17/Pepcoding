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

int coinChangeCombinations(int* coinDenominations, int n, int requiredAmount){
    if(requiredAmount < 0) return 0;
    if(requiredAmount == 0) return 1;
    if(n <= 0) return 0;

    int include = coinChangeCombinations(coinDenominations, n, requiredAmount-coinDenominations[0]);
    int exclude = coinChangeCombinations(coinDenominations+1, n-1, requiredAmount);

    return include + exclude;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    int* coinDenominations = new int[n];
    for(int i = 0; i<n; i++) cin>>coinDenominations[i];

    int amount;
    cin>>amount;

    int ans = coinChangeCombinations(coinDenominations, n, amount);
    cout << ans << endk;
}