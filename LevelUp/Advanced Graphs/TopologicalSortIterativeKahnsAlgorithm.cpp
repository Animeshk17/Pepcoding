#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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

vector<int> topologicalSort(vector<vector<Edge>>& graph, int vertices){
    int* degree = new int[vertices]{0};

    for(int i = 0; i<vertices; i++){
        for(Edge e : graph[i]){
            degree[e.dest]++;
        }
    }

    queue<int> q;
    for(int i = 0; i<vertices; i++){
        if(degree[i]==0) q.push(i);
    }
    int count = 0;
    vector<int> ans;

    while(!q.empty()){
        int currVertex = q.front(); q.pop();
        ans.push_back(currVertex);
        count++;
        for(Edge e : graph[currVertex]){
            degree[e.dest]--;
            if(degree[e.dest]==0) q.push(e.dest);
        }
    }

    if(count==vertices) return ans;
    else return {-1};
}

int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertices,edges;
    cin>>vertices>>edges;

    vector<vector<Edge>> graph(vertices);

    for(int i = 0; i<edges; i++){
        int src,dest,weight=0;
        cin>>src>>dest;
        Edge e1(src,dest,weight);
        graph[src].push_back(e1);
        
    }

    vector<int> ans = topologicalSort(graph,vertices);
    
    for(int v : ans){ 
        cout << v << " ";
    }
    
}