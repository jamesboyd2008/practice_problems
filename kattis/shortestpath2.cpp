/*
This program finds the shortest path between two vertices of a weighted graph.

This problem is from https://open.kattis.com/problems/shortestpath2

Title: Single source shortest path, time table

Input
The input consists of several test cases. Each test case starts with a line
with four non-negative integers, 1≤n≤10000, 0≤m≤20000, 1≤q≤100 and 0≤s<n,
separated by single spaces, where n is the numbers of nodes in the graph, m the
number of edges, q the number of queries and s the index of the starting node.
Nodes are numbered from 0 to n−1. Then follow m lines, each line consisting of
five (space-separated) integers u, v, t0, P and d indicating that there is an
edge from u to v in the graph which can be traversed at time t0+t⋅P for all
nonnegative integers t, and that it takes d time units to traverse the edge.
You may assume 0≤t0,P,d≤1000.

For instance, the edge 3 8 15 10 5 indicates that at time 15,25,35,45,…, we can
travel from node 3 to node 8 in 5 time units. Note that it is possible to stand
still at a node, to wait for an edge to become available. Also, note that if
P=0, the edge can be used only at time t0 and never again.

Then follow q lines of queries, each consisting of a single non-negative
integer, asking for the minimum distance from node s to the node number given
on the query line.

Input will be terminated by a line containing four zeros, this line should not
be processed.

Output
For each query, output a single line containing the minimum time to reach the
node queried, assuming we start in node s at time 0, or the word “Impossible”
if there is no path from s to that node. Print a blank line after each test
case.


Sample Input 1	        Sample Output 1
4 4 4 0                 0
0 1 15 10 5             20
1 2 15 10 5             30
0 2 5 5 30              Impossible
3 0 0 1 1
0                       105
1
2
3
2 1 1 0
0 1 100 0 5
1
0 0 0 0
*/

#include <iostream>

using namespace std;

int main()
{
    cout << "output shortest path\n";

    return 0;
}
