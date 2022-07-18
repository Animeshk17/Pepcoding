#include<bits/stdc++.h>
using namespace std;

int getLengthOfLargestSubarrayWithContiguousElements(vector<int>& a, int n){

    int maxLength = 1;

    for(int i = 0; i<n; i++) {

        int minElement = a[i];
        int maxElement = a[i];
        
        unordered_map<int,bool> alreadySeenElements;
        alreadySeenElements[a[i]] = true;

        for(int j = i+1; j<n; j++) {
            
            if(alreadySeenElements.find(a[j]) != alreadySeenElements.end()){
                break;
            }
            
            alreadySeenElements[a[j]] = true;
            
            minElement = min(a[j], minElement);
            maxElement = max(a[j], maxElement);

            if((maxElement - minElement) == (j - i)){
                maxLength = max(j - i + 1, maxLength);
            }

        }
    }

    return maxLength;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/DevSpace/CPP space/Input.txt", "r", stdin);
    freopen("D:/DevSpace/CPP space/Output.txt", "w", stdout);
    freopen("D:/DevSpace/CPP space/Error.txt", "w" , stderr);
    #endif
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) {
        cin>>a[i];
    }

    int ans = getLengthOfLargestSubarrayWithContiguousElements(a,n);
    cout << ans << "\n";
}