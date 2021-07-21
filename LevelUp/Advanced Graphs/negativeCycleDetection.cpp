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

bool detectNegativeCycle(vector<Edge> edgeList, int vertices){
    int infi = 1000000000;
    vector<int> ans(vertices,infi);
    ans[0] = 0;

    for(int i = 0; i<vertices-1; i++){
        for(int i = 0; i<edgeList.size(); i++){
            int u = edgeList[i].source;
            int v = edgeList[i].dest;
            int wt = edgeList[i].weight;
            if(ans[u]!=infi && ans[u]+wt < ans[v]){
                ans[v] = ans[u] + wt;
            }
        }
    }

    for(int i = 0; i<edgeList.size(); i++){
        int u = edgeList[i].source;
        int v = edgeList[i].dest;
        int wt = edgeList[i].weight;
        if(ans[u]!=infi && ans[u]+wt < ans[v]){
            return true;
        }
    }

    return false;

}


int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertices,edges;
    cin>>vertices>>edges;

    vector<Edge> edgeList;

    for(int i = 0; i<edges; i++){
        int src,dest,weight;
        cin>>src>>dest>>weight;
        Edge e1(src,dest,weight);
        edgeList.push_back(e1);
        
    }

    bool* visited = new bool[vertices]{false};
    bool hasNegativeCycle = false;

    hasNegativeCycle = detectNegativeCycle(edgeList,vertices);

    if(hasNegativeCycle){
        cout << "1" << endk;
    }else{
        cout << "0" << endk;
    }
}