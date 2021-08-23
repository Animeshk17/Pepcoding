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

void getHamiltonian(vector<vector<Edge>> graph, int vertices, int source, int& visitCount, vector<bool>& visited,string currPath, vector<string>& allPaths, int originalSource){
    
    if(visitCount==vertices-1){
    
        currPath+=to_string(source);
    
        for(Edge e : graph[source]){
            if(e.dest==originalSource){
                currPath+="*";
                allPaths.push_back(currPath);
                return ;
            }
        }
    
        currPath+=".";
        allPaths.push_back(currPath);
        return; 
    
    }
    
    visited[source] = true;
    visitCount++;
    currPath += to_string(source);
    
    for(Edge e : graph[source]){
        if(!visited[e.dest]){
            getHamiltonian(graph,vertices,e.dest,visitCount,visited,currPath,allPaths,originalSource);
        }
    }
    
    visited[source] = false;
    visitCount--;
    return ;

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

    vector<bool> visited(vertices,false);

    string currPath;
    vector<string> allPaths;

    int visitCount = 0;

    getHamiltonian(graph,vertices,source,visitCount,visited,currPath,allPaths,source);
    
    for(auto path : allPaths){
            cout << path << '\n';
    }
    
}