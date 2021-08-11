#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define vve vector<vector<Edge>>
#define makepair(a,b) make_pair(a,b)
#define pp push_back
#define endk "\n";
#define intmax INT_MAX
#define intmin INT_MIN
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define mod 1000000007
#define tenmax 1000000000
#define all(c) c.begin(), c.end()
#define fo(i,n) for(int i = 0; i<n; i++)
#define f(i,l,r) for(int i = l; i<r ; i++)
#define rf(i,l,r) for(int i = l; i>=r ; i--)
#define setmemo(x) memset(memo,x,sizeof(memo))
#define matrix(N,M) vector < vector < int > > matrix(N, vector < int > (M, -1));

class Edge{

    public:
    int source;
    int dest;
    int weight;
    
    Edge(int source, int dest , int weight){
        this->source = source;
        this->dest = dest;
        this->weight = weight;
    }
};

void getDfs(vector<vector<Edge>>& graph, int startVertex, vector<bool> & visited,vector<int>& allConnectedComponents){
    
    visited[startVertex] = true;
    allConnectedComponents.push_back(startVertex);

    for(Edge e : graph[startVertex]){
        if(!visited[e.dest]){
            getDfs(graph,e.dest,visited,allConnectedComponents);
        }
    }
    
    return ;
}

void getConnectedComponents(vector<vector<Edge>>& graph, int vertices, vector<bool>& visited,  vector<vector<int>>& allConnectedComponents){

    for(int i = 0; i<vertices; i++){
        vector<int> currComponent;
        if(!visited[i]) getDfs(graph,i,visited,currComponent);
        if(currComponent.size()) allConnectedComponents.push_back(currComponent);
    }

}

void printComponents(vector<vector<int>>& allConnectedComponents){

    int n = allConnectedComponents.size();

    for(int i = 0; i<n; i++){
        if(i==0) cout << "[";
        
        cout << "[";
        
        for(int j = 0; j<allConnectedComponents[i].size(); j++){
            cout <<allConnectedComponents[i][j];
            if(j!=allConnectedComponents[i].size()-1) cout << ", ";
        }
        
        cout << "]";
        
        if(i!=n-1) cout << ", ";
        if(i==n-1) cout << "]";
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);


    int vertices,edges;
    cin>>vertices>>edges;

    vector<vector<Edge>> graph(vertices);

    for(int i = 0; i<edges; i++){
        int src,dest,weight;
        cin>>src>>dest>>weight;
        Edge e1(src,dest,weight);
        graph[src].push_back(e1);
        Edge e2(dest,src,weight);
        graph[dest].push_back(e2);
    }

    vector<bool> visited(vertices,false);

    vector<vector<int>> allConnectedComponents;
    getConnectedComponents(graph,vertices,visited,allConnectedComponents);

    printComponents(allConnectedComponents);
    
}