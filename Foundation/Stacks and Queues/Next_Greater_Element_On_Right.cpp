#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> NextGreaterOnRight1(vector<int> a){

    int n = a.size();
    vector<int> ans(n);
    
    stack<int> st;
    st.push(0);
    
    for(int i=1; i<n; i++){
        while(!st.empty() && a[st.top()]<a[i]){
            ans[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    
    while(!st.empty()){
        ans[st.top()] = -1;
        st.pop();
    }
    
    return ans;

}

vector<int> NextGreaterOnRight(vector<int> a){

    int n = a.size();
    vector<int> ans(n);

    stack<int> st;
    st.push(a[n-1]);
    ans[n-1] = -1;
    
    for(int i=n-2; i>=0; i--){
    
        while(!st.empty() && st.top()<=a[i]){
            st.pop();
        }
    
        if(st.empty()){
            ans[i] = -1;
        }else{
            ans[i] = st.top();
        }
    
        st.push(a[i]);
    
    }
    
    return ans;

}

int main(){

    int n;
    cin>>n;
    
    vector<int> a(n); 
    for(int i=0; i<n ; i++){
        cin>>a[i];
    }
    
    vector<int> ans(n);
    ans = NextGreaterOnRight1(a);
    for(auto x: ans){
        cout << x << endl;
    }
}