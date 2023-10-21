
// In this code, I will be implementing undirected graph using the idea of adjacency list
// Thus the user is required to input in way of adjacency list

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class graph{
    vector<vector<int>> adj;
    int vertices;
    int edges;
    int size_adj;
public:
    bool add_edge(int x,int y);
    graph(){
        int x,y,n;
        cout<<"Enter no. of vertices"<<endl;
        cin>>vertices;
        size_adj=vertices+1;
        adj.resize(size_adj);
        cout<<"Enter no.of edges"<<endl;
        cin>>n;
        cout<<" Enter edges in pair of vertices "<<endl;
        edges=0;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            add_edge(x,y);
        }
    }
    void add_vertex();
    void remove_edge(int x,int y);
    void remove_vertex(int x);
    void display_graph();
    void check_planarity();
    void get_adjacent_vertices(int x);
    int get_degree(int x);
};

bool graph::add_edge(int x,int y){
    if(x<size_adj&&y<size_adj){
        edges++;
        adj[x].push_back(y);
        adj[y].push_back(x);
        return true;
    }
    else{
        cout<<"Inappropriate input!!"<<endl;
        return false;
    }
}
void graph::add_vertex(){
    vertices++;
    size_adj++;
    adj.resize(size_adj);
}

void graph::remove_edge(int x,int y){
    for(auto it = adj[x].begin();it!= adj[x].end();it++){
        if(*it == y){
            adj[x].erase(it);
            break;
        }
    }
    for(auto it = adj[y].begin();it!= adj[y].end();it++){
        if(*it == x){
            adj[y].erase(it);
            break;
        }
    }
    edges--;
}

void graph::remove_vertex(int x){
    if(x>=size_adj){
        cout<<"Vertex not in the graph"<<endl;
        return;
    }
    for(auto y:adj[x]){
        auto it = find(adj[y].begin(),adj[y].end(),x);
        adj[y].erase(it);
    }
    edges = edges - adj[x].size();
    adj[x].clear();
    vertices--;
}
void graph::display_graph(){
    for(int i=1;i<size_adj;i++){
            if(!adj[i].empty()){
            cout<<i<<": ";
            for(auto x:adj[i]){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
}
void graph::check_planarity(){
    if((3*vertices-6) >= edges)             /* According to Euler's theorem for planar graphs */
        cout<<"Graph is planar"<<endl;
    else
        cout<<"Graph is NOT planar"<<endl;
}
void graph::get_adjacent_vertices(int x){
    cout<<x<<": ";
    for(auto y:adj[x]){
        cout<<y<<" ";
    }
    cout<<endl;
}
int graph::get_degree(int x){
    return adj[x].size();
}
int main()
{
    cout<<"Enter the details about your graph"<<endl;
    graph g;
    cout<<"Graph initiallised successfully !"<<endl;
    int a;
    int x,y;
    while(1)
    {
        cout<<"Choose from below"<<endl;
        cout<<"1. Add an edge"<<endl;
        cout<<"2. Remove an edge"<<endl;
        cout<<"3. Add an vertex"<<endl;
        cout<<"4. Remove a vertex"<<endl;
        cout<<"5. Display the graph"<<endl;
        cout<<"6. Check for Planarity (Euler's Theorem)"<<endl;
        cout<<"7. Display the adjacent nodes of a vertex in a graph"<<endl;
        cout<<"8. Display the degree of a node"<<endl;
        cout<<"9. Exit"<<endl;
        cin>>a;
        switch(a){
        case 1:
            cout<<" Enter edge in pair of vertices"<<endl;
            cin>>x>>y;
            if(g.add_edge(x,y))
                cout<<"Edge Added successfully"<<endl;
            break;
        case 2:
            cout<<" Enter edge in pair of vertices"<<endl;
            cin>>x>>y;
            g.remove_edge(x,y);
            break;
        case 3:
            g.add_vertex();
            break;
        case 4:
            cout<<"Enter the vertex:"<<endl;
            cin>>x;
            g.remove_vertex(x);
            break;
        case 5:
            cout<<"vertex : adjacent vertex"<<endl;
            g.display_graph();
            break;
        case 6:
            g.check_planarity();
            break;
        case 7:
            cout<<"Enter the vertex:"<<endl;
            cin>>x;
            g.get_adjacent_vertices(x);
            break;
        case 8:
            cout<<"Enter the vertex:"<<endl;
            cin>>x;
            cout<<"Degree of node "<<x<<" : "<<g.get_degree(x)<<endl;;
            break;
        case 9:
            cout<<"Thank You!!"<<endl;
            return 0;
        default:
            cout<<"Enter a Valid choice"<<endl;
            break;
        }
    }
    return 0;
}

