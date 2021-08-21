#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define makepair(a,b) make_pair(a,b)
#define pp push_back
#define endk "\n";
#define intmax INT_MAX
#define intmin INT_MIN
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define mod 1000000007
#define tenmax 1000000000
#define charToDigit(ch) ch-'0'
#define digitToChar(n) char(n+'0')
#define all(c) c.begin(), c.end()
#define fo(i,n) for(int i = 0; i<n; i++)
#define f(i,l,r) for(int i = l; i<r ; i++)
#define rf(i,l,r) for(int i = l; i>=r ; i--)
#define setmemo(x) memset(memo,x,sizeof(memo))
#define takeArrayInput(a,n) fo(i,n) cin>>a[i];
#define matrix(N,M) vector < vector < int > > matrix(N, vector < int > (M, -1));

void getConnectedComponents(int** graph,int vertices, int i, int j, vector<vector<bool>>& visited){  // this fn will bring all connected pieces of land 
    
    if(i<0 || j<0 || i>= vertices || j>=vertices || graph[i][j]==1 || visited[i][j]==true) return;  
    
    visited[i][j] = true;

    getConnectedComponents(graph,vertices,i-1,j,visited);
    getConnectedComponents(graph,vertices,i,j+1,visited);
    getConnectedComponents(graph,vertices,i,j-1,visited);
    getConnectedComponents(graph,vertices,i+1,j,visited);

}

int totalIslands(int** graph, int vertices,vector<vector<bool>>& visited){
    int count = 0;

    for(int i = 0; i<vertices; i++){
        for(int j = 0; j<vertices; j++){
            if(graph[i][j]==0 && !visited[i][j]){
                getConnectedComponents(graph,vertices,i,j,visited);
                count++;
            }
        }
    }

    return count;
}

int main(){

    int m,n;
    cin>>m>>n;

    int** graph = new int*[m];

    fo(i,n){
        graph[i] = new int[n];
        fo(j,n) cin>>graph[i][j];
    }
    
    vector<vector<bool>> visited(n,vector<bool>(n,false));

    int numOfIslands = totalIslands(graph,n,visited);
    cout << numOfIslands << endk;
}