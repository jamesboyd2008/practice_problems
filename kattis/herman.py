# This program calculates the area of a circle correctly and incorrectly.

# from https://open.kattis.com/problems/herman

# Title: Herman
# The 19th century German mathematician Hermann Minkowski investigated a non-Euclidian geometry, called the taxicab geometry. In taxicab geometry the distance between two points T1(x1,y1) and T2(x2,y2) is defined as:
#
# D(T1,T2)=|x1−x2|+∣y1−y2∣
# All other definitions are the same as in Euclidian geometry, including that of a circle:
#
# A circle is the set of all points in a plane at a fixed distance (the radius) from a fixed point (the centre of the circle).
#
# We are interested in the difference of the areas of two circles with radius R, one of which is in normal (Euclidian) geometry, and the other in taxicab geometry. The burden of solving this difficult problem has fallen onto you.
#
# Input
# The first and only line of input will contain the radius R, a positive integer smaller than or equal to 10000.
#
# Output
# On the first line you should output the area of a circle with radius R in normal (Euclidian) geometry. On the second line you should output the area of a circle with radius R in taxicab geometry.
#
# Note: Outputs within ±0.0001 of the official solution will be accepted.
#
# Sample Input 1
# 1
#
# Sample Output 1
# 3.141593
# 2.000000
#
# Sample Input 2
# 21
#
# Sample Output 2
# 1385.442360
# 882.000000
#
# Sample Input 3
# 42
#
# Sample Output 3
# 5541.769441
# 3528.000000

import math

def eucArea(radius):
    return math.pi * radius ** 2

def taxiArea(radius):
    return 2 * radius ** 2

radius = int(input())
print(eucArea(radius))
print(taxiArea(radius))
