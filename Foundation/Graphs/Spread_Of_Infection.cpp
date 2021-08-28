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



int bfs(vector<vector<Edge>> graph, int source, int time, vector<bool>& visited){
    
    int infectedCount = 0;
    
    queue<pair<vector<Edge>,int>> q;
    q.push(make_pair(graph[source],1));
    
    while(!q.empty()){
    
        vector<Edge> curr = q.front().first;
        int level = q.front().second;
    
        q.pop();
    
        int currVertex = curr[0].source;
    
        if(!visited[currVertex]){
            if(level>time) break;
            infectedCount++;  
        } 
    
        visited[currVertex] = true;
    
        for(Edge e: curr){
            if(!visited[e.dest]) q.push(make_pair(graph[e.dest],level+1));
        }
    
    }
    
    return infectedCount;

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
    
    int source;
    cin>>source;
    
    int time;
    cin>>time;
    
    vector<bool> visited(vertices,false);
    
    int infectedCount = bfs(graph,source,time,visited);
    cout << infectedCount << "\n";
    
}