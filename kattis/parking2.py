"""
This program tells a grocery shopper how far they can anticipate walking,
given data regarding the stores they wish to visit at a strip mall.

This problem is from https://open.kattis.com/problems/parking2

Title: Parking
When shopping on Long Street, Michael usually parks his car at some random
location, and then walks to the stores he needs. Can you help Michael choose a
place to park which minimises the distance he needs to walk on his shopping
round?
Long Street is a straight line, where all positions are integer. You pay for
parking in a specific slot, which is an integer position on Long Street.
Michael does not want to pay for more than one parking though. He is very
strong, and does not mind carrying all the bags around.

Input
The first line of input gives the number of test cases, 1≤t≤100. There are two
lines for each test case. The first gives the number of stores Michael wants to
visit, 1≤n≤20, and the second gives their n integer positions on
Long Street, 0≤x≤99.

Output
Output for each test case a line with the minimal distance Michael must walk
given optimal parking.

Sample Input 1	           Sample Output 1
2                          152
4                          70
24 13 89 37
6
7 30 41 14 39 42
"""
# The commented  solution assumes he goes to the stores in the order received.
# This results in the same answer for Sample Input 1
# cases = int(input())
# for x in range(cases):
#     stores = input()
#     locations = input().split()
#     locations = list(map(int, locations))
#     distance = 0
#     for i in (range(len(locations) - 1)):
#         distance += abs(locations[i + 1] - locations[i])
#     distance += abs(locations[0] - locations[-1])
#     answers.append(distance)
# for answer in answers:
#     print(answer)

answers = []
cases = int(input())
for x in range(cases):
    stores = input()
    locations = input().split()
    locations = list(map(int, locations))
    distance = (max(locations) - min(locations)) * 2
    answers.append(distance)
for answer in answers:
    print(answer)
