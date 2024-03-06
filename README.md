# PROGRAMMING LAB - THE GAME OF LIFE

## Description 
Group project that consisted of creating a code in C language for the game of life.
Conway’s Game of Life is a cellular automaton devised by mathematician John Conway. In this game, each cell can be either alive or dead. The evolution of the game is determined by simple rules:

1. Grid: Imagine a grid of cells.
2. Rules:
a) Birth: A dead cell with exactly three live neighbors becomes alive in the next generation.
b) Survival: A live cell with two or three live neighbors remains alive.
c) Death: A live cell with fewer than two or more than three live neighbors dies.
3. Generations:
a) The game progresses in generations.
b) The initial configuration (often called the “seed”) determines the first generation.
c) Subsequent generations evolve based on the previous one.

## Interface
### Main Page
The program starts by asking the user to define the size of the cellular world, with dimensions ranging from 10x10 to 60x60. After this configuration, the main menu is presented, offering 11 options:

1. Display the current state of the map with live cells.

2. Remove all cells, resetting the map.

3. Allow the user to add or remove live cells.

4. Enable or disable the display of neighboring dead cells for each cell.

5. Start the simulation for a specified number of generations.

6. Show lists of live cells and neighboring dead cells.

7. Save an initial generation to an external file.

8. Retrieve a generation from that external file.

9. Remove saved generations.

10. Game rules.

11. Exit the program.

During the game, the user is asked about the desired number of generations and the simulation speed in seconds. Choosing a speed of 0 leads to a step-by-step progression, displaying each generation individually as it advances.

Upon returning to the main menu, the user can add new cells, save the game progress to an external file, show or hide neighboring dead cells in the world and restart the generation process. In addition to these options, there's a section explaining the game rules, providing essential insights for players to understand and succeed in the Game of Life.
## Media

<img src="https://github.com/manozita/game-of-life/blob/cde4191b3c582b8e179984bd074b02149bdad99f/media/1.jpg" width="700" />
<img src="https://github.com/manozita/game-of-life/blob/cde4191b3c582b8e179984bd074b02149bdad99f/media/2.jpg" width="700" />

## Contributions
Kauã Cordeiro Cavalheiro

Luan Bonasorte Capella

Nicolas Mariano

Teacher Eli Banks

#### The project was coded using C.
