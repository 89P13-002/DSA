
// In this code, I will be implementing undirected graph using the idea of adjacency list
// Thus the user is required to input in way of adjacency list
// Breadth First Search and Depth First Search are implemented on undirected graphs


#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
    void display_graph();
    void BFS(int x);
    int DFS();
    void DFS_visit(int start,bool visited[]);
    void find_tree();
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
void graph::BFS(int start){
    if(start<size_adj){
        bool visited[vertices+1] = {false};
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while(!q.empty()){
            int y = q.front();
            q.pop();
            cout<<y<<" ";
            for(auto v:adj[y]){
                if(visited[v]==false){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }
    else
        cout<<"Inappropriate Input!!"<<endl;
}
int graph::DFS(){
    int connect = 0;
    bool visited[vertices+1] ={false};
    for(int i=1;i<=vertices;i++){
        if(visited[i] == false){
            DFS_visit(i,visited);
            cout<<endl;
            connect++;
        }
    }
    return (connect>1?connect:0);
}
void graph::DFS_visit(int start,bool visited[]){
    visited[start] = true;
    cout<<start<<" ";
    for(auto v:adj[start]){
        if(visited[v]==false){
            DFS_visit(v,visited);
        }
    }
}
void graph::find_tree(){
    int x = DFS();
    if(x==0 && edges == vertices - 1)
        cout<<"Given graph contains a tree"<<endl;
    else
        cout<<"Given graph does NOT contain a tree"<<endl;
}
int main()
{
    cout<<"Enter the details about your graph"<<endl;
    graph g;
    cout<<"Graph initialized successfully !"<<endl;
    int a;
    int x,y;
    while(1)
    {
        cout<<"Choose from below"<<endl;
        cout<<"1. Add an edge"<<endl;
        cout<<"2. Remove an edge"<<endl;
        cout<<"3. Add an vertex"<<endl;
        cout<<"4. Display the graph"<<endl;
        cout<<"5. Display the Breadth First Search"<<endl;
        cout<<"6. Display the Depth First Search"<<endl;
        cout<<"7. Find the tree in the graph"<<endl;
        cout<<"8. Find all the connected components in a graph"<<endl;
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
            cout<<"vertex : adjacent vertex"<<endl;
            g.display_graph();
            break;
        case 5:
            cout<<"Enter the start node"<<endl;
            cin>>x;
            g.BFS(x);
            break;
        case 6:
            g.DFS();
            break;
        case 7:
            g.find_tree();
            break;
        case 8:
            x = g.DFS();
            cout<<"Total no. of disconnected components in the graph : "<<x<<endl;
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

