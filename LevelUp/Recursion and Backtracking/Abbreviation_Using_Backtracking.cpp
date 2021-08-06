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
#define digitToChar(n) char(n+'0')
#define charToDigit(ch) ch-'0'
#define all(c) c.begin(), c.end()
#define fo(i,n) for(int i = 0; i<n; i++)
#define f(i,l,r) for(int i = l; i<r ; i++)
#define rf(i,l,r) for(int i = l; i>=r ; i--)
#define setmemo(x) memset(memo,x,sizeof(memo))
#define takeArrayInput(a,n) fo(i,n) cin>>a[i];
#define matrix(N,M) vector < vector < int > > matrix(N, vector < int > (M, -1));

void generateAllAbbreviations(string& s, int index, string currAns,int count){
    if(index==s.size()){
        if(count==0) cout << currAns << endl;
        else cout << currAns << count << endl;
        return;
    }


    if(count > 0){
        generateAllAbbreviations(s, index+1, currAns + to_string(count) + s[index], 0);
    }else{
        generateAllAbbreviations(s, index+1, currAns + s[index], 0);
    }

    generateAllAbbreviations(s, index+1, currAns, count+1);
}

int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;
    
    generateAllAbbreviations(s,0,"",0);

}