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



void getDfs(vector<vector<Edge>> graph, int startVertex, vector<bool> & visited,vector<int>& currComponent){
    
    visited[startVertex] = true;
    currComponent.push_back(startVertex);

    for(Edge e : graph[startVertex]){
        if(!visited[e.dest]){
            getDfs(graph,e.dest,visited,currComponent);
        }
    }
    
    return ;
}

void getConnectedComponents(vector<vector<Edge>> graph, int vertices, vector<bool> visited,  vector<vector<int>>& connectedComponents){

    for(int i = 0; i<vertices; i++){
        vector<int> currComponent;
        if(!visited[i]) getDfs(graph,i,visited,currComponent);
        if(currComponent.size()) connectedComponents.push_back(currComponent);
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

    vector<bool> visited(vertices,false);
    vector<vector<int>> connectedComponents;
    
    getConnectedComponents(graph,vertices,visited,connectedComponents);
    
    if(connectedComponents.size()==1) cout << "true" << endl;
    else cout << "false" << endl;
    
}