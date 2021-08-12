#include<bits/stdc++.h>
using namespace std;

bool isBitSet(int n, int mask){
    return n&mask;
}

void setKthBit(int& n, int k){
    int mask = 1<<k;
    n |= mask;
}

class BinaryTrieNode{
    public:
    BinaryTrieNode* zero;
    BinaryTrieNode* one;

    BinaryTrieNode(){
        zero = nullptr;
        one = nullptr;
    }
    
};

class BinaryTrie{
    public:
    BinaryTrieNode* root;

    BinaryTrie(){
        root = new BinaryTrieNode();
    }

    void insert(int val){

        BinaryTrieNode* currNode = root;
        int bitIndex = 30;
        
        while(bitIndex >= 0){
            
            int mask = 1<<bitIndex;
            int currBit;
            
            if(isBitSet(val,mask)){
                
                currBit = 1;
                if(currNode->one == NULL) currNode->one = new BinaryTrieNode();
                currNode = currNode->one;
            
            }else{
            
                currBit = 0;
                if(currNode->zero == NULL) currNode->zero = new BinaryTrieNode();
                currNode = currNode->zero;
            
            }
            
            bitIndex--;
        }

        
    }

    int query(int required){

        BinaryTrieNode* currNode = root;
        int bitIndex = 30;
        int ans = 0;

        while(bitIndex >= 0){

            int mask = 1<<bitIndex;
            int currBit;

            if(isBitSet(required,mask)){
                
                currBit = 1;
                
                if(currNode->one != NULL){
                    currNode = currNode->one;
                    setKthBit(ans,bitIndex);
                }else{
                    currNode = currNode->zero;
                }

            }else{

                currBit = 0;

                if(currNode->zero != NULL){
                    currNode = currNode->zero; 
                }else{
                    currNode = currNode->one;
                    setKthBit(ans,bitIndex);
                }

            }

            bitIndex--;
        }

        return ans;
    }

};


int maxXOR(vector<int>& arr){

    BinaryTrie trie;

    for(int val : arr) trie.insert(val);

    int ans = 0;

    for(int val : arr){
    
        int required = INT_MAX ^ val;
        int currMaxPossible = trie.query(required) ^ val;
        ans = max(ans,currMaxPossible);
    
    }
    
    return ans;
}


int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    int ans = maxXOR(a);
    cout << ans << '\n';
    
}
