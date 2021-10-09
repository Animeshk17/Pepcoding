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

void print(vector<int>& arr){
    for(auto x : arr) cout << x << ", ";
    cout << "." << endk;
}

void printTargetSumSubset(vector<int>& a, int index, int n, vector<int>& currSubset, int currSubsetsSum, int& target){

    if(index == n){
        if(currSubsetsSum == target){
            print(currSubset);
        }
        return;
    }

    currSubset.push_back(a[index]);
    printTargetSumSubset(a, index + 1, n, currSubset, currSubsetsSum + a[index], target);
    if(!currSubset.empty()) currSubset.pop_back();
    printTargetSumSubset(a, index + 1, n, currSubset, currSubsetsSum, target);
    
}

int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    fo(i,n) cin>>a[i];

    int target;
    cin>>target;

    vector<int> currSubset;
    printTargetSumSubset(a, 0, n, currSubset, 0, target);
}