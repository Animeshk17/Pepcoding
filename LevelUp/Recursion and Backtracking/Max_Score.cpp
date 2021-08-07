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

bool isValid(vector<string>& currWords, unordered_map<char,ll> freqMap){
    for(string &word : currWords){
        for(char &ch : word){
            if(freqMap.find(ch)==freqMap.end() || freqMap[ch]==0){
                return false; 
            }
            freqMap[ch]--;
        }
    }
    return true;
}

ll getScore(vector<string>& currWords, unordered_map<char,ll>& charScore){
    ll score = 0;
    for(string &word : currWords){
        for(char &ch : word){
            score += charScore[ch];
        }
    }
    return score;
}

void getMaxScore(vector<string>& words, ll index, ll n, vector<string> currWords, unordered_map<char,ll>& freqMap, unordered_map<char,ll>& charScore, ll& maxScore){
    
    if(index == n){
        if(isValid(currWords,freqMap)){
            ll currScore = getScore(currWords,charScore);
            maxScore = max(currScore,maxScore);
            return ;
        }
        return ;
    }

    getMaxScore(words,index+1,n,currWords,freqMap,charScore,maxScore);
    currWords.push_back(words.at(index));
    getMaxScore(words,index+1,n,currWords,freqMap,charScore,maxScore);
    if(!currWords.empty()) currWords.pop_back();

    return ;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    
    vector<string> words(n);
    fo(i,n) cin>>words[i];

    ll m;
    cin>>m;

    unordered_map<char,ll> freqMap;
    char ch;

    fo(i,m){
        cin>>ch;
        freqMap[ch]++;
    }
    
    unordered_map<char,ll> charScore;
    
    fo(i,26) cin>>charScore['a'+i];

    ll maxScore = llmin;
    vector<string> currWords;


    getMaxScore(words, 0, n, currWords, freqMap, charScore, maxScore);
    cout << maxScore << endk;
}