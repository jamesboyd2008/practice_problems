# This program determines sums.

# From https://open.kattis.com/problems/sumkindofproblem

"""
Title: Sum Kind of Problem
For this problem you will compute various running sums of values for positive integers.

Input
The first line of input contains a single integer 𝑃, (1≤𝑃≤10000), which is the number of data sets that follow. Each data set should be processed identically and independently. Each data set consists of a single line of input. It contains the data set number, 𝐾, followed by an integer 𝑁, (1≤𝑁≤10000).

Output
For each data set there is one line of output. The single output line consists of the data set number, 𝐾, followed by a single space followed by three space separated integers 𝑆1, 𝑆2 and 𝑆3 such that:

𝑆1 = The sum of the first 𝑁 positive integers.

𝑆2 = The sum of the first 𝑁 odd integers.

𝑆3 = The sum of the first 𝑁 even integers.

Sample Input
3
1 1
2 10
3 1001

Sample Output
1 1 1 2
2 55 100 110
3 501501 1002001 1003002
"""

reps = int(input())
results = []

for rep in range(1, reps + 1):
    line = input().split()
    n = int(line[1])
    result = []
    result.append(str(rep))
    s1 = int( ( n * ( n + 1 ) ) / 2 )
    result.append(str(s1))
    s3 = s1 * 2
    s2 = s3 - n
    result.append(str(s2))
    result.append(str(s3))
    results.append(result)

for result in results:
    print(' '.join(result))



















