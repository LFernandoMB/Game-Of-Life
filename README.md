# 👾 Game-Of-Life 🧬
Status: Completed ✅
Improvement target: 06/22/2023 ⚠️
Resume: A cellular automaton that follows simple rules: Living or dead cells interact to create complex patterns on a two-dimensional board.

# 📖 The history of project
"Conway's Game of Life" is a cellular automaton created by British mathematician John Conway in 1970. Although it is called a "game", the Game of Life does not involve players or strategies; is actually an abstract mathematical model that simulates the behavior of a population of cells on a two-dimensional grid.

The game takes place on an infinite grid, made up of square cells that can be alive or dead. Each cell interacts with its eight immediate neighbor cells (horizontally, vertically, and diagonally). Cells can be in two states: "alive" (represented by filled cells) or "dead" (represented by empty cells).

The rules of the game are simple:
- Overpopulation: If a live cell has more than three live neighbors, it dies due to overpopulation.
- Loneliness: If a live cell has less than two live neighbors, it dies of loneliness.
- Survival: If a living cell has two or three live neighbors, it lives on into the next generation.
- Reproduction: If a dead cell has exactly three live neighbors, it becomes a live cell in the next generation.

These rules are applied to all cells simultaneously, in each generation, and determine whether a living cell stays alive, dies, or a dead cell becomes alive in the next iteration of the game. From simple initial setups, complex and unpredictable patterns can emerge in Game of Life, including stable structures, oscillators, and "spaceships" that move across the grid.

# 🎯 Project Operation
In this project there are some differences from the original proposal of the "game", they are:
- Any live cell with two or three live neighbours survives.
- Any dead cell with three live neighbours becomes a live cell.
- All other live cells die in the next generation. Similarly, all other dead cells stay dead.

Working Project:
![Working project](https://github.com/LFernandoMB/Game-Of-Life/assets/91624923/fc3fd3b9-c344-48ee-839a-7b8afd1d606a)

Link to access Replit:
https://replit.com/@LuisFernandoMB/GameOfLife#main.cpp

# 🏎️💨 Improvement objective
Improve the visualization of the project by learning models similar to the ones in the image below.

![Improvement objective](https://github.com/LFernandoMB/Game-Of-Life/assets/91624923/e708a8d7-c7a7-4842-bdda-8e14b8bd0404)

Create a "Game" Class and insert the "printGrid", "getNextState" and "updateGeneration" functions so that the code becomes OOP.

# 👨🏻‍💻 Conclusion
I didn't know the model and I learned a lot about it.

I had the feeling of similarity between the proposal of the "game" with Artificial Intelligence (Perhaps by generations and the fact that the state of other cells influences the current state of the other cell)

I intend to practice other models, and execute the improvement proposal defined as "Improvement objective".
