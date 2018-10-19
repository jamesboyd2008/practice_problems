# This program finds the best deals in sets of sets of deals.

# From https://open.kattis.com/problems/carousel

"""
Title: Carousel Rides
Carl likes to ride the carousel. Carousel operators often offer discounts for buying multiple rides. He wonders which of the discounts provides the best value. Write a program to help him.
Input
The input will contain multiple test cases, up to 100. A test case starts with a line containing two integers n (1≤n≤10) and m (1≤m≤20). Carl will not take advantage of offers that require him to buy more than m tickets. Following this are n lines, each with integers a and b which each represent an offer to buy a tickets for $b.

The input will be terminated by a line containing the characters 0 0.

Output
For each test case, print Buy a tickets for $b for the best offer that matches his requirements. If there are multiple best offers, print the one which buys more tickets. If there is no suitable offer, print No suitable tickets offered.

Sample Input 1:
3 5
1 3
3 5
4 7
3 2
3 5
1 3
4 7
3 2
3 6
1 2
2 4
1 3
4 10
0 0

Sample Output 1:
Buy 3 tickets for $5
Buy 1 tickets for $3
Buy 2 tickets for $4
No suitable tickets offered
"""

pairs = []

aAndB = list(map(int, input().split()))
a = aAndB[0]
b = aAndB[1]

while a != 0 and b != 0:
    pairs.append((a, b))
    aAndB = list(map(int, input().split()))
    a = aAndB[0]
    b = aAndB[1]

pairsIndex = 0
(offers, max) = pairs[pairsIndex]
pairsIndex += 1

while pairsIndex < len(pairs):
    bestprice = None
    numTicket = 0
    priceKeep = 0
    for i in range(0, offers):
        (ticket, price) = pairs[pairsIndex]
        pairsIndex += 1
        if ticket <= max and \
        (bestprice is None or bestprice > (float(price)/float(ticket))):
            bestprice = float(price)/float(ticket)
            numTicket = ticket
            priceKeep = price
        elif ticket <= max and bestprice == float(price)/float(ticket):
            if numTicket < ticket:
                numTicket = ticket
                priceKeep = price

    if bestprice is None:
        print("No suitable tickets offered")
    else:
        print(f"Buy {numTicket} tickets for ${priceKeep}")
    if pairsIndex < len(pairs):
        (offers, max) = pairs[pairsIndex]
        pairsIndex += 1
