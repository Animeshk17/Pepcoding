#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
    int src;
    int dest;

    Edge(int src, int dest){
        this->src = src;
        this->dest = dest;
    }

};


void topologicalSort(vector<vector<Edge>>& graph, int startVertex, bool* visited, stack<int>& stck){
    
    visited[startVertex] = true;
    
    for(Edge neighbour : graph[startVertex]){
        if(!visited[neighbour.dest]) topologicalSort(graph,neighbour.dest,visited,stck);
    }
    
    stck.push(startVertex);
}

int main(){

    int vertices,edges;
    cin>>vertices>>edges;

    vector<vector<Edge>> graph(vertices);

    for(int i = 0; i<edges; i++){

        int source,destination;
        cin>>source>>destination;

        Edge e(source,destination);
        graph[source].push_back(e);
    
    }

    bool* visited = new bool[vertices]{false};
    stack<int> stck;

    for(int i = 0; i<vertices; i++){

        if(!visited[i]){
            topologicalSort(graph,i,visited,stck);
        }

    }
    
    while(!stck.empty()){
    
        cout <<  stck.top() << "\n";
        stck.pop();
    
    }

}