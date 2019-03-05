# This program determines the strength of a hand of cards.

# from https://open.kattis.com/problems/pokerhand

"""
Title: Poker Hand
You are given a five-card hand drawn from a standard 52-card deck. The strength of your hand is the maximum value k such that there are k cards in your hand that have the same rank.

Compute the strength of your hand.

Input
The input will consist of a single line, with five two-character strings separated by spaces.

The first character in each string will be the rank of the card, and will be one of A23456789TJQK. The second character in the string will be the suit of the card, and will be one of CDHS.

You may assume all the strings are distinct.

Output
Output, on a single line, the strength of your hand.

Sample Input 1
AC AD AH AS KD

Sample Output 1
4

Sample Input 2
2C 4D 4H 2D 2H

Sample Output 2
3

Sample Input 3
AH 2H 3H 4H 5H

Sample Output 3
1
"""

cards = input().split()

ranks = {}

for i in range(len(cards)):
    rank = cards[i][0]
    if rank not in ranks:
        ranks[rank] = 1
    else:
        ranks[rank] += 1

print(max(ranks.values()))

