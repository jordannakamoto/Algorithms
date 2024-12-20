// C++ program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph
#include <iostream>
using namespace std;
#include <limits.h>

// Number of vertices in the graph
#define V 9

// Starting at vertex 0...
// Find the vertex with minimum distance
// from the set of vertices not in spt
int minDistance(int dist[], bool sptSet[])
{

	// Initialize min value
	int min = INT_MAX, min_index;

	// Just loop through all vertices that haven't
	// been added to the SPT and find the minimum
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// Function to print the constructed distance
void printSolution(int dist[])
{
	cout << "Vertex \t Distance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source
// INIT: dist[i] = INT_MAX, sptSet[i] = false;
// inputs: src = entry vertex
// graph = adjacency matrix
void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // The output array. dist[i] will hold the
				// shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is
					// included in shortest
	// path tree or shortest distance from src to i is
	// finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pass the current state of the shortest path tree
		// to the minDistance function
		int u = minDistance(dist, sptSet);

		// Update the spt with the calculated vertex
		sptSet[u] = true;

		// Update dist values of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// A vertex is considered adjacent to u only:
			// if is not in sptSet,
			// if there is an edge from u to v
			// and, importantly, if total distance of path:
			// from src->v through u is smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				{
				dist[v] = dist[u] + graph[u][v];
			}
	}

	// print the constructed distance array
	printSolution(dist);
}

// driver's code
int main()
{
	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	// Function call
	dijkstra(graph, 0);

	return 0;
}

// This code is contributed by shivanisinghss2110
