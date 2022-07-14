#include<bits/stdc++.h>
using namespace std;
#define fastIO std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

void countDistinctElementsInWindowOfSizeK(vector<int>& a, int n, int k, vector<int>& result){

    unordered_map<int,int> frequencyMap;

    for(int i = 0; i<k; i++) {
        frequencyMap[a[i]]++;
    }

    result.push_back(frequencyMap.size());

    for(int i = k; i<n; i++) {

        int elementGoingOutOfWindow = a[i-k];

        if(frequencyMap[elementGoingOutOfWindow] == 1){
            frequencyMap.erase(elementGoingOutOfWindow);
        }else{
            frequencyMap[elementGoingOutOfWindow]--;
        }

        int elementComingInsideWindow = a[i];
        frequencyMap[elementComingInsideWindow]++;

        result.push_back(frequencyMap.size());

    }
}

int main(){

    fastIO

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) {
        cin>>a[i];
    }

    int k;
    cin>>k;

    vector<int> result;
    countDistinctElementsInWindowOfSizeK(a,n,k,result);
    
    for(int &x : result) {
        cout << x << " ";
    }
}