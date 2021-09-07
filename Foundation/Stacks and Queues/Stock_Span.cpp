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

vi getStockSpan(vi& price, int n){
    
    stack<int> stck;
    stck.push(0);
    
    vi ans(n);
    ans[0] = 1;
    
    for(int i = 1; i<n; i++){
    
        while(!stck.empty() && price[stck.top()] < price[i]){
            stck.pop();
        }

        if(stck.empty()) ans[i] = i+1;
        else ans[i] = i - stck.top();
        stck.push(i);
    }
    
    return ans;
}



int main(){

    fastIO
    
    int n;
    cin>>n;
    
    vi price(n);
    fo(i,n) cin>>price[i];
    
    vi ans = getStockSpan(price,n);

    fo(i,n) cout << ans[i] << endk;
}