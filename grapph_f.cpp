#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class graph{
    int vertx_num;
    int edg_num;
    vector<vector<int>> adj_mat;
    vector <vector<int>> adj_ls;
    public:
    graph(int v,int e);
    void input();
    void adj_mat_print();
    void adj_list_print();
    void BFS(int);
    void dfs(int,bool* ,vector <pair<int,int>> &);
    void DFS();
    bool cycle(int i);
};
graph :: graph(int v,int e){
    vertx_num = v;
    edg_num = e;
    adj_mat.resize(vertx_num+1);
    for(int i=0;i<vertx_num+1;i++){
        for(int j=0;j<vertx_num+1;j++){
            adj_mat[i].push_back(0);
        }
    }
    //vector<vector<int>> adj_mat(vertx_num+1 , vector<int> (vertx_num+1, 0));
    adj_ls.resize(vertx_num+1);
}
bool graph :: cycle(int i){
    static vector<bool> visited (vertx_num+1,false);
    static int j = 0;
    visited[i] = true;
    for(auto x : adj_ls[i]){
            if(visited[x] && j>2){
                return true;
            }
            j++;
            if(!visited[x] && cycle(x)){
                return true;
            }
        
    }
    return false;
}
void graph :: DFS(){
    vector <pair<int,int>> order;
    bool visited[vertx_num+1] = {false};
    int st;
    cout<<"Enter the start vertex"<<endl;
    cin>>st;
    order.push_back(make_pair(st,0));
    dfs(st,visited,order);
    cout<<endl;
    int i;
    for(i=0;i<order.size();i++){
        cout<<order[i].first<<" "<<order[i].second<<endl;
    }
    return ;
}
void graph :: dfs(int st,bool* v,vector <pair<int,int>> &o){
    v[st] = true;
    cout<<st<<" "; //start to end me
    for(auto x:adj_ls[st]){
        if(v[x]==false){
            o.push_back(make_pair(x,st));
            dfs(x,v,o);
        }
    }
    //cout<<st<<" "; //last to start then
}
void graph :: BFS(int st){
    vector <pair<int,int>> order;
    bool visited[vertx_num+1] = {false};
    queue<int> q;
        visited[st] = true;
        q.push(st);
        q.push(-1);
        order.push_back(make_pair(st,0));
        order.push_back(make_pair(-1,-1));
        cout<<"BFS order traversal"<<endl;
        int j = 0;
        while(!q.empty() && j<(vertx_num+1)){
            int y = q.front();
            q.pop();
            if(y == -1){
                q.push(-1);
                j++;
                continue;
            }
            cout<<y<<" ";
            for(auto v:adj_ls[y]){
                if(visited[v]==false){
                    visited[v]=true;
                    q.push(v);
                    order.push_back(make_pair(v,y));
                }
            }
            order.push_back(make_pair(-1,-1));
        }
        cout<<endl;
        int i;
        for(i=0;i<order.size();i++){
            if(order[i].first == -1){
                continue;
            }
            cout<<order[i].first<<" "<<order[i].second<<endl;
        }
        cout<<endl;
        return ;
        
}
void graph :: adj_list_print(){
    cout<<"Your adjecency list"<<endl;
    int i;
    for(i=0;i<adj_ls.size();i++){
        cout<<i<<" -> ";
        for(auto x : adj_ls[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return ;
}
void graph :: input(){
    int i,x,y;
    //cout<<"Enter edges"<<endl;
    //vector<vector<int>> adj_mat(vertx_num+1 , vector<int> (vertx_num+1, 0));
    for(i=0;i<edg_num;i++){
        cin>>x;
        cin>>y;
        adj_mat[x][y] = 1;
        adj_mat[y][x] = 1;
        adj_ls[x].push_back(y);
        adj_ls[y].push_back(x);
    }
    for(i=1;i<vertx_num;i++){
        // sort(adj_ls[i].begin(),adj_ls[i].end(), greater<int>());
        sort(adj_ls[i].begin(),adj_ls[i].end());
    }
    return ;
}

void graph :: adj_mat_print(){
    cout<<"Adjeceny matrix "<<endl;
    int i,j;
    for(i=1;i<adj_mat.size();i++){
        for(j=1;j<adj_mat.size();j++){
            cout<<adj_mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return ;
}
int main(){
    int vertex_num,edge_num;
    cout<<"Enter total vertex and edge "<<endl;
    cin>>vertex_num>>edge_num;
    graph* g;
    g = new graph(vertex_num,edge_num);
    g->input(); 
    // if(g->cycle(2)){
    //     cout<<"sjdnf"<<endl;
    // }
    g->adj_list_print();
    g->adj_mat_print();
    int t;
    cout<<"Enter start"<<endl;
    cin>>t;
    g->BFS(t);
    g->DFS();
    return 0;
}


// bfs by adj_matrix
// C++ implementation of the approach
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;


// function to add edge to the graph
void addEdge(int x,int y)
{
	adj[x][y] = 1;
	adj[y][x] = 1;
}

// Function to perform BFS on the graph
void bfs(int start)
{
	// Visited vector to so that
	// a vertex is not visited more than once
	// Initializing the vector to false as no
	// vertex is visited at the beginning
	vector<bool> visited(adj.size(), false);
	vector<int> q;
	q.push_back(start);

	// Set source as visited
	visited[start] = true;

	int vis;
	while (!q.empty()) {
		vis = q[0];

		// Print the current node
		cout << vis << " ";
		q.erase(q.begin());

		// For every adjacent vertex to the current vertex
		for (int i = 0; i < adj[vis].size(); i++) {
			if (adj[vis][i] == 1 && (!visited[i])) {

				// Push the adjacent node to the queue
				q.push_back(i);

				// Set
				visited[i] = true;
			}
		}
	}
}

// Driver code
int main()
{
// number of vertices
int v = 5;


// adjacency matrix
adj= vector<vector<int>>(v,vector<int>(v,0));

addEdge(0,1);
addEdge(0,2);
addEdge(1,3);

// perform bfs on the graph
bfs(0);
}


// dfs by adj_mat
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// adjacency matrix
vector<vector<int> > adj;

// function to add edge to the graph
void addEdge(int x, int y)
{
	adj[x][y] = 1;
	adj[y][x] = 1;
}

// function to perform DFS on the graph
void dfs(int start, vector<bool>& visited)
{

	// Print the current node
	cout << start << " ";

	// Set current node as visited
	visited[start] = true;

	// For every node of the graph
	for (int i = 0; i < adj[start].size(); i++) {

		// If some node is adjacent to the current node
		// and it has not already been visited
		if (adj[start][i] == 1 && (!visited[i])) {
			dfs(i, visited);
		}
	}
}

int main()
{
	// number of vertices
	int v = 5;

	// number of edges
	int e = 4;

	// adjacency matrix
	adj = vector<vector<int> >(v, vector<int>(v, 0));

	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(0, 3);
	addEdge(0, 4);

	// Visited vector to so that
	// a vertex is not visited more than once
	// Initializing the vector to false as no
	// vertex is visited at the beginning
	vector<bool> visited(v, false);

	// Perform DFS
	dfs(0, visited);
}



// cycle in graph
// A C++ Program to detect
// cycle in an undirected graph
#include <iostream>
#include <limits.h>
#include <list>
using namespace std;

// Class for an undirected graph
class Graph {

	// No. of vertices
	int V;

	// Pointer to an array
	// containing adjacency lists
	list<int>* adj;
	bool isCyclicUtil(int v, bool visited[], int parent);

public:
	// Constructor
	Graph(int V);

	// To add an edge to graph
	void addEdge(int v, int w);

	// Returns true if there is a cycle
	bool isCyclic();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{

	// Add w to v’s list.
	adj[v].push_back(w);

	// Add v to w’s list.
	adj[w].push_back(v);
}

// A recursive function that
// uses visited[] and parent to detect
// cycle in subgraph reachable
// from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{

	// Mark the current node as visited
	visited[v] = true;

	// Recur for all the vertices
	// adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i) {

		// If an adjacent vertex is not visited,
		// then recur for that adjacent
		if (!visited[*i]) {
			if (isCyclicUtil(*i, visited, v))
				return true;
		}

		// If an adjacent vertex is visited and
		// is not parent of current vertex,
		// then there exists a cycle in the graph.
		else if (*i != parent)
			return true;
	}
	return false;
}

// Returns true if the graph contains
// a cycle, else false.
bool Graph::isCyclic()
{

	// Mark all the vertices as not
	// visited and not part of recursion
	// stack
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper
	// function to detect cycle in different
	// DFS trees
	for (int u = 0; u < V; u++) {

		// Don't recur for u if
		// it is already visited
		if (!visited[u])
			if (isCyclicUtil(u, visited, -1))
				return true;
	}
	return false;
}

// Driver program to test above functions
int main()
{
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.isCyclic() ? cout << "Graph contains cycle\n"
				: cout << "Graph doesn't contain cycle\n";

	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.isCyclic() ? cout << "Graph contains cycle\n"
				: cout << "Graph doesn't contain cycle\n";

	return 0;
}
