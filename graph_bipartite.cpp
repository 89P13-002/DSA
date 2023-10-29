//for both connected and disconnected
#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<int> adj[])
{
	// vector to store colour of vertex
	// assigning all to -1 i.e. uncoloured
	// colours are either 0 or 1
	// for understanding take 0 as red and 1 as blue
	vector<int> col(V, -1);

	// queue for BFS storing {vertex , colour}
	queue<pair<int, int> > q;

	//loop incase graph is not connected
	for (int i = 0; i < V; i++) {
	
	//if not coloured
		if (col[i] == -1) {
		
		//colouring with 0 i.e. red
			q.push({ i, 0 });
			col[i] = 0;
		
			while (!q.empty()) {
				pair<int, int> p = q.front();
				q.pop();
			
				//current vertex
				int v = p.first;
				//colour of current vertex
				int c = p.second;
				
				//traversing vertexes connected to current vertex
				for (int j : adj[v]) {
				
					//if already coloured with parent vertex color
					//then bipartite graph is not possible
					if (col[j] == c)
						return 0;
				
					//if uncoloured
					if (col[j] == -1) {
					//colouring with opposite color to that of parent
						col[j] = (c) ? 0 : 1;
						q.push({ j, col[j] });
					}
				}
			}
		}
	}
	//if all vertexes are coloured such that 
	//no two connected vertex have same colours
	return 1;
}


// { Driver Code Starts.
int main()
{

	int V, E;
	V = 4 , E = 8;
	//adjacency list for storing graph
	vector<int> adj[V];
	adj[0] = {1,3};
	adj[1] = {0,2};
	adj[2] = {1,3};
	adj[3] = {0,2};
	

	bool ans = isBipartite(V, adj);
	//returns 1 if bipartite graph is possible
	if (ans)
		cout << "Yes\n";
	//returns 0 if bipartite graph is not possible
	else
		cout << "No\n";

	return 0;
}
// code Contributed By Devendra Kolhe



// when adj matrix
// C++ program to find out whether
// a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <bits/stdc++.h>

using namespace std;

const int V = 4;

// This function returns true if
// graph G[V][V] is Bipartite, else false
bool isBipartiteUtil(int G[][V], int src, int colorArr[])
{
	colorArr[src] = 1;

	// Create a queue (FIFO) of vertex numbers a
	// nd enqueue source vertex for BFS traversal
	queue<int> q;
	q.push(src);

	// Run while there are vertices in queue (Similar to
	// BFS)
	while (!q.empty()) {
		// Dequeue a vertex from queue ( Refer
		// http://goo.gl/35oz8 )
		int u = q.front();
		q.pop();

		// Return false if there is a self-loop
		if (G[u][u] == 1)
			return false;

		// Find all non-colored adjacent vertices
		for (int v = 0; v < V; ++v) {
			// An edge from u to v exists and
			// destination v is not colored
			if (G[u][v] && colorArr[v] == -1) {
				// Assign alternate color to this
				// adjacent v of u
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}

			// An edge from u to v exists and destination
			// v is colored with same color as u
			else if (G[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}

	// If we reach here, then all adjacent vertices can
	// be colored with alternate color
	return true;
}

// Returns true if G[][] is Bipartite, else false
bool isBipartite(int G[][V])
{
	// Create a color array to store colors assigned to all
	// vertices. Vertex/ number is used as index in this
	// array. The value '-1' of colorArr[i] is used to
	// indicate that no color is assigned to vertex 'i'.
	// The value 1 is used to indicate first color is
	// assigned and value 0 indicates second color is
	// assigned.
	int colorArr[V];
	for (int i = 0; i < V; ++i)
		colorArr[i] = -1;

	// This code is to handle disconnected graph
	for (int i = 0; i < V; i++)
		if (colorArr[i] == -1)
			if (isBipartiteUtil(G, i, colorArr) == false)
				return false;

	return true;
}

// Driver code
int main()
{
	int G[][V] = { { 0, 1, 0, 1 },
				{ 1, 0, 1, 0 },
				{ 0, 1, 0, 1 },
				{ 1, 0, 1, 0 } };

	isBipartite(G) ? cout << "Yes" : cout << "No";
	return 0;
}
