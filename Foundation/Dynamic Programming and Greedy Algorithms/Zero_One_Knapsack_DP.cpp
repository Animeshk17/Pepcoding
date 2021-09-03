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


int getMaxLoot(vi& values, vi& weights, int n, int knapsackCapacity){

    vector<vector<int>> dp(n+1,vector<int>(knapsackCapacity+1,0));                      //dp[i][j] stores the max loot possible using the items upto "i"th index with knapsack capacity being "j" kg.

    for(int i = 0; i<=n; i++){
        dp[i][0] = 0;                                                                 //There can be no loot if the capacity of the knapsack is Zero
    }

    for(int j = 0; j<=knapsackCapacity; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=knapsackCapacity; j++){
            if(j>=weights[i-1]) dp[i][j] = max(dp[i-1][j-weights[i-1]] + values[i-1] , dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][knapsackCapacity];
    
}

int main(){

    fastIO

    int n;
    cin>>n;
    
    vi values(n);
    fo(i,n) cin>>values[i];
    
    vi weights(n);
    fo(i,n) cin>>weights[i];
    
    int knapsackCapacity;
    cin>>knapsackCapacity;

    int maxLoot = getMaxLoot(values,weights,n,knapsackCapacity);
    cout << maxLoot << endk;

}