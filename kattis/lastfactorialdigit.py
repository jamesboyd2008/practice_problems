# This program spits out the last digit of the Nth factorial.

# From https://open.kattis.com/problems/lastfactorialdigit

"""
Title: Last Factorial Digit
Factorials on the complex plane, by Dmitrii Kouznetsov
The factorial of N, written as N!, is defined as the product of all the integers from 1 to N. For example, 3!=1×2×3=6.

This number can be very large, so instead of computing the entire product, just compute the last digit of N! (when N! is written in base 10).

Input
The first line of input contains a positive integer 1≤T≤10, the number of test cases. Each of the next T lines contains a single positive integer N. N is at most 10.

Output
For each value of N, print the last digit of N!.

Sample Input 1
3
1
2
3

Sample Output 1
1
2
6

Sample Input 2
2
5
2

Sample Output 2
0
2
"""

caseQuantity = int(input())
results = []
factorials = [1, 2, 6, 4]

for case in range(caseQuantity):
    n = int(input())
    if n < 5:
        results.append(factorials[n - 1])
    else:
        results.append(0)

for result in results:
    print(result)




    