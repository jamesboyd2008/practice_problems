# This program sorts a list.

# From https://open.kattis.com/problems/mjehuric

"""
Title: Mjehuric
Goran has five wooden pieces arranged in a sequence. There is a number between 1 and 5 inscribed on every piece, so that every number appears on exactly one of the five pieces. Goran wants to order the pieces to form the sequence 1,2,3,4,5 and does it like this:

If the number on the first piece is greater than the number on the second piece, swap them.

If the number on the second piece is greater than the number on the third piece, swap them.

If the number on the third piece is greater than the number on the fourth piece, swap them.

If the number on the fourth piece is greater than the number on the fifth piece, swap them.

If the pieces don’t form the sequence 1,2,3,4,5, go to step 1.

Write a program that, given the initial ordering of the pieces, outputs the ordering after each swap.

Input
The first line contains five integers separated by single spaces, the ordering of the pieces. The numbers will be between 1 and 5 (inclusive) and there will be no duplicates. The initial ordering will not be 1,2,3,4,5.

Output
After any two pieces are swapped, output the ordering of the pieces, on a single line separated by spaces.

Sample Input 1:
2 1 5 3 4

Sample Output 1:
1 2 5 3 4
1 2 3 5 4
1 2 3 4 5

Sample Input 2:
2 3 4 5 1

Sample Output 2:
2 3 4 1 5
2 3 1 4 5
2 1 3 4 5
1 2 3 4 5
"""

def printEm(nums):
    for i in range(len(nums) - 1):
        print(nums[i], end = " ")
    print(nums[len(nums) - 1])

nums = list(map(int, input().split(" ")))
sortedNums = nums.copy()
sortedNums.sort()

sorted = False

while not sorted:
    for i in range(len(nums) - 1):
        swapped = False
        if nums[i] > nums[i + 1]:
            temp = nums[i]
            nums[i] = nums[i + 1]
            nums[i + 1] = temp
            swapped = True
        if swapped:
            printEm(nums)
        if sortedNums == nums:
            sorted = True


