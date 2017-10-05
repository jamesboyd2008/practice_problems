/* File: Dijkstra_adjMatrix.cpp
A C / C++ program for Dijkstra's single source shortest path algorithm.
It only computes distances, but doesn't calculate path information.
You can create a parent array, update the parent array when the distance is
updated, and use it to show the shortest path from the source to different vertices.
Uses an adjacency matrix representation of a graph.
Time Complexity: O(V^2)
http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
Downloaded 10/12/16 -MRP
*/

#include <stdio.h>
#include <limits.h>  // use INT_MAX to represent infinity
#include <vector>
#include <iostream>
using namespace std;

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[], int n)
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
	int dist[V];     // The output array.  dist[i] will hold the shortest
					 // distance from src to i

	bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
					// path tree or shortest distance from src to i is finalized

					// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++)
	{
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to  v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist, V);
}

// driver program to test above function
int main()
{
	int numLoc, edge;
	vector<int> items;

	// int **ary = new int*[numLoc];
	// for (int i = 0; i < numLoc; ++i) {
	// 	ary[i] = new int[numLoc];
	// }

  // get city data

  int locationsQuantity;

  // read in first line of input, the number of locations
  cin >> locationsQuantity;

  // create array of locations
  int *locations = new int[locationsQuantity];

  for(int location_i = 0; location_i < locationsQuantity; location_i++)
  {
    // read in 2nd line. get all the locations. Shove them into an array.
    cin >> locations[location_i];
  }

  int roadQuantity;
  // read in 3rd line: number of roads
  cin >> roadQuantity;

  // initialize a 2D dynamic array of all the roads
  int **roads = new int*[roadQuantity];
  for (int road_i = 0; road_i < roadQuantity; road_i++)
  {
    roads[road_i] = new int[3];
  }

  // read in all roads
  for (int road_i = 0; road_i < roadQuantity; road_i++)
  {
    // starting location
    cin >> roads[road_i][0];
    // distance between locations
    cin >> roads[road_i][1];
    // ending location
    cin >> roads[road_i][2];
  }

/*
Example input:
6
1 1 2 3 1 0
7
1 2 2
2 3 3
3 6 4
1 4 4
4 3 2
4 5 3
5 6 2
*/
// the output for above would be:"9 5"

  // pickup here
  // process city data into dijkstra 2D array funness
  // iterate over roads array to make Num x Num array


  // it gives us the shortest route,
  // from which we can derive the shortest distance.
  // Then find all the routes of that same distance or less.
  // Chose the route with the most items.
  // output the shortest DISTANCE and quantity of ITEMS on that route.

  /* Let us create the example graph discussed above */
  // int graph[V][V] =
  //   {
  //     { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
  //     { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
  //     { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
  //     { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
  //     { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
  //     { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
  //     { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
  //     { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
  //     { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
  //   };

	// dijkstra(graph, 0);

	return 0;
}
