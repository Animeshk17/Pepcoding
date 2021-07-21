#include<bits/stdc++.h>
using namespace std;
#define endk '\n'

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

int maximumPlantsWithHeightM(vector<int>& roseHeights, vector<Query>& queries, int m){

    int n = roseHeights.size();
    int q = queries.size();

    int* prefixCountM = new int[n]{0};
    int* prefixCountM1 = new int[n]{0};

    if(roseHeights[0]==m){
        prefixCountM[0] = 1;
    }

    if(roseHeights[0]==m+1){
        prefixCountM1[0] = 1;
    }

    for(int i = 1; i<n; i++){

        if(roseHeights[i]==m){
            prefixCountM[i] = prefixCountM[i-1] + 1;
        }else{
            prefixCountM[i] = prefixCountM[i-1];
        }

        if(roseHeights[i]==m+1){
            prefixCountM1[i] = prefixCountM1[i-1] + 1;
        }else{
            prefixCountM1[i] = prefixCountM1[i-1];
        }

    }

    int count = prefixCountM[n-1];
    int bestCase = INT_MIN;

    for(int i = 0; i<q; i++){
        int left = queries[i].startIndex;
        int right = queries[i].endIndex;
        
        int loss = prefixCountM[right] - prefixCountM[left-1];

        int gain = prefixCountM1[right] - prefixCountM1[left-1];

        bestCase = max(bestCase,(gain-loss));
    }

    int ans = bestCase + count;
    return ans;

}

int main(){

    int n,q,m;
    cin>>n>>q>>m;

    vector<int> roseHeights(n+2,0);
    vector<Query> queries;

    int startIndex, endIndex, increment = 1;
    for(int i = 0; i<q; i++){
        cin>>startIndex>>endIndex;
        Query qry(startIndex,endIndex,increment);
        queries.push_back(qry);
    }

    doRangeQueries(roseHeights,queries);
    
    int ans = maximumPlantsWithHeightM(roseHeights,queries,m);

    cout << ans << endk;
}