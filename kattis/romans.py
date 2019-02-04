# This program converts miles to roman paces.

# From https://open.kattis.com/problems/romans

miles = float(input())
paces = 5280 * 1000 / 4854 * miles
print(round(paces))