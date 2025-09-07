# Valid Sudoku (Medium)

## Problem Statement

You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:

    Each row must contain the digits 1-9 without duplicates.
    Each column must contain the digits 1-9 without duplicates.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.

Return true if the Sudoku board is valid, otherwise return false

*Note: A board does not need to be full or be solvable to be valid.*

## Python Solution

- A sudoku will only be valid if there are no duplicate numbers in either a row, column, or subbox.
  - **The inverse is also true**: A sudoku will NOT be valid if there are *any* duplicate numbers in a row, column, or subbox.
- To track for duplicates numbers in a sudoku, we create 3 arrays (rows, columns, and subboxes) of length 9 representing the 9 rows, columns, and subboxes in a sudoku
  - Each element in these arrays is a ``set()`` (which is essentially a hashmap) tracking which numbers have been found in the current row/column/subbox.

Code:

1. We iterate through each position in the sudoku.
2. Each time we encounter a number in a position, we check to make sure that the number has not been previously found in this row, column, or subbox.
3. If not, we mark that the current row, column, and subbox contain this current number and move on to the next positon.
4. Otherwise if the current number has already been encountered in this row, column, or subbox, we return that the sudoku is invalid.
5. If no duplicate numbers were found, we return that the sudoku is valid.

**Time:** O(N^2)
**Space:** O(N^2)

```python
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        # Helper function which gets the current subbox based on the column and row
        def get_subbox(col, row):
            return int(col/3) * 3 + int(row/3)

        # These arrays track the numbers found in each column, row, and subbox
        row_tracker = [set() for i in range(9)]
        col_tracker = [set() for i in range(9)]
        subbox_tracker = [set() for i in range(9)]
        
        for col in range(0, 9):
            for row in range(0, 9):
                current_number = board[col][row] # Number at current position
                subbox = get_subbox(col, row) # Current subbox
                
                # Skip if there is no number
                if current_number == ".":
                    continue

                # Check to see if we already found another instance of this number in this row, column, or subbox
                # Returns False if so
                if current_number in row_tracker[row] or current_number in col_tracker[col] or current_number in subbox_tracker[subbox]:
                    return False

                # Mark that this row, column, and subbox have an instance of this number
                row_tracker[row].add(current_number)
                col_tracker[col].add(current_number)
                subbox_tracker[subbox].add(current_number)

        return True
```
