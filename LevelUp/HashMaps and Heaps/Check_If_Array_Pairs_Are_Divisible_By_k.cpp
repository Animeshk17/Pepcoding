#include<bits/stdc++.h>
using namespace std;

int pairSumToK(vector<int>& a, int x){
    
    unordered_map<int,int> frequencyMap;
    
    int numOfPairs = 0;

    for(int i = 0; i<a.size(); i++){
        
        int curr = a[i];
        int reqd = x - a[i];

        if(frequencyMap.find(reqd) != frequencyMap.end() && frequencyMap[reqd] > 0){
            numOfPairs++;
            frequencyMap[reqd]--;
            frequencyMap[curr]--;
        }

        frequencyMap[curr]++;

    }

    int numOfZeroes = frequencyMap[0];
    numOfPairs += (numOfZeroes/2);

    return numOfPairs;

}

bool areAllPairsDivisibleByK(vector<int>& a, int n, int k) {

    for(int i = 0; i<n; i++) {
        a[i] %= k;
        a[i] += k;
        a[i] %= k;
    }   

    int numOfPairs = pairSumToK(a, k);

    return (numOfPairs*2) == n;
}

int main() {

    int n; 
    cin>>n;

    vector<int> a(n);

    for(int i = 0; i<n; i++) {
        cin>>a[i];
    }

    int k;
    cin>>k;

    bool ans = areAllPairsDivisibleByK(a, n, k);
    
    if(ans){
        cout << "true" << "\n";
    }else{
        cout << "false" << "\n";
    }
}