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


bool bfs(vector<vector<Edge>> graph, int startVertex, vector<bool>& visited, int& cycleLength){
    
    queue<vector<Edge>> q;
    q.push(graph[startVertex]);
    
    while(!q.empty()){
    
        vector<Edge> curr = q.front();
        q.pop();
    
        int currVertex = curr[0].source;
    
        if(visited[currVertex]) return true;
        visited[currVertex] = true;
        cycleLength++;
    
        for(Edge e: curr){
            if(!visited[e.dest]) q.push(graph[e.dest]); 
        }

    }

    return false;

}

bool isBipartite(vector<vector<Edge>>& graph){

    int vertices = graph.size();
    int cycleLength = 0;
    
    for(int i = 0; i<vertices; i++){
    
        cycleLength = 0;
        vector<bool> visited(vertices,false);
    
        bool isCyclic = bfs(graph,i,visited,cycleLength);
    
        if(isCyclic){
            if(cycleLength%2) return false;
        }
    
    }

    return true;

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

    bool isGraphBipartite = isBipartite(graph);
  
    if(isGraphBipartite) cout << "true" << "\n";
    else cout << "false" << "\n";

}
