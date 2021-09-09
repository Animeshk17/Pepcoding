#include<bits/stdc++.h>
using namespace std;

vector<int> getNextGreaterOnRight(vector<int> a){
    
    int n = a.size();
    vector<int> ans(n);

    stack<int> st;
    st.push(n-1);
    
    ans[n-1] = INT_MAX;
    
    for(int i=n-2; i>=0; i--){
    
        while(!st.empty() && a[st.top()]<=a[i]){
            st.pop();
        }
    
        if(st.empty()){
            ans[i] = INT_MAX;
        }else{
            ans[i] = st.top();
        }
    
        st.push(i);
    
    }
    
    return ans;

}

vector<int> SlidingWindowMax(vector<int> a, int k){
    
    int n = a.size();
    vector<int> ans (n-k+1);
    
    vector<int> nextGreaterElementOnRight = getNextGreaterOnRight(a);
    
    int j = 0;
    
    for(int i=0; i<=n-k; i++){
    
        if(j<i){
            j = i;
        }
    
        while(nextGreaterElementOnRight[j]<(i+k)){
            j = nextGreaterElementOnRight[j];
        }
    
        ans[i] = a[j];
    
    }
    
    return ans;

}


int main(){
    
    int n;
    cin>>n;
    
    vector<int> a(n); 
    for(int i=0; i<n ; i++) cin>>a[i];
    
    int k;
    cin>>k;

    vector<int> ans = SlidingWindowMax(a,k);
    
    for(auto x: ans) cout << x << "\n";
    
}