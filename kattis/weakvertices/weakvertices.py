# This program outputs the weak vertices in an undirected graph.

# From https://open.kattis.com/problems/weakvertices

"""
Title: Weak Vertices
Engineers like to use triangles. It probably has something to do with how a triangle can provide a lot of structural strength. We can describe the physical structure of some designs using an undirected graph. We’ll say vertex 𝑖 is part of a triangle if 𝑖 has two different neighbors 𝑗 and 𝑘 such that 𝑗 and 𝑘 are neighbors of each other. For this problem, find weak vertices in graphs – those vertices that is not part of any triangle.

Input
Input consists of up to 100 graphs. Each starts with an integer, 1≤𝑛≤20, giving the number of vertices in the graph. Next come 𝑛 lines with 𝑛 integers on each line, which describe an 𝑛×𝑛 adjacency matrix for the graph. Vertices are numbered from 0 to 𝑛−1. If the adjacency matrix contains a one at row 𝑟, column 𝑐 (where 0≤𝑟,𝑐≤𝑛−1), it means that there is an edge from vertex 𝑟 to vertex 𝑐. Since the graph is undirected, the adjacency matrix is symmetric. The end of input is marked by a value of −1 for 𝑛.

Output
For each graph, produce a line listing the weak vertices ordered from least to greatest.

Sample Input 1:
9
0 1 1 1 0 0 0 0 0
1 0 0 0 0 0 1 0 0
1 0 0 1 0 1 0 0 0
1 0 1 0 0 1 1 0 0
0 0 0 0 0 0 1 1 0
0 0 1 1 0 0 0 0 0
0 1 0 1 1 0 0 1 0
0 0 0 0 1 0 1 0 1
0 0 0 0 0 0 0 1 0
1
0
-1

Sample Output 1:
1 8
0
"""

vertices = int(input())
results = []

while(vertices != -1):
    weaks = []
    matrix = []
    for edge in range(vertices):
        matrix.append([])
        line = list(map(int, input().split(' ')))
        matrix[edge] = line


    for vertex in range(vertices):
        # check for two
        # follow up on those two to see if they reference each other
        followUps = []
        twoCount = 0
        for column in range(vertices):
            if matrix[vertex][column]:
                followUps.append(column)

        for followUp in range(len(followUps)):
            row = followUps[followUp]
            for followUp2 in range(followUp + 1, len(followUps)):
                column = followUps[followUp2]
                if matrix[row][column]:
                    twoCount += 1
        if twoCount < 1:
            weaks.append(vertex)
    results.append(weaks)

    vertices = int(input())

for result in results:
    for resi in result:
        print(resi, end = ' ') # potential whitespace error
    print("")





