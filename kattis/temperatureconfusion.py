# This script converts farenheit to celcius.

"""
From https://open.kattis.com/problems/temperatureconfusion

Title : Temperature Confusion
Yraglac has been a bit bored with Calgary lately and decided to move to the United States. After arriving in the strange land, he discovered that the people there use a temperature scale known as Fahrenheit. Celsius and Fahrenheit are related by the following equation:

[∘F]=95[∘C]+32
It is your job to help Yraglac convert Fahrenheit to Celsius. When it comes to temperatures, however, Yraglac is a bit particular. Given a temperature expressed as a fraction in Fahrenheit, he wants to know the exact value in Celsius, expressed as a fraction in lowest terms.

Input
The input consists of a single test case representing a fractional number in Fahrenheit. It will be in the form a/b or −a/b where a and b are integers such that 0≤a,b≤1000000 and b≠0. Note that the input is not guaranteed to be a fraction in lowest terms. You should consider temperatures below absolute zero to be valid.

Output
Output a single line with the exact result of converting the temperature to Celsius, expressed as a fraction in lowest terms (that is, gcd(a,b)=1).

Sample Input 1
32/1

Sample Output 1
0/1

Sample Input 2
33/1

Sample Output 2
5/9

Sample Input 3
-40/1

Sample Output 3
-40/1

Sample Input 4
-84/9

Sample Output 4
-620/27
"""

def gcd(numer, denom):
    """returns gcd"""
    best = 1
    ceiling = min([abs(numer), abs(denom)])

    for attempt in range(2, (ceiling + 1)):
        if numer % attempt == 0 and denom % attempt == 0:
            best = attempt

    return(best)

def celcius(numer, denom):
    """returns fractional temperature as a tuple
    C = (F - 32)*(5/9)
    """
    thirtyTwoNumer = denom * 32
    resultNumer = (numer - thirtyTwoNumer) * 5
    resultDenom = denom * 9
    return((resultNumer, resultDenom))

(numer, denom) = tuple(map(int, input().split('/')))
(uglyNumer, uglyDenom) = celcius(numer, denom)

divisor = gcd(uglyNumer, uglyDenom)

finalNumer = int(uglyNumer / divisor)
finalDenom = int(uglyDenom / divisor)

if finalNumer == 0:
    print("0/1")
else:
    print(f"{finalNumer}/{finalDenom}")






