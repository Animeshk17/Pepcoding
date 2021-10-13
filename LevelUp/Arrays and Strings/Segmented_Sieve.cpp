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
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endk
#else
#define debug(x) 
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ll* a, ll n){ cerr << "["; fo(i,n){ cerr << a[i] << " "; } cerr << "]"; }
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T, class V> void _print(unordered_map <T, V> v) {cerr << "["; for (auto i : v) { cerr << "{" << i.first << " : " << i.second << "},"; cerr << " ";} cerr << "]";}
void printArray(ll* a, ll n){ fo(i,n){ cout << a[i] << " "; } cout << endk; }
template<typename T> void printVector(vector<T>& a) { for(auto x : a){ cout << x << " "; } cout << endk; }

vector<int> sieveOfEratosthenes(ll n){

    vector<bool> sieve(n, true);

    for(int i = 2; i*i <= n; i++){
        if(sieve[i]){
            for(int j = i*i; j<=n; j+=i){
                sieve[j] = false;
            }
        }
    }


    vector<int> primes;
    for(int i = 2; i<=n; i++){
        if(sieve[i]) primes.push_back(i);
    }

    return primes;
}

void segmentedSieve(ll a, ll b){

    ll x = sqrt(b);
    vi primes = sieveOfEratosthenes(x);
    vector<bool> sieve((b-a+1),true);

    for(int i = 0; i<primes.size(); i++){
        int firstMultliple = ceil((a * 1.0)/primes[i]);

        if(firstMultliple == 1) firstMultliple++;

        int startIndex =  firstMultliple * primes[i] - a;

        for(int j = startIndex; j<sieve.size(); j+=primes[i]){
            sieve[j] = false;
        }
    }

    
    for(int i = 0; i<sieve.size(); i++){
        if(sieve[i] && i + a != 1){
            cout << a + i << endk;
        }
    }

}

int main(){

    fastIO

    int t = 1;
    
    while(t--){
        
        ll a, b;
        cin>>a>>b;
        
        segmentedSieve(a,b);


    }
}