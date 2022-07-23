#include <bits/stdc++.h>
using namespace std;


class TreeNode {
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};


class Triplet {
public:
    bool isBST;
    int minm;
    int maxm;
};

Triplet validateBST(TreeNode* root) {
    
    if(root==NULL){
        Triplet t;
        t.isBST = true;
        t.minm = INT_MAX;
        t.maxm = INT_MIN;
        return t;
    }
    Triplet leftCall = validateBST(root->left);
    Triplet rightCall = validateBST(root->right);
    
    int minimum = min(root->val,min(leftCall.minm,rightCall.minm));
    int maximum = max(root->val,max(leftCall.maxm,rightCall.maxm));
    bool isTreeBST = ((root->val > leftCall.maxm) && (root->val < rightCall.minm) && (leftCall.isBST && rightCall.isBST));
    
    Triplet ans;
    ans.isBST = isTreeBST;
    ans.minm = minimum;
    ans.maxm = maximum;
    
    return ans;
    
} 

bool isValidBST(TreeNode *root) {
    return validateBST(root).isBST;
}

TreeNode *createTree(vector<int> &arr, vector<int> &IDX) {

    if (IDX[0] > arr.size() || arr[IDX[0]] == -1){
            IDX[0]++;
            return nullptr;
        }

    TreeNode *node = new TreeNode(arr[IDX[0]++]);
    node->left = createTree(arr, IDX);
    node->right = createTree(arr, IDX);

    return node;
}

void solve() {

    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> IDX(1, 0);
    TreeNode *root = createTree(arr, IDX);
    cout << (boolalpha) << isValidBST(root);
}

int main() {

    solve();
    return 0;

}