# This script prints the results of adding a some binary numbers.

import random

def decimalToBinary(n):
    """
    Return the binary representation of the integer argument.
    """
    if(n > 1):
        return(decimalToBinary(n // 2) + str(n % 2))
    else:
        return(str(n % 2))

def main():
    nums = range(0, 32)
    for i in range(20):
        num1 = random.choice(nums)
        num2 = random.choice(nums)
        print(num1, '+', num2, '=', num1 + num2, 'or')
        print('  ', decimalToBinary(num1).zfill(5))
        print('+ ', decimalToBinary(num2).zfill(5))
        print('--------')
        print(' ', decimalToBinary(num1 + num2).zfill(6))
        print()


# Driver code
if __name__ == '__main__':
    main()
