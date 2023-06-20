#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <vector>
#include <iostream>

// Function to print the current state of the grid
void printGrid(const std::vector<std::vector<int>>& grid);

// Function to check next cell state based on neighbors
int getNextState(int currentState, int liveNeighbors);

// Function to update the grid to the next generation
void updateGeneration(std::vector<std::vector<int>>& grid);

#endif
