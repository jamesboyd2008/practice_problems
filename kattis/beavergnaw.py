# This program calculates the width of a special cylinder.

# From https://open.kattis.com/problems/beavergnaw

"""
Title: Beavergnaw
When chomping a tree the beaver cuts a very specific shape out of the tree trunk. What is left in the tree trunk looks like two frustums of a cone joined by a cylinder with the diameter the same as its height. A very curious beaver tries not to demolish a tree but rather sort out what should be the diameter of the cylinder joining the frustums such that he chomped out certain amount of wood. You are to help him to do the calculations.

\          /           _
 \        /             |
  \      /     _        |
   |    |       |       |
   |    |       |  d    |   D
   /    \      -        |
  /      \              |
 /        \            _|

Figure 1: A trunk partially eaten by a beaver

We will consider an idealized beaver chomping an idealized tree. Let us assume that the tree trunk is a cylinder of diameter D and that the beaver chomps on a segment of the trunk also of height D. What should be the diameter d of the inner cylinder such that the beaver chomped out V cubic units of wood?

Input
Input contains multiple cases each presented on a separate line. Each line contains two space separated integers D,V (1≤D≤100,1≤V≤1000000). D is the linear units and V is in cubic units. V will not exceed the maximum volume of wood that the beaver can chomp. A line with D=0 and V=0 follows the last case.

Output
For each case, one line of output should be produced containing a floating point number giving the value of d measured in linear units. Your output will be considered correct if it is within relative or absolute error 10−6.

Sample Input 1
10 250
20 2500
25 7000
50 50000
0 0

Sample Output 1
8.054498576
14.774938880
13.115314879
30.901188723
"""


import math

results = []

inputs = list(map(int, input().split()))
# print(inputs)
while(inputs[0] != 0 and inputs[1] != 0):
    D = inputs[0]
    V = inputs[1]
    results.append((-6 * V / math.pi + D ** 3) ** (1/3))
    inputs = list(map(int, input().split()))

for result in results:
    print(result)


    