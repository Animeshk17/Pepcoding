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

class Duple{
public:
    int vertex;
    int weight;

    Duple(){}

    Duple(int vertex, int weight){
        this->vertex = vertex;
        this->weight = weight;
    }

};

int zeroOneBFS(vector<vector<Edge>>& graph, int vertices, bool* visited){
    int count = -1;
    list<Duple> l;
    l.push_front(Duple(0,0));
    while(!l.empty()){
        auto curr = l.front();
        l.pop_front();
        if(!visited[curr.vertex]){
            visited[curr.vertex] = true;
            if(curr.vertex==vertices-1) count = curr.weight;
            vector<Edge> neighbours = graph[curr.vertex];
            for(Edge e : neighbours){
                if(!visited[e.dest]){
                    if(e.weight==0){
                        l.push_front(Duple(e.dest,curr.weight+0));
                    }else{
                        l.push_back(Duple(e.dest,curr.weight+e.weight));
                    }
                }
            }
        }
    }
    return count;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertices,edges;
    cin>>vertices>>edges;

    vector<vector<Edge>> graph(vertices);

    for(int i = 0; i<edges; i++){
        int src,dest,weight = 0;
        cin>>src>>dest;
        Edge e1(src-1,dest-1,weight);
        graph[src-1].push_back(e1);
        Edge e2(dest-1,src-1,weight+1);
        graph[dest-1].push_back(e2);
    }

    bool* visited = new bool[vertices]{false};

    int minmReversals = zeroOneBFS(graph,vertices,visited);

    cout << minmReversals << endk;
    
}