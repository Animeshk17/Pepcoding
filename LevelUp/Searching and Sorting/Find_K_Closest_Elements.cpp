#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Pair{
public:
    int val;
    int gap;

    Pair(){

    }

    Pair(int val, int gap){
        this->val = val;
        this->gap = gap;
    }

};

struct compare{
    bool operator()(Pair p, Pair q){
        if(p.gap == q.gap){
            if(p.val<q.val) return true;
            else return false;
        }else{
            if(p.gap<q.gap) return true;
            else return false;
        }
    }
};


vector<int> findKClosestElements(vector<int>& arr, int k, int x){
    priority_queue<Pair,vector<Pair>,compare> pq;
    for(int i = 0; i<k; i++) pq.push(Pair(arr[i],abs(arr[i]-x)));
    for(int i = k; i<arr.size(); i++){
        if(pq.top().gap > abs(arr[i]-x)){
            pq.pop();
            pq.push(Pair(arr[i],abs(arr[i]-x)));
        }
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top().val);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}

template <typename T>
void printVector(vector<T>& a){
    for(auto element : a) cout << element << " ";
    cout << '\n';
}

int main(){
    int n,k,x;
    cin>>n;
    
    vector<int> arr(n);
    for(int i = 0 ; i<n; i++) cin>>arr[i];
    
    cin>>k>>x;
    
    vector<int> ans = findKClosestElements(arr,k,x);
    printVector(ans);


}