#include <iostream>
#include <vector>

// Function to print the current state of the grid
void printGrid(const std::vector<std::vector<int>>& grid) {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << (cell == 1 ? '*' : ' ') << ' ';
        }
        std::cout << '\n';
    }
}

// Function to check next cell state based on neighbors
int getNextState(int currentState, int liveNeighbors) {
    if (currentState && (liveNeighbors == 2 || liveNeighbors == 3)) {
        return 1; // Living cell with 2 or 3 neighbors survives
    } else if (!currentState && liveNeighbors == 3) {
        return 1; // Dead cell with 3 neighbors becomes alive
    }
    return 0; // All other cells die or remain dead
}

// Function to update the grid to the next generation
std::vector<std::vector<int>> updateGeneration(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> nextGeneration(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Count the number of living neighbors
            int liveNeighbors = 0;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int ni = (i + dx + rows) % rows;
                    int nj = (j + dy + cols) % cols;
                    liveNeighbors += grid[ni][nj];
                }
            }
            liveNeighbors -= grid[i][j]; // Delete current cell state

            // Update cell state on next generation
            nextGeneration[i][j] = getNextState(grid[i][j], liveNeighbors);
        }
    }

    return nextGeneration;
}

int main() {
    // Set grid size and initial state
    int rows = 10;
    int cols = 20;
    std::vector<std::vector<int>> grid(rows, std::vector<int>(cols, 0));

    // Set initial grid state
    grid[1][2] = 0;
    grid[2][3] = 1;
    grid[3][1] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;

    // 5 generation simulation
    for (int generation = 0; generation < 5; ++generation) {
        std::cout << "Generation " << generation << ":\n";
        printGrid(grid);
        std::cout << '\n';

        grid = updateGeneration(grid);
    }

    return 0;

}
