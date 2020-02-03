# This program determines the volume of a piece of cake.

# From https://open.kattis.com/problems/pieceofcake2

"""
Title: Piece of Cake!

It is Greg’s birthday! To celebrate, his friend Sam invites Greg and two other friends for a small party. Of course, every birthday party must have cake.

Sam ordered a square cake. She makes a single horizontal cut and a single vertical cut. In her excitement to eat cake, Sam forgot to make these cuts through the middle of the cake.

Of course, the biggest piece of cake should go to Greg since it is his birthday. Help Sam determine the volume of the biggest piece of cake that resulted from these two cuts.

Input
The input consists of a single line containing three integers 𝑛 (2≤𝑛≤10000), the length of the sides of the square cake in centimeters, ℎ (0<ℎ<𝑛), the distance of the horizontal cut from the top edge of the cake in centimeters, and 𝑣 (0<𝑣<𝑛), the distance of the vertical cut from the left edge of the cake in centimeters. This is illustrated in the figure above.

Each cake is 4 centimeters thick.

Output
Display the volume (in cubic centimeters) of the largest of the four pieces of cake after the horizontal and vertical cuts are made.

Sample Input 1
10 4 7

Sample Output 1
168

Sample Input 2
5 2 2

Sample Output 2
36

Sample Input 3
4 2 1

Sample Output 3
24
"""

dims = list(map(int, input().split()))
half = dims[0] / 2
h = dims[1]
v = dims[2]

# four scenarios

if h > half:
    if v > half:
        result = h * v * 4
    else:
        result = h * (half * 2 - v) * 4
else: # h <= half
    if v > half:
        result = (half * 2 - h) * v * 4
    else:
        result = (half * 2 - h) * (half * 2 - v) * 4

print(int(result))

