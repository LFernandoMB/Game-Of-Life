#include "game_of_life.h"

const int ROWS = 6;
const int COLS = 10;
const int GENERATIONS = 5;

// Function to print the current state of the grid
void printGrid(const std::vector<std::vector<int>>& grid) {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << (cell == 1 ? '*' : ' ') << ' ';
        }
        std::cout << std::endl;
    }
}

// Function to check next cell state based on neighbors
int getNextState(int currentState, int liveNeighbors) {
    if (currentState && (liveNeighbors == 2 || liveNeighbors == 3)) {
      // Living cell with 2 or 3 neighbors survives
      return 1; 
    } else if (!currentState && liveNeighbors == 3) {
      // Dead cell with 3 neighbors becomes alive
      return 1; 
    }
    // All other cells die or remain dead
    return 0; 
}

// Function to update the grid to the next generation
void updateGeneration(std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> nextGeneration;
    nextGeneration.reserve(ROWS);

    for (int i = 0; i < ROWS; ++i) {
        nextGeneration.emplace_back();
        nextGeneration[i].reserve(COLS);
        for (int j = 0; j < COLS; ++j) {
            // Count the number of living neighbors
            int liveNeighbors = 0;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int ni = (i + dx + ROWS) % ROWS;
                    int nj = (j + dy + COLS) % COLS;
                    liveNeighbors += grid[ni][nj];
                }
            }
            // Delete current cell state
            liveNeighbors -= grid[i][j]; 

            // Update cell state in the next generation
            nextGeneration[i].push_back(getNextState(grid[i][j], liveNeighbors));
        }
    }
    // Update the grid with the next generation
    grid = std::move(nextGeneration); 
}

int main() {
    // Width and height of the grid like as parameters
    std::vector<std::vector<int>> grid(ROWS, std::vector<int>(COLS, 0)); 

    // Set initial grid state
    grid[1][2] = 0;
    grid[2][3] = 1;
    grid[3][1] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;

    // 5 generation simulation
    for (int generation = 0; generation < GENERATIONS; ++generation) {
        std::cout << "Generation " << generation << ":\n";
        printGrid(grid);
        std::cout << std::endl;
        // Update grid to the next generation
        updateGeneration(grid); 
    }

    return 0;

}
