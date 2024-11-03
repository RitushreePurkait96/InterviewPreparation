#include <iostream>
#include <vector>
using namespace std;

// Recursive method to find DFS
void DFSRec(vector<vector<int>>& adj, vector<bool>& visited, int source)
{
	visited[source] = true; // Mark the source or starting point as visited
	cout << source << "-->";
	
	// Recursively visit all adjacent vertices
    // that are not visited yet
	for(int i : adj[source])
	{
		if(visited[i] == false)
		{
			DFSRec(adj, visited, i);
		}
	}
	
}

// DFS from source vertex
void DFS(vector<vector<int>>& adj, int source)
{
	vector<bool> visited(adj.size(), false); // Mark all the vertices as not visited
	// Call Recursive DFS find method
	DFSRec(adj, visited, source);
}

// Adds edges between sorce and destination vertex
void addEdge(vector<vector<int>>& adj, int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

int main() {

	int v = 5;
	vector<vector<int>> adj(v);
	
	vector<vector<int>> edges = {{1, 2},{1, 0},{2, 0},{2, 3},{2, 4}};
	for(auto& edge : edges)
	{
		addEdge(adj, edge[0], edge[1]);
	}
	// source
	int source = 1;
	
	// DFS from source 1
	DFS(adj,source);
	return 0;
}
