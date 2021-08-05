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
#define all(c) c.begin(), c.end()
#define fo(i,n) for(int i = 0; i<n; i++)
#define f(i,l,r) for(int i = l; i<r ; i++)
#define rf(i,l,r) for(int i = l; i>=r ; i--)
#define setmemo(x) memset(memo,x,sizeof(memo))
#define takeArrayInput(a,n) fo(i,n) cin>>a[i];
#define matrix(N,M) vector < vector < int > > matrix(N, vector < int > (M, -1));

class Query{
    public:
    char action;
    int startIndex;
    int endIndex;
    int increment;

    Query(char action, int startIndex, int endIndex){
        this->action = action;
        this->startIndex = startIndex;
        this->endIndex = endIndex;
        this->increment = endIndex;
    }
};

void takeQueriesInput(vector<Query>& queries, int q){
    char action;
    int startIndex,endIndex;

    for(int i = 0; i<q; i++){
        cin>>action>>startIndex>>endIndex;
        Query q(action,startIndex,endIndex);
        queries.push_back(q);
    }
}

ll rightMostSetBit(ll n){ return (n & -n); } 

void update(ll* fenwickArray, ll n, ll index, ll increment){
    while(index<=n){
        fenwickArray[index] += increment;
        index += rightMostSetBit(index);
    }
}

ll prefixSum(ll* fenwickArray, int index){
    ll sum = 0;
    while(index > 0){
        sum += fenwickArray[index];
        index -= rightMostSetBit(index);
    }
    return sum;
}

ll rangeSum(ll* fenwickArray, ll n, ll startIndex, ll endIndex){
    return prefixSum(fenwickArray,endIndex) - prefixSum(fenwickArray,startIndex-1);
}

void preprocess(ll* a, ll n, ll* fenwickArray){
    for(int i = 1; i<=n; i++){
        update(fenwickArray,n,i,a[i]);
    }
}

void doRangeQueries(ll* a, ll n, vector<Query>& queries, int q){
    
    ll* fenwickArray = new ll[n+1];
    fo(i,n+1) fenwickArray[i] = 0;
    preprocess(a,n,fenwickArray);

    for(Query qry : queries){
        char action = qry.action;


        if(action=='u'){
            update(fenwickArray,n,qry.startIndex,qry.increment);
        }
        
        if(action=='q'){
            ll ans = rangeSum(fenwickArray,n,qry.startIndex,qry.endIndex);
            cout << ans << endk;
        }
        
    }

}


int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    
    ll* a = new ll[n+1];
    f(i,1,n+1) cin>>a[i];

    int q;
    cin>>q;

    vector<Query> queries;
    takeQueriesInput(queries,q);
    
    doRangeQueries(a,n,queries,q);
}