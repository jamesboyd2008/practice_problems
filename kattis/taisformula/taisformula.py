# This program calculates the area under a curve.

# From https://open.kattis.com/problems/taisformula

"""
Title: Tai's formula

The plot of Sample Input 1. They gray area is the area under the curve formed by the three input points.
Have you heard about the mastermind Tai? He found a way to calculate the area under a glucose curve, given discrete measurement points. He even validated his formula against the approximate technique of counting the number of squares below the graph, when printed on graph paper.
Can you, just like Tai, reinvent the wheel and calculate the area under a glucose curve? Instead of publishing a paper, you need to implement the algorithm. You need this algorithm in your new app, that logs your glucose values that comes from a continuous glucose monitor. You have also figured out the trick of the device. It’s not actually continuous, it just samples the glucose value frequently, automatically.

Input
Input contains several lines of numbers separated by spaces. The first line contains the integer N, 2≤N≤104, the number of glucose samples.

The following N lines describe each glucose sample.

Each line contains two numbers ti, vi, where ti is the time of the sample, and vi is the glucose value at time ti.

The glucose values vi are inside the measurement domain: 2.0≤vi≤23.0 mmol/L.

Each glucose value is given with exactly one decimal digit.

Since you are working with a computer program, the time of each sample is given as an integer, the number of milliseconds since the first of January 1970.

The samples are always given in increasing order by time, meaning 0<t1<t2<⋯<tN<1014 ms.

Note that a second is a thousand milliseconds.

Output
The area under the glucose curve in the unit mmol/L⋅s

Answers within a relative or absolute error of 10−6 will be accepted.

Sample Explanation
In Sample Input 1 there are three data points, where the area between the t-axis and the curve is formed by two Trapezoids. The first trapezoid have the area of 2+122⋅(2000−1000)=7000mmol/L⋅ms, making 7mmol/L⋅s. The second has an area of 17mmol/L⋅s, making the total area 24mmol/L⋅s.

Sample Input 1
3
1000 2.0
2000 12.0
3000 22.0

Sample Output 1
24

Sample Input 2
3
1000 4.0
2000 8.0
3001 7.3

Sample Output 2
13.65765
"""

caseQuantity = int(input())

totalArea = 0
xPrev = None
yPrev = None

for i in range(caseQuantity):
    (x, y) = tuple(map(float, input().split()))
    if xPrev is None:
        xPrev = x
        yPrev = y
    else:
        newArea = ( y + yPrev ) / 2 * ( x - xPrev )
        totalArea += newArea
        xPrev = x
        yPrev = y

totalArea /= 1000
print(totalArea)









