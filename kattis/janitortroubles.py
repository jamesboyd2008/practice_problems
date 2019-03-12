# This program calculates the max area of a quadrilateral.

# From https://open.kattis.com/problems/janitortroubles

"""
Title: Janitor Troubles
While working a night shift at the university as a janitor, you absentmindedly erase a blackboard covered with equations, only to realize afterwards that these were no ordinary equations! They were the notes of the venerable Professor E. I. N. Stein who earlier in the day solved the elusive maximum quadrilateral problem! Quick, you have to redo his work so no one noticed what happened.
The maximum quadrilateral problem is quite easy to state: given four side lengths s1,s2,s3 and s4, find the maximum area of any quadrilateral that can be constructed using these lengths. A quadrilateral is a polygon with four vertices.

Input
The input consists of a single line with four positive integers, the four side lengths s1, s2, s3, and s4.

It is guaranteed that 2si<∑4j=1sj, for all i, and that 1≤si≤1000.

Output
Output a single real number, the maximal area as described above. Your answer must be accurate to an absolute or relative error of at most 10−6.

Sample Input 1
3 3 3 3

Sample Output 1
9

Sample Input 2
1 2 1 1

Sample Output 2
1.299038105676658

Sample Input 3
2 2 1 4

Sample Output 3
3.307189138830738
"""

import math

(a, b, c, d) = tuple(map(int, input().split()))

s = ( a + b + c + d ) / 2

k = math.sqrt(
    (s - a) *
    (s - b) *
    (s - c) *
    (s - d)
)

print(k)







