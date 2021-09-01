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

int countCoinChangePermutations(vi coinDenominations, int n, int amount){

    vi permutationsToGiveChange(amount+1,0);    
    permutationsToGiveChange[0] = 1;

    for(int i = 1; i<=amount; i++){
        for(int currCoin : coinDenominations){
            if(currCoin <= i) permutationsToGiveChange[i] += permutationsToGiveChange[i-currCoin];
        }
    }

    return permutationsToGiveChange[amount];
}

int main(){

    fastIO
    
    int n;
    cin>>n;
    
    vi coinDenominations(n);
    fo(i,n) cin>>coinDenominations[i];

    int amount;
    cin>>amount;

    int ans = countCoinChangePermutations(coinDenominations,n,amount);
    cout << ans << endk;

}