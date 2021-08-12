#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    bool isTerminal;
    TrieNode** children;
    
    TrieNode(){
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{

    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void insert(string& word){

        TrieNode* curr = root;
        
        for(char &ch : word){
            int index = ch-'a';
            if(curr->children[index]==NULL){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }

        curr->isTerminal = true;

    }

    bool search(string& word){

        TrieNode* curr = root;

        for(char &ch : word){
            int index = ch - 'a';
            if(curr->children[index]==NULL) return false;
            curr = curr->children[index];
        }

        return curr->isTerminal;

    }

    bool startsWith(string& word){
        
        TrieNode* curr = root;

        for(char &ch : word){
            int index = ch - 'a';
            if(curr->children[index]==nullptr) return false;
            curr = curr->children[index];
        }

        return true;
    }
};

int main(){
    
    Trie* t = new Trie();

    string command, word;

    while(cin>>command){
        
        cin>>word;

        if(command=="insert"){

            t->insert(word);
        
        }else if(command=="search"){
        
            bool found = t->search(word);
            if(found) cout << "true" << endl;
            else cout << "false" << endl;
        
        }else if(command=="startsWith"){

            bool result = t->startsWith(word);
            if(result) cout << "true" << endl;
            else cout << "false" << endl;

        }
    }
}