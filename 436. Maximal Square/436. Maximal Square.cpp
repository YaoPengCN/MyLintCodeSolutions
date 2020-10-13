/** 
 * 436. Maximal Square
 * Difficulty
 * Medium
 * 
 * Description
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
 *
 * Example
 * Example 1
 * Input:
 * [
 *  [1, 0, 1, 0, 0], 
 *  [1, 0, 1, 1, 1],
 *  [1, 1, 1, 1, 1],
 *  [1, 0, 0, 1, 0]
 * ]
 * Output: 4
 * 
 * Example 2
 * Input:
 * [
 *  [0, 0, 0],
 *  [1, 1, 1]
 * ]
 * Output: 1
 * 
 * Related Problems 
 * 1044. Largest Plus Sign
 * 697. Sum of Square Numbers
 * 631. Maximal Square II
 * 510. Maximal Rectangle
 */

/**
 * Ref: https://www.jiuzhang.com/problem/maximal-square/#tag-lang-cpp
 * Run Time: 151ms
 */

class Solution
{
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if (!n || !m)
            return 0;

        vector<vector<int>> dp(n, vector<int>(m));
        // dp[i][j] records the edge length of the maximum square with its lower-right corner starting from matrix[i][j]

        for (int i = 0; i != m; i++)
            dp[0][i] = matrix[0][i];

        for (int i = 0; i != n; i++)
            dp[i][0] = matrix[i][0];

        for (int i = 1; i != n; i++)
            for (int j = 1; j != m; j++)
            {
                if (matrix[i][j])
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                else
                    dp[i][j] = 0;
            }

        int ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans = max(ans, dp[i][j]);
        return ans * ans;
    }
};