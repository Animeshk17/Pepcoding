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

void doDFS(vector<vector<Edge>> graph,int source, vector<bool>& visited, vector<int>& currComp){
    
    visited[source] = true;
    currComp.push_back(source);
    
    for(Edge e : graph[source]){
        int neighbour = e.dest;
        if(!visited[neighbour]) doDFS(graph,neighbour,visited, currComp);
    }

}

void getConnectedComponent(vector<vector<Edge>> graph, int vertices, vector<bool>& visited, vector<int>& lengthOfComponents){
    for(int i = 0;  i<vertices; i++){
        if(!visited[i]){
            vector<int> dfsArr;
            doDFS(graph,i,visited,dfsArr);
            lengthOfComponents.push_back(dfsArr.size());
        }
    }
}

int main(){

    int vertices,edges;
    cin>>vertices>>edges;
    
    vector<vector<Edge>> graph(vertices);

    for(int i = 0; i<edges; i++){
    
        int src,dest;
        cin>>src>>dest;
    
        Edge e1(src,dest);
        graph[src].push_back(e1);
    
        Edge e2(dest,src);
        graph[dest].push_back(e2);
    
    }

    vector<bool> visited(vertices,false);
    vector<int> lengthOfComponents;
    
    getConnectedComponent(graph,vertices,visited,lengthOfComponents);

    int ans = 0;
    for(int i = 0; i<lengthOfComponents.size()-1; i++){
        for(int j = i+1; j<lengthOfComponents.size(); j++){
            ans += (lengthOfComponents[i]*lengthOfComponents[j]);
        }
    }

    cout << ans << '\n';
}