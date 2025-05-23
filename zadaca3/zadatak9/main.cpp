#include <iostream>

/* A utility function to print grid */
void print(int arr[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			std::cout << arr[i][j] << " ";
		std::cout << std::endl;
	}
}

// Checks whether it will be
// legal to assign num to the
// given row, col
bool isSafe(int grid[9][9], int row,
			int col, int num) {

	// Check if we find the same num
	// in the similar row , we
	// return false
	for (int x = 0; x <= 8; x++)
		if (grid[row][x] == num)
			return false;

	// Check if we find the same num in
	// the similar column , we
	// return false
	for (int x = 0; x <= 8; x++)
		if (grid[x][col] == num)
			return false;

	// Check if we find the same num in
	// the particular 3*3 matrix,
	// we return false
	int startRow = row - row % 3,
		startCol = col - col % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i + startRow][j + startCol] == num)
				return false;

	return true;
}

/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
bool solveSudoku(int grid[9][9], int row, int col) {
	// Check if we have reached the 8th
	// row and 9th column (0
	// indexed matrix) , we are
	// returning true to avoid
	// further backtracking
	if (row == 9 - 1 && col == 9)
		return true;

	// Check if column value  becomes 9 ,
	// we move to next row and
	//  column start from 0
	if (col == 9) {
		row++;
		col = 0;
	}

	// Check if the current position of
	// the grid already contains
	// value >0, we iterate for next column
	if (grid[row][col] > 0)
		return solveSudoku(grid, row, col + 1);

	for (int num = 1; num <= 9; num++) {

		// Check if it is safe to place
		// the num (1-9)  in the
		// given row ,col  ->we
		// move to next column
		if (isSafe(grid, row, col, num)) {

			/* Assigning the num in
			   the current (row,col)
			   position of the grid
			   and assuming our assigned
			   num in the position
			   is correct     */
			grid[row][col] = num;

			//  Checking for next possibility with next
			//  column
			if (solveSudoku(grid, row, col + 1))
				return true;
		}

		// Removing the assigned num ,
		// since our assumption
		// was wrong , and we go for
		// next assumption with
		// diff num value
		grid[row][col] = 0;
	}
	return false;
}

int main() {
	int grid[9][9];

	for (auto i = 0; i < 9; ++i) {
		for (auto j = 0; j < 9; ++j) {
			std::cin >> grid[i][j];
		}
	}

	if (solveSudoku(grid, 0, 0))
		print(grid);
	else
		std::cout << "no solution  exists " << std::endl;

	return 0;
}
