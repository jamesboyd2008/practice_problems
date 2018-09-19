# This program decodes a message.

# From https://open.kattis.com/problems/encodedmessage

# Title: Encoded Message
# Alex wants to send a love poem to his girlfriend Bridget. Unfortunately, she has a nosy friend, Ellen, who might intercept his message and invade their privacy.
#
# To prevent this, Alex has invented a scheme to make his messages indecipherable to Ellen. He arranges the letters into a 5x5 grid, which is rotated a quarter-turn clockwise, and then he puts the resulting letters on a single line again. (For simplicity’s sake, Alex doesn’t use whitespace or punctuation in his poems.)
#
# For example, the text “RosesAreRedVioletsAreBlue” would be encoded as
# “eedARBtVrolsiesuAoReerles” using the following intermediate steps:
#
# ---------------------
# | R | o | s | e | s |
# ---------------------
# | A | r | e | R | e |
# ---------------------
# | d | V | i | o | l |
# ---------------------
# | e | t | s | A | r |
# ---------------------
# | e | B | l | u | e |
# ---------------------
#
# ==>
#
# ---------------------
# | e | e | d | A | R |
# ---------------------
# | B | t | V | r | o |
# ---------------------
# | l | s | i | e | s |
# ---------------------
# | u | A | o | R | e |
# ---------------------
# | e | r | l | e | s |
# ---------------------
#
# Ellen has intercepted some of Alex’s messages but they make no sense to her. Can you write a program to help her decode them?
#
# Input
# On the first line one positive number: the number of test cases, at most 100. After that per test case:
#
# one line with an encoded message: a string consisting of upper-case and lower-case letters only. The length of the message is a square between 1 and 10 000 characters.
#
# Output
# Per test case:
#
# one line with the original message.
#
# Sample Input 1
# 3
# RSTEEOTCP
# eedARBtVrolsiesuAoReerles
# EarSvyeqeBsuneMa
#
# Sample Output 1
# TOPSECRET
# RosesAreRedVioletsAreBlue
# SquaresMayBeEven

results = []
caseQuantity = int(input())

for case in range(caseQuantity):
    result = ''
    line = input()
    xByx = int(len(line) ** (1/2))
    for i in range(xByx):
        for j in range(xByx):
            result += line[ (xByx - i - 1) + (xByx * j) ]
    results.append(result)

print(*results, sep = '\n')

