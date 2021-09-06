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

vector<int> NextSmallerIndexOnRight(vector<int> a, int n){
    
    vector<int> ans(n);
    stack<int> st;

    st.push(n-1);
    ans[n-1] = n;
    
    for(int i=n-2; i>=0; i--){
    
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
    
        if(st.empty()){
            ans[i] = n;
        }else{
            ans[i] = st.top();
        }
    
        st.push(i);
    }
    
    return ans;
}

vector<int> NextSmallerIndexOnLeft(vector<int> a, int n){
    
    vector<int> ans(n);
    stack<int> st;
    
    st.push(0);
    
    for(int i=0; i<n; i++){
    
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
    
        if(st.empty()){
            ans[i] = -1;
        }else{
            ans[i] = st.top();
        }
    
        st.push(i);
    }
    
    return ans;
}

int LargestAreaUnderHistogram(vector<int> a, int n){
    
    vector<int> nsRight = NextSmallerIndexOnRight(a,n);
    vector<int> nsLeft = NextSmallerIndexOnLeft(a,n);
    vector<int> ans(n);
    
    int maxArea = INT_MIN;
    int currArea = 0;

    for(int i=0; i<n; i++){
    
        int width = (nsRight[i] - nsLeft[i] - 1);
        currArea = a[i]*width;
        maxArea = max(currArea,maxArea);
    
    }
    
    return maxArea;

}

int main(){

    int n ;
    cin>> n;
    
    vector<int> a(n);
    fo(i,n) cin>>a[i];

    int maxArea = LargestAreaUnderHistogram(a,n);
    cout << maxArea << endk;
}