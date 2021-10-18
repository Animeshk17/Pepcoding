#include<bits/stdc++.h>
using namespace std;

template <typename T>
void printVector(vector<T>& a){
    for(auto i : a){
        cout << i << " ";
    }
}

class Query{

    public:
    int startIndex;
    int endIndex;
    int increment;

    Query(int startIndex, int endIndex, int increment){
        this->startIndex = startIndex;
        this->endIndex = endIndex;
        this->increment = increment;
    }

};


void doRangeQueries(vector<int>& arr, vector<Query>& queries){

    int n = arr.size();
    int k = queries.size();

    
    for(int i = 0; i<k; i++){

        int left = queries[i].startIndex;
        int right = queries[i].endIndex;
        int increment = queries[i].increment;

        arr[left] += increment;
        if(right+1 < n) arr[right+1] += -increment;
    }

    
    for(int i = 1; i<n; i++){
        arr[i] = arr[i-1] + arr[i];
    }

    return ;
}


int main(){

    int n,k;
    cin>>n>>k;
    
    vector<int> arr(n,0);
    vector<Query> queries;
    
    int startIndex, endIndex, increment;
    
    for(int i = 0; i<k; i++){
 
        cin>>startIndex>>endIndex>>increment;
        Query q(startIndex,endIndex,increment);
        queries.push_back(q);
 
    }

    doRangeQueries(arr,queries);
    printVector(arr);
}