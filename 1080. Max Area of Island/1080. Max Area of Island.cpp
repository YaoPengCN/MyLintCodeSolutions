/** 
 * 1080. Max Area of Island
 * Difficulty
 * Easy
 * 
 * Description
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical).
 * You may assume all four edges of the grid are surrounded by water.
 * Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
 * 
 * Clarification
 * The size() of each dimension in the given grid does not exceed 50.
 *
 * Example
 * Example 1
 * input:
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,1,1,0,1,0,0,0,0,0,0,0,0],
 *  [0,1,0,0,1,1,0,0,1,0,1,0,0],
 *  [0,1,0,0,1,1,0,0,1,1,1,0,0],
 *  [0,0,0,0,0,0,0,0,0,0,1,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * output:
 * 6
 * Explanation: 
 * Note the answer is not 11, because the island must be connected 4-directionally.
 * 
 * Example 2
 * input: [[0,0,0,0,0,0,0,0]]
 * output: 0
 * 
 * Related Problems
 * 1225. Island Perimeter
 * */

/**
 * DFS
 * Run Time: 50ms
 */

class Solution
{
public:
	/**
     * @param grid: a 2D array
     * @return: the maximum area of an island in the given 2D array
     */
	int maxAreaOfIsland(vector<vector<int>> &grid)
	{
		int maxArea = 0;
		for (int i = 0; i != grid.size(); i++)
			for (int j = 0; j != grid[i].size(); j++)
				if (grid[i][j] == 1)
					maxArea = max(maxArea, dfs(grid, i, j));
		return maxArea;
	}

private:
	int dfs(vector<vector<int>> &grid, int i, int j)
	{
		int currentArea = 0;
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0)
		{
			return 0;
		}
		else
		{
			currentArea = 1;
			grid[i][j] = 0;
			currentArea += dfs(grid, i + 1, j);
			currentArea += dfs(grid, i - 1, j);
			currentArea += dfs(grid, i, j + 1);
			currentArea += dfs(grid, i, j - 1);
		}
		return currentArea;
	}
};