# This program calculates football scores.

# From https://open.kattis.com/problems/beatspread


"""
Title: Beat the Spread

Superbowl Sunday is nearly here. In order to pass the time waiting for the half-time commercials and wardrobe malfunctions, the local hackers have organized a betting pool on the game. Members place their bets on the sum of the two final scores, or on the absolute difference between the two scores.

Given the winning numbers for each type of bet, can you deduce the final scores?

Input
The first line of input contains 𝑛, the number of test cases. 𝑛 lines follow, each representing a test case. Each test case gives 𝑠 and 𝑑, non-negative integers representing the sum and (absolute) difference between the two final scores. You can assume that 0≤s,d≤1000.

Output
For each test case, output a line giving the two final scores, largest first. If there are no such scores, output a line containing “impossible”. Recall that football scores are always non-negative integers.

Sample Input 1:
2
40 20
20 40

Sample Output 1:
30 10
impossible
"""

def valid(num):
    """
    Validates a number. If nothing follows the decimal, it's good.
    If something follows the decimal, it's no good.
    Param: num float A decimal with or without non zero digits after
           the decimal.
    Returns boolean
    """
    if (num - int(num)) == 0:
        return(True)
    else:
        return(False)

gameQuantity = int(input())

results = []

for game in range(gameQuantity):
    line = list(map(int, input().split(" ")))
    summ = line[0]
    diff = line[1]

    if diff > summ:
        results.append( ('impossible', 0) )
    else:
        # score_1  = (summ - diff) // 2
        score_1  = (summ - diff) / 2


        score_2 = summ - score_1
        if score_1 > score_2:
            scoreBig = score_1
            scoreSmall = score_2
        else:
            scoreBig = score_2
            scoreSmall = score_1
        results.append( (scoreBig, scoreSmall) )

for summ, diff in results:
    """
    list of tuples looks like:
    [
        (30, 10),
        (20, 20),
        ('impossible', 0),
        (50, 2)
    ]
    """
    if summ == 'impossible':
        print('impossible')
    else:
        if valid(summ) and valid(diff):
            print(f"{int(summ)} {int(diff)}")
        else:
            print('impossible')








