# This program approximates Euler's Number: e.

# From https://open.kattis.com/problems/eulersnumber

"""

"""

# Try adding it up

n = int(input())

if(n < 1):
    print(1)
else:
    sum = 1
    factorialness = 1
    for i in range(1, n + 1):
        factorialness *= i
        sum += 1 / factorialness

    print(sum)

