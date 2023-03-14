#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid
 * @grid: the grid
 * @height: height of the grid
 */
void free_grid(int **grid, int height)
{
int y;

for (y = 0; y < height; y++)
free(grid[y]);
free(grid);
}
