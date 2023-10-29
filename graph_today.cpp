// C++ program to solve Rat in a Maze problem using
// backtracking
#include <bits/stdc++.h>
using namespace std;
// Maze size
#define N 4

bool solveMazeUtil(int maze[N][N], int x, int y,int sol[N][N]);

// A utility function to print solution matrix sol[N][N] 
void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout<<" "<<sol[i][j]<<" ";
		cout<<endl;
	}
}

// A utility function to check if x, y is valid index for
// N*N maze
bool isSafe(int maze[N][N], int x, int y)
{
	// if (x, y outside maze) return false
	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return true;
	return false;
}

// This function solves the Maze problem using Backtracking.
// It mainly uses solveMazeUtil() to solve the problem. It
// returns false if no path is possible, otherwise return
// true and prints the path in the form of 1s. Please note
// that there may be more than one solutions, this function
// prints one of the feasible solutions.
bool solveMaze(int maze[N][N])
{
	int sol[N][N] = { { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } };
	if (solveMazeUtil(maze, 0, 0, sol) == false) {
		cout<<"Solution doesn't exist";
		return false;
	}
	printSolution(sol);
	return true;
}

// A recursive utility function to solve Maze problem
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
	// if (x, y is goal) return true
	if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
		sol[x][y] = 1;
		return true;
	}
	// Check if maze[x][y] is valid
	if (isSafe(maze, x, y) == true) {
		// Check if the current block is already part of
		// solution path.
		if (sol[x][y] == 1)
			return false;
		// mark x, y as part of solution path
		sol[x][y] = 1;
		/* Move forward in x direction */
		if (solveMazeUtil(maze, x + 1, y, sol) == true)
			return true;
		// If moving right didn't work
		// move left
		if (solveMazeUtil(maze, x - 1, y, sol) == true)
			return true;
		// If moving in x direction doesn't give solution
		// then Move down in y direction
		if (solveMazeUtil(maze, x, y + 1, sol) == true)
			return true;
		// If moving down didn't work
		// move up
		if (solveMazeUtil(maze, x, y - 1, sol) == true)
			return true;
		// If none of the above movements work then
		// BACKTRACK: unmark x, y as part of solution path
		sol[x][y] = 0;
		return false;
	}
	return false;
}

// driver program to test above function
int main()
{
	int maze[N][N] = { { 1, 0, 0, 0 },
					{ 1, 1, 0, 1 },
					{ 0, 1, 0, 0 },
					{ 1, 1, 1, 1 } };
	solveMaze(maze);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
// Changes made for N>4 by Ch. Abdul Wasay


// C++ program to solve N Queen Problem using backtracking

#include <bits/stdc++.h>
#define N 4
using namespace std;

// A utility function to print solution
void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<". ";
		printf("\n");
	}
}

// A utility function to check if a queen can
// be placed on board[row][col]. Note that this
// function is called when "col" queens are
// already placed in columns from 0 to col -1.
// So we need to check only left side for
// attacking queens
bool isSafe(int board[N][N], int row, int col)
{
	int i, j;

	// Check this row on left side
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	// Check upper diagonal on left side
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	// Check lower diagonal on left side
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

// A recursive utility function to solve N
// Queen problem
bool solveNQUtil(int board[N][N], int col)
{
	// base case: If all queens are placed
	// then return true
	if (col >= N)
		return true;

	// Consider this column and try placing
	// this queen in all rows one by one
	for (int i = 0; i < N; i++) {
		
		// Check if the queen can be placed on
		// board[i][col]
		if (isSafe(board, i, col)) {
			
			// Place this queen in board[i][col]
			board[i][col] = 1;

			// recur to place rest of the queens
			if (solveNQUtil(board, col + 1))
				return true;

			// If placing queen in board[i][col]
			// doesn't lead to a solution, then
			// remove queen from board[i][col]
			board[i][col] = 0; // BACKTRACK
		}
	}

	// If the queen cannot be placed in any row in
	// this column col then return false
	return false;
}

// This function solves the N Queen problem using
// Backtracking. It mainly uses solveNQUtil() to
// solve the problem. It returns false if queens
// cannot be placed, otherwise, return true and
// prints placement of queens in the form of 1s.
// Please note that there may be more than one
// solutions, this function prints one of the
// feasible solutions.
bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	printSolution(board);
	return true;
}

// Driver program to test above function
int main()
{
	solveNQ();
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)




// Insertion sort in C++

#include <iostream>
using namespace std;

// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

// Driver code
int main() {
  int data[] = {9, 5, 1, 4, 3};
  int size = sizeof(data) / sizeof(data[0]);
  insertionSort(data, size);
  cout << "Sorted array in ascending order:\n";
  printArray(data, size);
}




// bfs to detect cycle

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        // resize the vector to hold `n` elements of type `vector<int>`
        adjList.resize(n);
 
        // add edges to the undirected graph
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
// Node to store vertex and its parent info in BFS
struct Node {
    int v, parent;
};
 
// Perform BFS on the graph starting from vertex `src` and
// return true if a cycle is found in the graph
bool BFS(Graph const &graph, int src, int n)
{
    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(n);
 
    // mark the source vertex as discovered
    discovered[src] = true;
 
    // create a queue for doing BFS and
    // enqueue source vertex
    queue<Node> q;
    q.push({src, -1});
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node and print it
        Node node = q.front();
        q.pop();
 
        // do for every edge (v, u)
        for (int u: graph.adjList[node.v])
        {
            if (!discovered[u])
            {
                // mark it as discovered
                discovered[u] = true;
 
                // construct the queue node containing info
                // about vertex and enqueue it
                q.push({ u, node.v });
            }
 
            // `u` is discovered, and `u` is not a parent
            else if (u != node.parent)
            {
                // we found a cross-edge, i.e., the cycle is found
                return true;
            }
        }
    }
 
    // no cross-edges were found in the graph
    return false;
}
 
int main()
{
    // initialize edges
    vector<Edge> edges =
    {
        {0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {4, 8},
        {4, 9}, {3, 6}, {3, 7}, {6, 10}, {6, 11}, {5, 9}
        // edge {5, 9} introduces a cycle in the graph
    };
 
    // total number of nodes in the graph (0 to 11)
    int n = 12;
 
    // build a graph from the given edges
    Graph graph(edges, n);
 
    // Perform BFS traversal in connected components of a graph
    if (BFS(graph, 0, n)) {
        cout << "The graph contains a cycle";
    }
    else {
        cout << "The graph doesn't contain any cycle";
    }
 
    return 0;
}


//dfs to detect cycle
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
 
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        // resize the vector to hold `n` elements of type `vector<int>`
        adjList.resize(n);
 
        // add edges to the undirected graph
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
// Perform DFS on the graph and returns true if any back-edge is found in the graph
bool DFS(Graph const &graph, int v, vector<bool> &discovered, int parent)
{
    // mark the current node as discovered
    discovered[v] = true;
 
    // do for every edge (v, w)
    for (int w: graph.adjList[v])
    {
        // if `w` is not discovered
        if (!discovered[w])
        {
            if (DFS(graph, w, discovered, v)) {
                return true;
            }
        }
 
        // if `w` is discovered, and `w` is not a parent
        else if (w != parent)
        {
            // we found a back-edge (cycle)
            return true;
        }
    }
 
    // No back-edges were found in the graph
    return false;
}
 
int main()
{
    // initialize edges
    vector<Edge> edges =
    {
        {0, 1}, {0, 6}, {0, 7}, {1, 2}, {1, 5}, {2, 3},
        {2, 4}, {7, 8}, {7, 11}, {8, 9}, {8, 10}, {10, 11}
        // edge (10, 11) introduces a cycle in the graph
    };
 
    // total number of nodes in the graph (0 to 11)
    int n = 12;
 
    // build a graph from the given edges
    Graph graph(edges, n);
 
    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(n);
 
    // Perform DFS traversal from the first vertex
    if (DFS(graph, 0, discovered, -1)) {
        cout << "The graph contains a cycle";
    }
    else {
        cout << "The graph doesn't contain any cycle";
    }
 
    return 0;
}
