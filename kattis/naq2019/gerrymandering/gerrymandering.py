# This program determines the likelihood of gerrymandering having occured.

# from https://naq19.kattis.com/problems/gerrymandering
# or from https://open.kattis.com/problems/gerrymandering

"""
Title: Gerrymandering
The original political cartoon about Gerrymandering. Image from Wikipedia.
Electoral systems across the world can vary widely. In some systems, such as winner-take-all, the winner is determined by the plurality of votes—the candidate that receives the most votes wins, and the loser(s) do not get a position.

Such elections can have “wasted votes.” Conceptually, a wasted vote is a vote that did not affect the election outcome. While the exact definition of a wasted vote varies, we’ll adopt the following definition: in an election with 𝑉 voters, every vote for a losing candidate is wasted (these are called lost votes), and every vote for a winning candidate beyond the strict majority of ⌊𝑉/2⌋+1 votes the candidate needs to win is wasted (these are called excess votes). For this problem we’ll consider a two-party system (let’s call the parties A and B) with elections that always involve one candidate from each party.

Let’s illustrate wasted votes with a simple example between two candidates in a district. Suppose that the candidate for party A receives 100 votes and the candidate for party B receives 200 votes. All 100 votes for party A are wasted (lost votes for A), and 49 votes for party B are wasted (excess votes for B). This is because B needs 151 (⌊(100+200)/2⌋+1) votes to win (over A), so the remaining 49 are wasted.

Political scientists use wasted votes to compute the efficiency gap, a single number that summarizes wasted votes. Suppose we have a number of races in different districts, where each district elects one person. Across all districts there are 𝑉 total votes cast, with 𝑤𝐴 total wasted votes for party A and 𝑤𝐵 total wasted votes for party B. Then the efficiency gap is:

𝐸(𝑉,𝑤𝐴,𝑤𝐵)=|𝑤𝐴−𝑤𝐵|𝑉.
A low efficiency gap indicates that the elections are competitive, and that the number of candidates elected from each party is representative of the total voting share for each party. When the efficiency gap is high, this can be an indication of gerrymandering. Gerrymandering refers to organizing voting districts in a way that favors a particular political outcome. Two common ways of doing this are to “pack” similar voters into districts, or “crack” them across multiple districts; both ways tend to diminish those voters’ influence in electing candidates they would like to win.

In an election, districts are made up of precincts. A precinct is an indivisible group of voters. The votes for all precincts in a district are added together to find the results for that district. In this problem you are given a description of a number of precincts: the party vote totals for each precinct, and how those precincts have been grouped into districts. For each district, determine the party that wins and the wasted votes for each party. Then determine the efficiency gap between the two parties over all the districts.

Input
The input describes one election. The first line contains two integers 𝑃 and 𝐷, where 1≤𝑃≤10000 and 1≤𝐷≤min(1000,𝑃). These indicate, respectively, the number of voting precincts and districts. Following this are 𝑃 lines describing the precincts. Line 𝑖 contains 3 numbers: the district 𝑑𝑖 that precinct 𝑖 is assigned to (1≤𝑑𝑖≤𝐷), the number of votes for the candidate from party A (0≤𝑎𝑖≤100000), and the number of votes for the candidate from party B (0≤𝑏𝑖≤100000). It is guaranteed that:

for each precinct 𝑖, 0<𝑎𝑖+𝑏𝑖,

each district is assigned at least one precinct, and

there are no ties within any district.

Output
For each of the districts from 1 to 𝐷, print which party wins (a single character, either A or B). Then print the number of wasted votes for party A and for party B, in order. Finally, after reporting on all the districts, print the efficiency gap as measured over all the districts. The efficiency gap should be accurate to within an absolute error of 10−6.

Sample Input 1
5 3
1 100 200
2 100 99
3 100 50
3 100 50
2 100 98
B 100 49

Sample Output 1
A 1 197
A 49 100
0.1965897693

Sample Input 2
4 4
3 100 99
2 100 99
1 100 99
4 100 99

Sample Output 2
A 0 99
A 0 99
A 0 99
A 0 99
0.4974874372

Sample Input 3
4 4
4 99 100
1 100 99
3 100 99
2 99 100

Sample Output 3
A 0 99
B 99 0
A 0 99
B 99 0
0.0000000000
"""

import math

def victory(a, b):
    """
    determines which party won: A or B.
    """
    return("A" if a >= b else "B")

def wasted(a, b):
    """
    Return a tuple of wated votes, per party, given votes per party.
    a is the quantity of votes for party a.
    b is the quantity of votes for party b.
    """
    wastedA = 0
    wastedB = 0

    if a > b:
        wastedB = b
        wastedA = a - ( math.floor( (a + b) / 2 ) + 1 )
    elif b > a:
        wastedA = a
        wastedB = b - ( math.floor( (a + b) / 2 ) + 1 )

    wasted = (wastedA, wastedB)
    return( wasted )

def efficiency(wastedA, wastedB, votes, winner):
    """
    Returns the efficiency gap over all the districts.
    """
    result = abs(wastedA - wastedB) / votes
    return result

def winner(aS, bS):
    return "A" if aS >= bS else "B"

precincts, districts = tuple(map(int, input().split(" ")))

allVotes = {}

# populate all votes
for i in range(precincts):
    district, a, b = list(map(int, input().split(" ")))
    if district not in allVotes:
        allVotes[district] = [a, b]
    else:
        allVotes[district][0] += a
        allVotes[district][1] += b

totWasteA = 0
totWasteB = 0
votes = 0
aS = 0
bS = 0

# organize votes
voteKeys = list(allVotes.keys())
voteKeys.sort()
# print(voteKeys)


# for district in allVotes:
for key in voteKeys:
    a = allVotes[key][0]
    b = allVotes[key][1]
    winny = victory(a, b)
    print(winny, end = " ")
    wastedA, wastedB = wasted(a, b)
    print(wastedA, wastedB, sep = " ")
    totWasteA += wastedA
    totWasteB += wastedB
    votes += a + b
    if winny == "A":
        aS += 1
    else:
        bS += 1


print(efficiency(totWasteA, totWasteB, votes, winner(aS, bS)))















