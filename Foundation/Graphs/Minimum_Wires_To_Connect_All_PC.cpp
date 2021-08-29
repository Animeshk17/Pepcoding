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


class Triplet{

    public:
    int vertex;
    int acquiredThrough;
    int weight;

    Triplet(int vertex, int acquiredThrough, int weight){
    
        this->vertex = vertex;
        this->acquiredThrough = acquiredThrough;
        this->weight = weight;
    
    }

};

struct compare{
    bool operator()(Triplet p, Triplet q){
        if(p.weight > q.weight) return true;
        return false;
    }
};

void minmSpanningTree(vector<vector<Edge>>& graph, int vertices, bool* visited){

    priority_queue<Triplet,vector<Triplet>,compare> pq;
    Triplet t(0,-1,0);
    pq.push(t);
    
    while(!pq.empty()){
        Triplet curr = pq.top();
        pq.pop();

        if(visited[curr.vertex]==true) continue;
        visited[curr.vertex] = true;

        if(curr.acquiredThrough!=-1) cout << "[" << curr.vertex << "-" << curr.acquiredThrough << "@" << curr.weight << "]" << endl;

        for(Edge neighbour : graph[curr.vertex]){
            if(!visited[neighbour.dest]){
                Triplet t(neighbour.dest,curr.vertex,neighbour.weight);
                pq.push(t);
                visited[neighbour.source] = true;
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
        Edge e2(dest,src,weight);
        graph[src].push_back(e1);
        graph[dest].push_back(e2);
    }

    bool* visited = new bool[vertices]{false};

    minmSpanningTree(graph,vertices,visited);

}