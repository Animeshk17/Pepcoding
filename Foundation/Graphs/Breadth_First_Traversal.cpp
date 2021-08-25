#include<bits/stdc++.h>
using namespace std;

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

void doBFS(vector<vector<Edge>>& graph, int startVertex, vector<bool>& visited){
    
    queue<pair<vector<Edge>,string>> q;
    pair<vector<Edge>,string> p;
    
    p.first = graph[startVertex];
    p.second = to_string(startVertex);
    
    q.push(p);
    
    while(!q.empty()){
    
        auto curr = q.front();
        q.pop();
    
        int currVertex = curr.first[0].source;
        if(!visited[currVertex]){
    
            cout << currVertex << "@" << curr.second;
            cout << "\n";
            visited[currVertex] = true;
    
        }
    
        for(Edge e : curr.first){
            if(!visited[e.dest]){
                pair<vector<Edge>,string> p;
                p.first = graph[e.dest];
                p.second = curr.second+to_string(e.dest);
                q.push(p);
            }
        }
    }
}


int main(){

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
    
    int startVertex;
    cin>>startVertex;
    
    vector<bool> visited(vertices,false);
    doBFS(graph,startVertex,visited);
    
}