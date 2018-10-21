"""
This program counts specific triplets.

Given N integers A1, A2, ..., AN, count the number of triplets (x, y, z) (with 1 ≤ x < y < z ≤ N) such that at least one of the following is true:

Ax = Ay × Az, and/or
Ay = Ax × Az, and/or
Az = Ax × Ay

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each begins with one line containing an integer N: the number of integers in array A. The second line consists of N integers Ai; the i-th of these is the value of the i-th integer, as described above.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of triplets satisfying the condition given in the problem statement.

Limits
1 ≤ T ≤ 30.
0 ≤ Ai ≤ 2 × 105, for all i.
Small dataset
3 ≤ N ≤ 200.
Large dataset
3 ≤ N ≤ 7000.

Input
4
6
5 2 4 6 3 1
6
2 4 8 16 32 64
3
1 1 1
3
200000 200000 200000

Output
Case #1: 1
Case #2: 6
Case #3: 1
Case #4: 0
"""

results = []
caseQuantity = int(input())

for case in range(caseQuantity):
    numQuant = int(input())
    nums = list(map(int, input().split()))
    caseMatches = 0
    matches = []

    for i in range(numQuant):
        product = nums[i]
        for j in range(numQuant):
            if j != i:
                factor1 = nums[j]
                for k in range(numQuant):
                    if k != i and k != j:
                        factor2 = nums[k]
                        if (factor1 * factor2 == product):
                            triplet = [i, j, k]
                            triplet.sort()
                            if triplet not in matches:
                                matches.append(triplet)
                                caseMatches += 1

    # results.append(nums)
    results.append(caseMatches)

# print(results)
for i in range(len(results)):
    print(f"Case #{i + 1}: {results[i]}")



