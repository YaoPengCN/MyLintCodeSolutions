/** 
 * 110. Minimum Path Sum
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a m x n grid filled with non-negative numbers, 
 * find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Clarification
 * You can only go right or down in the path.
 * 
 * Example
 * Example 1
 * Input: [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation:	Path is: 1 -> 3 -> 1 -> 1 -> 1
 * 
 * Example 2:
 * Input: [[1,3,2]]
 * Output: 6
 * Explanation:  
 * Path is: 1 -> 3 -> 2
 *  
 * Related Problems
 * 1682. Minimum Path Sum II
 * 1058. Cherry Pickup
 * 794. Sliding Puzzle II
 * 109. Triangle 
 * 94. Binary Tree Maximum Path Sum
 */

/**
 * Dynamic programming
 * Space complexity: O(M+N)
 * Running Time: 101ms
 */
class Solution
{
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;

        vector<int> dpRow;
        vector<int> dpColumn;

        dpRow.push_back(grid[0][0]);
        dpColumn.push_back(grid[0][0]);

        for (int i = 1; i != grid[0].size(); i++)
            dpRow.push_back(dpRow[i - 1] + grid[0][i]);
        for (int i = 1; i != grid.size(); i++)
            dpColumn.push_back(dpColumn[i - 1] + grid[i][0]);

        for (int i = 1; i != grid.size(); i++)
        {
            for (int j = 1; j != grid[0].size(); j++)
            {
                dpRow[j] = min(dpRow[j], dpColumn[i]) + grid[i][j];
                dpColumn[i] = dpRow[j];
            }
        }

        return dpRow[dpRow.size() - 1];
    }
};

// /**
//  * Dynamic programming
//  * Ref: https://mp.weixin.qq.com/s/cwunN4Uoo4ZfO13kgkHVPQ
//  * Running Time: 101ms
//  */
// class Solution
// {
// public:
//     /**
//      * @param grid: a list of lists of integers
//      * @return: An integer, minimizes the sum of all numbers along its path
//      */
//     int minPathSum(vector<vector<int>> &grid)
//     {
//         if (grid.empty())
//             return 0;

//         vector<vector<int>> dp;

//         vector<int> temp;
//         for (vector<int>::size_type i = 0; i != grid[0].size(); i++)
//             temp.push_back(INT_MAX);

//         for (vector<int>::size_type i = 0; i != grid.size(); i++)
//             dp.push_back(temp);

//         dp[0][0] = grid[0][0];

//         for (int i = 1; i != grid[0].size(); i++)
//             dp[0][i] = dp[0][i - 1] + grid[0][i];

//         for (int i = 1; i != grid.size(); i++)
//             dp[i][0] = dp[i - 1][0] + grid[i][0];

//         for (int i = 1; i != grid.size(); i++)
//         {
//             for (int j = 1; j != grid[0].size(); j++)
//             {
//                 dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
//             }
//         }

//         return dp[grid.size() - 1][grid[0].size() - 1];
//     }
// };