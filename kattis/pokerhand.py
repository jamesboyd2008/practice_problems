# from https://open.kattis.com/problems/pokerhand

cards = input().split()

ranks = {}

# max = 0

for i in range(len(cards)):
    rank = cards[i][0]
    if rank not in ranks:
        ranks[rank] = 1
    else:
        ranks[rank] += 1

print(max(ranks.values()))