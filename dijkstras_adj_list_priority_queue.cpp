/*
1) Initialize distances of all vertices as infinite.
2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or 
   distance) is used  as first item  of pair
   as first item is by default used to compare
   two pairs
3) Insert source vertex into pq and make its
   distance as 0.
4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do 
       following for every vertex v.
           // If there is a shorter path to v
           // through u. 
           If dist[v] > dist[u] + weight(u, v)
               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)
               
5) Print distance array dist[] to print all shortest
   paths. 
NOTE: here we can use vector<pair<int, int>> as well instead of list<pair<int, int>>
*/

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <functional>
#include <climits>

using namespace std;

#define INF INT_MAX

typedef pair<int, int> iPair; // pair of integers to strore node and distance

class Graph
{
	private:
		int V; // Number of nodes
		vector<list<iPair>> adj; // Adjacency list rep. of graph
	
	public:
		Graph(int V) : V(V)
		{
			adj.resize(V); // Resizing the adjacency list based on the number of vertices
		}
	
		void addEdge(int u, int v, int weight);
		void shortestPath(int source);
};

void Graph :: addEdge( int u, int v, int weight)
{
	adj[u].push_back(make_pair(v, weight));
	adj[v].push_back(make_pair(u, weight));
} 

void Graph ::  shortestPath(int source)
{
	priority_queue<iPair, vector<iPair>, greater<iPair>> min_heap_dist_pq;
	vector<int> dist(V, INF);
	
	dist[0] = source;
	min_heap_dist_pq.push(make_pair(0, source)); // .first => dist .second => node
	
	
	while(!min_heap_dist_pq.empty())
	{
		auto u = min_heap_dist_pq.top().second; // pick up the node with minimum distance
		
		min_heap_dist_pq.pop(); // remove as already visited now
		
		for(const auto& neighbour : adj[u])
		{
			int v = neighbour.first; // neighbour node
			int weight = neighbour.second; // weight of the node
			
			if(dist[v] > (dist[u] + weight))
			{
				dist[v] = dist[u] + weight;
				min_heap_dist_pq.push(make_pair(dist[v], v));
			}
		}
	}
	 // Print the shortest distances from the source vertex
    cout << "Vertex Distance from Source (" << source << "):\n";
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INF)
            cout << i << " \t\t INF\n";  // If distance is still INF, the node is unreachable
        else
            cout << i << " \t\t " << dist[i] << "\n";
    }

}

int main() {
	int V = 9;
    Graph g(V);

    // making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}

output:
Vertex Distance from Source (0):
0 		 0
1 		 4
2 		 12
3 		 19
4 		 21
5 		 11
6 		 9
7 		 8
8 		 14

/*
Time complexity : O(E log V)

Space Complexity:O(V2) , here V is number of Vertices.
*/
