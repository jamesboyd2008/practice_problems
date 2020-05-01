# This program builds a graph and returns the path from a leaf to the root.

# From https://open.kattis.com/problems/kitten

"""
Title: Kitten on a Tree
Ouch! A kitten got stuck on a tree. Fortunately, the tree’s branches are numbered. Given a description of a tree and the position of the kitten, can you write a program to help the kitten down?

Input
The input is a description of a single tree. The first line contains an integer 𝐾, denoting the branch on which the kitten got stuck. The next lines each contain two or more integers 𝑎,𝑏1,𝑏2,…. Each such line denotes a branching: the kitten can reach 𝑎 from 𝑏1,𝑏2,… on its way down. Thus, 𝑎 will be closer to the root than any of the 𝑏𝑖. The description ends with a line containing -1. Each branch 𝑏𝑖 will appear on exactly one line. All branch numbers are in the range 1..100, though not necessarily contiguous. You are guaranteed that there is a path from every listed branch to the root. The kitten will sit on a branch that has a number that is different than the root.

Output
Output the path to the ground, starting with the branch on which the kitten sits.

Sample Input 1:
14
25 24
4 3 1 2
13 9 4 11
10 20 8 7
32 10 21
23 13 19 32 22
19 12 5 14 17 30
14 6 15 16
30 18 31 29
24 23 26
26 27 28
-1

Sample Output 1:
14 19 23 24 25
"""

def dfs(path, parent, leaf):
    """
    Returns the path to a leaf.
    This function assumes itself to be within the scope of a dictionary,
    tree, such that tree[parent] = [child, child, ...]
    """
    if parent == leaf: # Did we find the kitten?
        return path
    else:
        if parent not in tree: # No kitten and no children?
            return
        else:
            for child in tree[parent]:
                path.append(child)
                result = dfs(path, child, leaf)
                if result is None:
                    path.pop()
                    pass
                else:
                    return result

# Build the graph
tree = {} # tree[parent] = [child, child, ...]

# Bug? -> this algo assumes the root is always on the second
#         line of input.

leaf = int(input())
branch = list(map(int, input().split()))
root = branch[0]

while branch[0] != -1:
    parent = branch[0]
    children = branch[1:]
    tree[parent] = children # Add the node to the graph.
    branch = list(map(int, input().split()))

path = ' '.join(list(map(str, dfs([root], root, leaf)[::-1])))
print(path)

