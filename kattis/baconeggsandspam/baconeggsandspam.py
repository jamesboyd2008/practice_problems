# This program prints organizes restaurant orders.

# From https://open.kattis.com/problems/baconeggsandspam

"""
Title: Bacon, Eggs, and Spam
You are a short-order cook in a local diner. Each day, a series of customers enter your diner and order a list of items from the menu. You not only prepare their orders, but you also make a list of who ordered what. At the end of the day, you like to reflect back on who ordered the various items on your menu. This will help you to make decisions about what you should feature on your menu, how you should price it, and what items you may be able to drop from the menu. Develop a program to generate a report of the day’s orders.

Input
Input consists of descriptions of up to 100 days’ worth of diner orders. The description of each day starts with a line containing an integer, 1≤𝑛≤20, giving the number of customers who visit the diner. This is followed by 𝑛 lines, each starting with the name of an individual. The remainder of the line is a non-empty, space-separated list of up to 10 unique menu items ordered by the individual. Each individual’s name is unique and appears at most once on a given day. Each name has at most 15 characters (all A–Z) beginning with an uppercase letter (lowercase characters may follow). All menu items have up to 15 characters using only a–z (lowercase) and ‘-’ (dash). Input terminates with a value of zero for 𝑛.

Output
For each day, print out a report of who ordered each menu item, one line per menu item. The line should give the name of the menu item, followed by a space-separated list of all the people who ordered it. The list of menu items for a given day should be sorted lexicographically, and the list of names reported for an item should also be sorted lexicographically. Print a blank line after the report for each day.

Sample Input 1
3
Alice bacon eggs spam
Sue pancakes sausage ham
David eggs spam
1
Bill diet-coke
0

Sample Output 1 
bacon Alice
eggs Alice David
ham Sue
pancakes Sue
sausage Sue
spam Alice David

diet-coke Bill
"""

from collections import deque

while(True):
    customerQuantity = int(input())
    if customerQuantity == 0:
        break

    orders = {}
    foods = set()

    for i in range(customerQuantity):
        order = deque(input().split())
        name = order.popleft()
        orders[name] = order

    for order in orders:
        for food in orders[order]:
            foods.add(food)

    organizedFoods = list(foods)
    organizedFoods.sort()

    names = list(orders.keys())
    names.sort()

    for food in organizedFoods:
        print(food + " ", end='')
        foodNames = []
        for name in names:
            if food in orders[name]:
                print(name, end=' ')
        print()
    print()
