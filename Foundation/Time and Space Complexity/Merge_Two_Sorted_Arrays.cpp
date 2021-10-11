#include<bits/stdc++.h>
using namespace std;

vector<int> mergeTwoSortedArrays(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int i = 0, j = 0;

    while(i < a.size() && j < b.size()){
        if(a[i] <= b[j]){
            ans.push_back(a[i]);
            i++;
        }else{
            ans.push_back(b[j]);
            j++;
        }
    }

    while(i < a.size()) ans.push_back(a[i++]);
    while(j < b.size()) ans.push_back(b[j++]);

    return ans;    
}

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void output(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int n, m;
    cin >> n;

    vector<int> A(n, 0);
    input(A);

    cin >> m;
    
    vector<int> B(m, 0);
    input(B);

    vector<int> ans = mergeTwoSortedArrays(A, B);
    output(ans);
    
    return 0;

}