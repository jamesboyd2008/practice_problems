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
for i in range(caseQuantity):
    cases.append(input())

for i in range(caseQuantity):
    case = cases[i]

    # establish the first three digits
        # check whether that right there works, reversed for 2nd 3 digits
    # up/down oscillation, looking for palindromes?
        # maybe determine whether up or down is the best path?



    # NO LEADING ZEROES
























