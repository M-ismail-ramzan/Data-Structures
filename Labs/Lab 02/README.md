# Task 1:
## a. Linear Search:
Write a program to perform linear search in 2D array.
Let arr=[[12,43,66,78],[34,21,72,81],[7,13,2,59]]
Find Element=2
## b. Binary search:
Write a program to perform binary search in 2D array.
Let arr=[[10,20,30,40],[15,25,35,45],[27,29,37,48],[32,33,39,50]]
Find Element=29
# Task 2:
Game of Life
Introduction to Life
Game of Life (or just “Life”) is not really a game. There’s no winning or losing or destroying
your opponent mentally and spiritually. Life is a “cellular automaton” - a system of cells that live
on a grid, where they live, die and evolve according to the rules that govern their world.
Life’s simple, elegant rules give rise to astonishingly complex emergent behavior. It is played on
a 2-D grid Each square in the grid contains a cell, and each cell starts the game as either “alive”
or “dead”. Play proceeds in rounds. During each round, each cell looks at its 8 immediate
neighbors and counts up the number of them that are currently alive.
Make a type char 30 x 30 2D grid. Randomly assign active and dead cells. Active cells will have
value ‘*’ and dead cell will have value

The cell then updates its own liveness according to 4 rules:
1. Any live cell with 0 or 1 live neighbors becomes dead, because of underpopulation
2. Any live cell with 2 or 3 live neighbors stays alive, because its neighborhood is just right
3. Any live cell with more than 3 live neighbors becomes dead, because of overpopulation
4. Any dead cell with exactly 3 live neighbors becomes alive, by reproduction
Run your code for infinite rounds and observe the pattern changing
And that’s all there is to Life. These 4 rules give rise to some unbelievably complex and
beautiful patterns, and an equally unbelievable quantity of analysis by Life devotees intent on
discovering new ones.
