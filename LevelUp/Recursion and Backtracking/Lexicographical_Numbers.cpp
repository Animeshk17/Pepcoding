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
#define matrix(N,M) vector < vector < int > > matrix(N, vector < int > (M, -1));

template <typename T>
void printVector(vector<T>& v){
    for(auto &x : v) cout << x << endk;
}

void getLexicographicNumbers(string curr, vector<string>& ans, int n, bool& withinRange){

    if(!curr.empty() && stoi(curr) > n){
        ans.pop_back();
        printVector(ans);
        ans.clear();
        return ;
    }
    
    for(int i = 0; i<=9; i++){
        ans.push_back(curr+to_string(i));
        getLexicographicNumbers(curr+to_string(i), ans, n, withinRange);
    }
    
    return ;
}


int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    
    vector<string> ans;
    string curr = "";

    bool withinRange = true;

    for(int i = 1; i<=9; i++){
        if( stoi(curr+to_string(i)) < n){
            ans.push_back(curr+to_string(i));
            getLexicographicNumbers(curr+to_string(i),ans,n,withinRange);
        }
    }

    printVector(ans);
}