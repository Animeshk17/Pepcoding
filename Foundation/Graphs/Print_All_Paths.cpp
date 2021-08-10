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

void printAllPaths(vector<vector<Edge>>& graph, int source, int destination, vector<bool>& visited, string currPath){
    
    if(source==destination){
        cout << currPath << destination << endk;
        return ;
    }

    visited[source] = true;
    vector<Edge> neighbours = graph[source];

    for(Edge e : neighbours){
        if(!visited[e.dest]){
            printAllPaths(graph,e.dest,destination,visited,currPath+to_string(e.source));
        }
    }

    visited[source] = false;
    return ;
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

    int source, destination;
    cin>>source>>destination;

    printAllPaths(graph,source,destination,visited,"");       
    
}