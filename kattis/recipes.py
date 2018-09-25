# This program calculates the appropriate quantity of ingredients to include in
# a recipe.
#
# From https://open.kattis.com/problems/recipes
#
# Title: Scaling Recipes
# A recipe is a list of ingredients and a set of instructions to prepare a dish. It is often written for a particular number of portions. If you have a recipe for 4 portions and you want to make 6 portions, it turns out that simply multiplying the amounts for each ingredient by 1.5 is often wrong! The reason is that the original recipe may have been rounded to the nearest teaspoon, gram, etc., and the rounding errors magnify when a recipe is scaled.
# Some recipes are specifically written to ease the task of scaling. These recipes are developed using “Baker’s percentages.” Each ingredient is listed not only by weight (in grams), but also as a percentage relative to the “main ingredient.” The main ingredient will always have a 100% Baker’s percentage. Note that the sum of the Baker’s percentages from all ingredients is greater than 100%, and that the Baker’s percentages of some ingredients may exceed 100%.
#
# Table 1: Example Recipe
# Ingredient  Weight (g)  Percentage (%)
# --------------------------------------
# Olive_Oil   50.9        11.2
# Garlic      12.0        2.7
# Beef        453.6       100.0
# Onions      1134.0      250.0
# Raisins     82.5        18.2
# Bouillon    10.0        2.2
#
# To scale a recipe:
#
# determine the scaling factor by dividing the number of desired portions by the number of portions for which the recipe is written;
#
# multiply the weight of the main ingredient with a 100% Baker’s percentage by the scaling factor. This is the scaled weight of the main ingredient;
#
# calculate the scaled weight of every other ingredient by multiplying its Baker’s percentage by the scaled weight of the main ingredient.
#
# Input
# The first line of input specifies a positive integer T≤1000, consisting of the cases to follow. Each case starts with a line with three integers R, P, and D: 1≤R≤20 is the number of ingredients, 1≤P≤12 is the number of portions for which the recipe is written, and 1≤D≤1000 is the number of desired portions. Each of the next R lines is of the form
#
#    <name>   <weight>   <percentage>
# where <name> is the name of the ingredient (an alphabetic string of up to 20 characters with no embedded spaces), <weight> is the weight in grams for that ingredient, and <percentage> is its Baker’s percentage. Both <weight> and <percentage> are floating-point numbers with exactly one digit after the decimal point. Each recipe will only have one ingredient with a Baker’s percentage of 100%.
#
# Output
# For each case, print Recipe # followed by a space and the appropriate case number (see sample output below). This is followed by the list of ingredients and their scaled weights in grams. The name of the ingredient and its weight should be separated by a single space. Each ingredient is listed on its own line, in the same order as in the input. After each case, print a line of 40 dashes (’-’). Answers within 0.1g of the correct result are acceptable.
#
# Sample Input 1
# 2
# 6 4 20
# oliveoil 50.9 11.2
# garlic 12.0 2.7
# beef 453.6 100.0
# onions 1134.0 250.0
# raisins 82.5 18.2
# bouillon 10.0 2.2
# 4 5 8
# Milk 265.0 93.0
# SodiumCitrate 11.0 4.0
# WhiteCheddar 285.0 100.0
# DryMacaroni 240.0 84.0
#
# Sample Output 1
# Recipe # 1
# oliveoil 254.0
# garlic 61.2
# beef 2268.0
# onions 5670.0
# raisins 412.8
# bouillon 49.9
# ----------------------------------------
# Recipe # 2
# Milk 424.1
# SodiumCitrate 18.2
# WhiteCheddar 456.0
# DryMacaroni 383.0
# ----------------------------------------

from pprint import pprint

results = []

caseQuantity = int(input())

for case in range(caseQuantity):
    proportions = input().split()
    proportions = list(map(float, proportions))
    results.append(f"Recipe # {case + 1}")
    scaleFactor = proportions[2] / proportions[1]
    mainWeight = None
    ingredients = {}

    for ingredient in range(int(proportions[0])):
        recipePart = input().split()
        name = recipePart[0]
        weight = float(recipePart[1])
        percentage = float(recipePart[2])
        ingredients[name] = (weight, percentage)

    for item in ingredients:
        (weight, percentage) = ingredients[item]
        if percentage == 100.0:
            mainWeight = scaleFactor * weight / 100
            break

    for item in ingredients:
        (weight, percentage) = ingredients[item]
        results.append(f"{item} {(mainWeight * percentage):.2f}")

    results.append("----------------------------------------")

print(*results, sep = '\n')










