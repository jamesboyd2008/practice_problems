# This program determines the number of handshakes at a mass.

# From https://open.kattis.com/problems/misa

# Misa
# A nice part of the Roman Catholic Mass is the rite of peace when people shake hands with their neighbours and say “peace be with you”. Mirko has found a way to turn this ritual into his own favor. Inside the church, there are R rows of benches where each row can hold a capacity of S people. We can imagine the seating order as a matrix sized R×S where each element represents either a person or an empty seating space. Let us assume that each person shakes hands with their neighbours. That means that the neighbours are located in one of the eight neighbouring elements (if such element exists):
#
# OOO
# OXO
# OOO
#
# A seating order of the people inside the church has been given before Mirko enters. Mirko is, of course, late for the morning Mass and will sit in an empty space so that he shakes hands with as many people as he can. If there are no empty seats left, Mirko will simply give up on the idea and go to the evening Mass instead. We can assume that nobody enters the church after Mirko.
#
# Calculate the total number of handshakes given during the morning Mass.
#
# Input
# The first line of input contains positive integers R and S (1≤R,S≤50) as stated in the text. Each of the following R lines contains S characters. These R×S characters represent the seating order. The character “.” (dot) represents an empty place and the character “o” (lowercase letter o) represents a person.
#
# Output
# The first and only line of output should contain the required number of handshakes.
#
# Sample Input 1
# 2 3
# ..o
# o..
#
# Sample Output 1
# 2
#
# Sample Input 2
# 2 2
# oo
# oo
#
# Sample Output 2
# 6

def mineSweeper(grid, emplace = False):
    """
    This function checks the occupancy of squares in a 2D grid.

    Parameters:
        grid (list): A 2D list of '.' and 'o'.
                     '.' is an unoccupied space and
                     'o' is an occupied   space.
        emplace (bool): Whether the best space is to be occupied, and
                        whether the new, slightly altered grid is to be
                        returned.

    Returns:
        (tuple): the coordinate, formatted thusly:
                 ((row, column), grid, totalShakes),
                 that is most crowded and avaiable.
                 Returns ((0, 0), grid, totalShakes) if nothing is
                 available. totalShakes is the quantity of handshakes
                 that occur on the grid.
    """
    maxShakesCoord = (None, None) # (row, column)
    maxShakes = None
    totalShakes = 0
    rows = len(grid)
    columns = len(grid[0])

    for row in range(rows):
        for column in range(columns):
            shakes = 0
            if emplace is True or grid[row][column] == 'o':

                # determine shakes, counting clockwise
                # If the grid is a horizontal line:
                if len(grid) < 2:
                    # leftmost case
                    if column == 0:
                        if grid[row][column + 1] == 'o':
                            shakes += 1
                    # rightmost case
                    elif column == (columns - 1):
                        if grid[row][column - 1] == 'o':
                            shakes += 1
                    # middle case
                    else:
                        if grid[row][column - 1] == 'o':
                            shakes += 1
                        if grid[row][column + 1] == 'o':
                            shakes += 1
                # If the grid is a vertical line:
                elif len(grid[0]) < 2:
                    # top case
                    if row == 0:
                        if grid[row + 1][column] == 'o':
                            shakes += 1
                    # bottom case
                    elif row == (rows - 1):
                        if grid[row - 1][column] == 'o':
                            shakes += 1
                    # middle case
                    else:
                        if grid[row + 1][column] == 'o':
                            shakes += 1
                        if grid[row - 1][column] == 'o':
                            shakes += 1
                else:
                    # top row case
                    if row == 0:
                        # leftmost column case
                        # Clockwise: E, SE, S
                        if column == 0:
                            if grid[row][column + 1] == 'o':
                                shakes += 1
                            if grid[row + 1][column + 1] == 'o':
                                shakes += 1
                            if grid[row + 1][column] == 'o':
                                shakes += 1
                        # rightmost column case
                        # Clockwise: S, SW, W
                        elif column == (columns - 1):
                            if grid[row + 1][column] == 'o':
                                shakes += 1
                            if grid[row + 1][column - 1] == 'o':
                                shakes += 1
                            if grid[row][column - 1] == 'o':
                                shakes += 1
                        # middle column case
                        # Clockwise: E, SE, S, SW, W
                        else:
                            if grid[row][column + 1] == 'o':
                                shakes += 1
                            if grid[row + 1][column + 1] == 'o':
                                shakes += 1
                            if grid[row + 1][column] == 'o':
                                shakes += 1
                            if grid[row + 1][column - 1] == 'o':
                                shakes += 1
                            if grid[row][column - 1] == 'o':
                                shakes += 1
                    # bottom row case
                    elif row == (rows - 1):
                        # leftmost column case
                        # Clockwise: N, NE, E
                        if column == 0:
                            if grid[row - 1][column] == 'o':
                                shakes += 1
                            if grid[row - 1][column + 1] == 'o':
                                shakes += 1
                            if grid[row][column + 1] == 'o':
                                shakes += 1
                        # rightmost column case
                        # Clockwise: W, NW, N
                        elif column == (columns - 1):
                            if grid[row][column - 1] == 'o':
                                shakes += 1
                            if grid[row - 1][column - 1] == 'o':
                                shakes += 1
                            if grid[row - 1][column] == 'o':
                                shakes += 1
                        # middle column case
                        # Clockwise: W, NW, N, NE, E
                        else:
                            if grid[row][column - 1] == 'o':
                                shakes += 1
                            if grid[row - 1][column - 1] == 'o':
                                shakes += 1
                            if grid[row - 1][column] == 'o':
                                shakes += 1
                            if grid[row - 1][column + 1] == 'o':
                                shakes += 1
                            if grid[row][column + 1] == 'o':
                                shakes += 1
                    # middle row case
                    else:
                        # leftmost column case
                        # Clockwise: N, NE, E, SE, S
                        if column == 0:
                            if grid[row - 1][column] == 'o':
                                shakes += 1
                            if grid[row - 1][column + 1] == 'o':
                                shakes += 1
                            if grid[row][column + 1] == 'o':
                                shakes += 1
                            if grid[row + 1][column + 1] == 'o':
                                shakes += 1
                            if grid[row + 1][column] == 'o':
                                shakes += 1
                        # rightmost column case
                        # Clockwise: S, SW, W, NW, N
                        elif column == (columns - 1):
                            if grid[row + 1][column] == 'o':
                                shakes += 1
                            if grid[row + 1][column - 1] == 'o':
                                shakes += 1
                            if grid[row][column - 1] == 'o':
                                shakes += 1
                            if grid[row - 1][column - 1] == 'o':
                                shakes += 1
                            if grid[row - 1][column] == 'o':
                                shakes += 1
                        # middle column case
                        # Clockwise: N, NE, E, SE, S, SW, W, NW
                        else:
                            if grid[row - 1][column] == 'o':
                                shakes += 1
                            if grid[row - 1][column + 1] == 'o':
                                shakes += 1
                            if grid[row][column + 1] == 'o':
                                shakes += 1
                            if grid[row + 1][column + 1] == 'o':
                                shakes += 1
                            if grid[row + 1][column] == 'o':
                                shakes += 1
                            if grid[row + 1][column - 1] == 'o':
                                shakes += 1
                            if grid[row][column - 1] == 'o':
                                shakes += 1
                            if grid[row - 1][column - 1] == 'o':
                                shakes += 1

            if maxShakes is None or shakes > maxShakes:
                maxShakes = shakes
                maxShakesCoord = (row, column)

            totalShakes += shakes

    if emplace is True:
        # Emplace Mirko
        (row, column) = maxShakesCoord
        grid[row][column] = 'o'

    return((maxShakesCoord, grid, totalShakes))



rowsNcolumns = list(map(int, input().split()))
rows = rowsNcolumns[0]
columns = rowsNcolumns[1]
grid = []
for row in range(rows):
    grid.append(list(input()))

# Accounting for a 1x1 grid
if rows < 2 and columns < 2:
    print('0')
else:
    # emplace mirko
    ((row, column), grid, totalShakes) = mineSweeper(grid, True)
    # Determine the total hand shakes.
    ((row, column), grid, totalShakes) = mineSweeper(grid)
    # totalShakes is divided by two because each shake is counted twice.
    print(int(totalShakes / 2))


# pickup here: a wrong answer was gotten. Generate test cases and test!

