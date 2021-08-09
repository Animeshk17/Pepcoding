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

bool hasPath(vector<vector<Edge>> graph, int source , int destination, vector<bool> visited){
    
    if(source==destination) return true;
    
    visited[source] = true;
    vector<Edge> neighboursList = graph[source];
    for(Edge e : neighboursList){
        int neighbour = e.dest;
        if(!visited[neighbour] && hasPath(graph,neighbour,destination,visited)){
            return true;
        }
    }
    
    return false;
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

    int source, destination;
    cin>> source >> destination;

    vector<bool> visited(vertices,false);
    
    bool ans = hasPath(graph,source,destination,visited);
    
    if(ans) cout << "true" << endl;
    else cout << "false" << endl;
}