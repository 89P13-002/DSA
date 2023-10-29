// C++ program to print all the cycles
// in an undirected graph
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;

// variables to be used
// in both functions
vector<int> graph[N];
vector<vector<int>> cycles;

// Function to mark the vertex with
// different colors for different cycles
void dfs_cycle(int u, int p, int color[], int par[], int& cyclenumber)
{

	// already (completely) visited vertex.
	if (color[u] == 2) {
		return;
	}

	// seen vertex, but was not completely visited -> cycle detected.
	// backtrack based on parents to find the complete cycle.
	if (color[u] == 1) {
		vector<int> v;
		cyclenumber++;
		
		int cur = p;
		v.push_back(cur);

		// backtrack the vertex which are
		// in the current cycle thats found
		while (cur != u) {
			cur = par[cur];
			v.push_back(cur);
		}
		cycles.push_back(v);
		return;
	}
	par[u] = p;

	// partially visited.
	color[u] = 1;

	// simple dfs on graph
	for (int v : graph[u]) {

		// if it has not been visited previously
		if (v == par[u]) {
			continue;
		}
		dfs_cycle(v, u, color, par, cyclenumber);
	}

	// completely visited.
	color[u] = 2;
}

// add the edges to the graph
void addEdge(int u, int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

// Function to print the cycles
void printCycles(int& cyclenumber)
{

	// print all the vertex with same cycle
	for (int i = 0; i < cyclenumber; i++) {
		// Print the i-th cycle
		cout << "Cycle Number " << i + 1 << ": ";
		for (int x : cycles[i])
			cout << x << " ";
		cout << endl;
	}
}

// Driver Code
int main()
{

	// add edges
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(3, 4);
	addEdge(4, 6);
	addEdge(4, 7);
	addEdge(5, 6);
	addEdge(3, 5);
	addEdge(7, 8);
	addEdge(6, 10);
	addEdge(5, 9);
	addEdge(10, 9);
	addEdge(10, 11);
	addEdge(11, 12);
	addEdge(11, 13);
	addEdge(12, 13);


	// arrays required to color the
	// graph, store the parent of node
	int color[N];
	int par[N];

	// store the numbers of cycle
	int cyclenumber = 0;
	int edges = 6;

	// call DFS to mark the cycles
	dfs_cycle(1, 0, color, par, cyclenumber);

	// function to print the cycles
	printCycles(cyclenumber);
}




// CPP program to find single cycle components
// in a graph.
#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

// degree of all the vertices
int degree[N];

// to keep track of all the vertices covered 
// till now
bool found[N];

// all the vertices in a particular 
// connected component of the graph
vector<int> curr_graph;

// adjacency list
vector<int> adj_list[N];

// depth-first traversal to identify all the
// nodes in a particular connected graph 
// component
void DFS(int v)
{
	found[v] = true;
	curr_graph.push_back(v);
	for (int it : adj_list[v])
		if (!found[it])
			DFS(it);
}

// function to add an edge in the graph
void addEdge(vector<int> adj_list[N], int src,
			int dest)
{
	// for index decrement both src and dest.
	src--, dest--;
	adj_list[src].push_back(dest);
	adj_list[dest].push_back(src);
	degree[src]++;
	degree[dest]++;
}

int countSingleCycles(int n, int m)
{
	// count of cycle graph components
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (!found[i]) {
			curr_graph.clear();
			DFS(i);

			// traversing the nodes of the
			// current graph component
			int flag = 1;
			for (int v : curr_graph) {
				if (degree[v] == 2)
					continue;
				else {
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				count++;
			}
		}
	}
	return(count);
}

int main()
{
	// n->number of vertices
	// m->number of edges
	int n = 15, m = 14;
	addEdge(adj_list, 1, 10);
	addEdge(adj_list, 1, 5);
	addEdge(adj_list, 5, 10);
	addEdge(adj_list, 2, 9);
	addEdge(adj_list, 9, 15);
	addEdge(adj_list, 2, 15);
	addEdge(adj_list, 2, 12);
	addEdge(adj_list, 12, 15);
	addEdge(adj_list, 13, 8);
	addEdge(adj_list, 6, 14);
	addEdge(adj_list, 14, 3);
	addEdge(adj_list, 3, 7);
	addEdge(adj_list, 7, 11);
	addEdge(adj_list, 11, 6);

	cout << countSingleCycles(n, m);

	return 0;
}
