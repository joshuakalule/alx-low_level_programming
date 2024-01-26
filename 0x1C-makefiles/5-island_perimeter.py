#!/usr/bin/python3
"""Calculate the perimeter of an island."""

MAX_ROW = 100
MAX_COL = 100


def island_perimeter(grid):
    """
    Calculate the perimemter of a 1s representation of an island in grid

    Arguments:
        grid (list): list of lists containing 1s and 0s

    Returns:
        perimeter
    """
    total = 0
    prev_row = [0 for x in range(len(grid[0]))]
    for r, row in enumerate(grid):
        prev_cell = 0
        if r + 1 < len(grid):
            next_row = [x for x in grid[r + 1]]
        else:
            next_row = [0 for x in grid[r]]
        for n, cell in enumerate(row):
            next_cell = row[n + 1] if n + 1 < len(row) else 0
            if cell == 1:
                # col wise perimeter (left)
                if prev_cell == 0:
                    total += 1
                # col wise perimeter (right)
                if next_cell == 0:
                    total += 1
                # row wise perimeter (top)
                if prev_row[n] == 0:
                    total += 1
                # row wise perimeter (bottom)
                if next_row[n] == 0:
                    total += 1
            prev_cell = cell
            prev_row[n] = cell

    return (total)
