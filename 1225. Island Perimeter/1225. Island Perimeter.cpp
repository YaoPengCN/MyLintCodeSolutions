/** 
 * 1225. Island Perimeter
 * Difficulty
 * Easy
 * 
 * Description
 * You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. 
 * Grid cells are connected horizontally/vertically (not diagonally). 
 * The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). 
 * The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
 * One cell is a square with side length 1. 
 * The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
 * 
 * Clarification
 * The size() of each dimension in the given grid does not exceed 50.
 *
 * Example
 * Example 1
 * input:
 * [[0,1,0,0],
 *  [1,1,1,0],
 *  [0,1,0,0],
 *  [1,1,0,0]]
 * output:
 * 16
 * 
 * Related Problems
 * 1080. Max Area of Island
 * 1062. Flood Fill
 * */

/**
 * Running Time: 50ms
 */

class Solution
{
public:
	/**
     * @param grid: a 2D array
     * @return: the perimeter of the island
     */
	int islandPerimeter(vector<vector<int>> &grid)
	{
		int perimeter = 0;
		for (int i = 0; i != grid.size(); i++)
			for (int j = 0; j != grid[i].size(); j++)
			{
				if (grid[i][j] == 1)
				{
					perimeter += 4 - (i - 1 >= 0 && grid[i - 1][j]) - (i + 1 != grid.size() && grid[i + 1][j]) - (j - 1 >= 0 && grid[i][j - 1]) - (j + 1 != grid[i].size() && grid[i][j + 1]);
//					perimeter += (i == 0 || !grid[i - 1][j]) + (i == grid.size() - 1 || !grid[i + 1][j]) + (j == 0 || !grid[i][j - 1]) + (j == grid[i].size() - 1 || !grid[i][j + 1]);
				}
			}
		return perimeter;
	}
};