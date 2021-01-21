/** 
 * 114. Unique Paths
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * A robot is located at the top-left corner of a m x n grid.
 * The robot can only move either down or right at any point in time. 
 * The robot is trying to reach the bottom-right corner of the grid.
 * How many possible unique paths are there?
 * 
 * Clarification
 * m and n will be at most 100.
 * The answer is guaranteed to be in the range of 32-bit integers
 * 
 * Example
 * Example 1
 * Input: n = 1, m = 3
 * Output: 1
 * Explanation: Only one path to target position.
 * 
 * Example 2:
 * Input:  n = 3, m = 3
 * Output: 6
 * Explanation:
 * 	D : Down
 * 	R : Right
 * 	1) DDRR
 * 	2) DRDR
 * 	3) DRRD
 * 	4) RRDD
 * 	5) RDRD
 * 	6) RDDR
 *  
 * Related Problems
 * 1543. Unique Path IV
 * 795. 4-Way Unique Paths
 * 679. Unique Paths III
 */

/**
 * return (n + m - 2)! / ((m - 1)! * (n - 1)!) would be accepted using Python, not C++
 * 
 * dynamic programming
 * 
 * Running Time: 54ms
 */

class Solution
{
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n)
    {
        if (m < 1 || n < 1)
            return -1;

        if (m == 1 || n == 1)
        {
            return 1;
        }

        vector<vector<int>> dp(m, vector<int>(n));
        for (vector<int>::size_type i = 0; i != m; i++)
        {
            dp[i][0] = 1;
        }
        for (vector<int>::size_type i = 0; i != n; i++)
        {
            dp[0][i] = 1;
        }

        for (vector<int>::size_type i = 1; i != m; i++)
            for (vector<int>::size_type j = 1; j != n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }

        return dp[m - 1][n - 1];
    }
};