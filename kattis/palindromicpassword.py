# This program finds the lowest palindrome, given input.

# From https://open.kattis.com/problems/palindromicpassword

"""
Title: Palindromic Password
The IT department at your school decided to change their password policy. Each password will have to consist of N 6-digit numbers separated by dashes, where N will be determined by the phase of the moon and the weather forecast for the day after it will be generated.

You realized that, if all of the numbers were palindromes (same numbers as the original ones if read backwards), you would have to remember a bunch of 3-digit numbers, which did not sound that bad (at the time).

In order to generate your password of N numbers, you get a list of N randomly generated 6-digit numbers and find the palindromic number closest to them.

Of course, you would like to automate this process...

Input
The first line of the input contains a single positive integer N≤1000 indicating the number of six-digit numbers in the input. Each of the next N lines contains a six-digit number without leading zeroes.

Output
For each six-digit number in the input, output another six-digit number that is closest to it and is also a palindrome. “Closest” in this context means “a number having the smallest absolute difference with the original number”. If there are two different numbers satisfying the above condition, output the smaller one of the two. Remember, no leading zeroes.

Sample Input 1
2
123321
123322

Sample Output 1
123321
123321
"""

caseQuantity = int(input())
cases = []
results = []

for i in range(caseQuantity):
    cases.append(input())

for i in range(caseQuantity):
    case = cases[i]

    # it's all about the first three digits
    # try the first three, reversed
        # then go low, for the third reversed digit
        # then go high for the third reversed digit
    # then go low for the second reversed digit
        # try middle, low, high for third reversed digit?
    # then go high for the second reversed digit
        # try middle, low, high for third reversed digit?
    # then go low for first reversed digit
        # then go middle, low, high for the second reversed digit
            # try middle, low, high for third reversed digit?
        # then go middle, low, high for the second reversed digit
            # try middle, low, high for third reversed digit?
    # then go high for first reversed digit
        # then go middle, low, high for the second reversed digit
            # try middle, low, high for third reversed digit?
        # then go middle, low, high for the second reversed digit
            # try middle, low, high for third reversed digit?

    # the first three, reversed, will often yield the closest solution
    # however, the might not always be the case, for example:
        # input: 499 000
            # try 499 994
            # but, 498 894 is closer
    # Therefore, an algo must be conceived to determine how to proceed.


    # establish the first three digits
    firstThree = case[0:3]

    # try straight

    # try down (third digit)

    # try up (third digit)

    possibilities = list(map(int, [diff0, diff1, diff2]))
    result = min(possibilities)
    """
    pickup here:
    1. establish string representations of the
       straight, down, and up scenarios.
    2. Then, put then in a list.
    3. Then, determine the index of the min diff solution.
    4. Then, append the item at that index in the list from step to the 
       results list.
    """

    # NO LEADING ZEROES

    # Will it ever be the second or first digits, to be manipulated?


for result in results:
    print(result)
























