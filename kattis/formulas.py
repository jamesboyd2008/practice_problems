# This script contains useful formulas for Kattis problems.

import math



# Python3 program to find maximum area of a quadrilateral
def maxArea (a , b , c , d ):
    # Calculating the semi-perimeter
    # of the given quadilateral
    semiperimeter = (a + b + c + d) / 2
    # Applying Brahmagupta's formula to
    # get maximum area of quadrilateral
    return math.sqrt((semiperimeter - a) *
                    (semiperimeter - b) *
                    (semiperimeter - c) *
                    (semiperimeter - d))
# Driver code 
a = 1
b = 2
c = 1
d = 2
print("%.2f"%maxArea(a, b, c, d))

# This code is contributed by "Sharad_Bhardwaj".