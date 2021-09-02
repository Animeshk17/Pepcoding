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


void getMaxLoot(vi& values, vi& weights, int index, int currLoot, int currWeight, int knapsackCapacity, int& maxLoot, int n){
    
    if(index == n){
        if(currWeight <= knapsackCapacity)  maxLoot = max(currLoot,maxLoot);
        return ;
    }

    getMaxLoot(values, weights, index+1, currLoot+values[index], currWeight+weights[index], knapsackCapacity,maxLoot,n);
    getMaxLoot(values, weights, index+1, currLoot, currWeight, knapsackCapacity,maxLoot,n);

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

    int maxLoot = 0;
    getMaxLoot(values,weights,0,0,0,knapsackCapacity,maxLoot,n);

    cout << maxLoot << endk;

}
