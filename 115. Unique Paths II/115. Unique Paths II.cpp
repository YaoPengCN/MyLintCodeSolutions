/** 
 * 115. Unique Paths II
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Follow up for "Problem 114. Unique Paths":
 * A robot is located at the top-left corner of a m x n grid.
 * The robot can only move either down or right at any point in time. 
 * The robot is trying to reach the bottom-right corner of the grid.
 * How many possible unique paths are there?
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Clarification
 * m and n will be at most 100.
 * 
 * Example
 * Example 1
 * Input: [[0]]
 * Output: 1
 * 
 * Example 2:
 * Input:  [[0,0,0],[0,1,0],[0,0,0]]
 * Output: 2
 * Explanation:
 * Only 2 different path.
 *  
 * Related Problems
 * 1543. Unique Path IV
 * 796. Open the Lock
 * 795. 4-Way Unique Paths
 * 114. Unique Paths
 */

/**
 * dynamic programming
 * 
 * Running Time: 101ms
 */

class Solution
{
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.empty())
            return -1;

        vector<int>::size_type row = obstacleGrid.size();
        vector<int>::size_type column = obstacleGrid[0].size();

        vector<int> dp(column);

        // once obstacleGrid[j][0]==1, dp[0]=0 for the rest columns
        for (vector<int>::size_type i = 0; i != column && !obstacleGrid[0][i]; i++)
        {
            dp[i] = 1;
        }

        for (vector<int>::size_type j = 1; j != row; j++)
        {
            // once obstacleGrid[j][0]==1, dp[0]=0 for the rest rows
            if (obstacleGrid[j][0] == 1)
            {
                dp[0] = 0;
            }

            for (vector<int>::size_type i = 1; i != column; i++)
            {
                dp[i] += obstacleGrid[j][i] ? -dp[i] : dp[i - 1];
            }
        }
        return dp[column - 1];
    }
};