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


class Node{
    
    public:
    int vertex;
    string path;

    Node(int vertex, string path){
        this->vertex = vertex;
        this->path = path;
    }
    
};


void iterativeDFS(vector<vector<Edge>> graph, int source, bool* visited){
    
    stack<Node> st;
    Node t(source,to_string(source));
    st.push(t);
    
    while(!st.empty()){
    
        Node curr = st.top();
        int currVertex = curr.vertex;
        st.pop();

        if(!visited[currVertex]){
    
            visited[currVertex] = true;
            cout << curr.vertex << "@" << curr.path << "\n";
    
        }
        
        vector<Edge> neighbours = graph[currVertex];

        for(Edge e : neighbours){
    
            if(!visited[e.dest]){
                Node temp(e.dest,curr.path+to_string(e.dest));
                st.push(temp);
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

    bool* visited = new bool[vertices];
    
    int source;
    cin>>source;
    
    iterativeDFS(graph,source,visited);
}