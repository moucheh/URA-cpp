#include <iostream>

#include <bits/stdc++.h>

// Initialize a string direction which represents all the
// directions.
std::string direction = "DLRU";

// Arrays to represent change in rows and columns
int dr[4] = { 1, 0, 0, -1 };
int dc[4] = { 0, -1, 1, 0 };

// Function to check if cell(row, col) is inside the maze
// and unblocked
bool isValid(int row, int col, int n, std::vector<std::vector<int> >& maze) {
	return row >= 0 && col >= 0 && row < n && col < n
		   && maze[row][col];
}

// Function to get all valid paths
void findPath(int row, int col, std::vector<std::vector<int> >& maze,
			  int n, std::vector<std::string>& ans,
			  std::string& currentPath) {
	// If we reach the bottom right cell of the matrix, add
	// the current path to ans and return
	if (row == n - 1 && col == n - 1) {
		ans.push_back(currentPath);
		return;
	}
	// Mark the current cell as blocked
	maze[row][col] = 0;

	for (int i = 0; i < 4; i++) {
		// Find the next row based on the current row (row)
		// and the dr[] array
		int nextrow = row + dr[i];
		// Find the next column based on the current column
		// (col) and the dc[] array
		int nextcol = col + dc[i];

		// Check if the next cell is valid or not
		if (isValid(nextrow, nextcol, n, maze)) {
			currentPath += direction[i];
			// Recursively call the FindPath function for
			// the next cell
			findPath(nextrow, nextcol, maze, n, ans,
					 currentPath);
			// Remove the last direction when backtracking
			currentPath.pop_back();
		}
	}
	// Mark the current cell as unblocked
	maze[row][col] = 1;
}

int main() {
	std::vector<std::vector<int>> maze;

	int m, n;

	std::cin >> n >> m;

	for (auto i = 0; i < n; ++i) {
		maze.push_back(std::vector<int>());
		for (auto j = 0; j < m; ++j) {
			int x;
			std::cin >> x;
			maze[i].push_back(x);
		}
	}

	for (const auto& row : maze) {
		for (const auto& col : row) {
			std::cout << col << ' ';
		}
		std::cout << std::endl;
	}

	// vector to store all the valid paths
	std::vector<std::string> result;
	// Store current path
	std::string currentPath = "";

	if (maze[0][0] != 0 && maze[n - 1][n - 1] != 0) {
		// Function call to get all valid paths
		findPath(0, 0, maze, n, result, currentPath);
	}

	if (result.size() == 0)
		std::cout << -1;
	else
		for (int i = 0; i < result.size(); i++)
			std::cout << result[i] << " ";
	std::cout << std::endl;

	return 0;
}