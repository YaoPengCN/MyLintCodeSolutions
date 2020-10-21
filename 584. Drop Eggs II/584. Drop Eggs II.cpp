/** 
 * 584. Drop Eggs II
 * Difficulty
 * Medium
 * 
 * Description
 * There is a building of n floors. If an egg drops from the k th floor or above, it will break. 
 * If it's dropped from any floor below, it will not break.
 * You're given m eggs, Find k while minimize the number of drops for the worst case. 
 * Return the number of drops in the worst case.
 *
 * Example
 * Example 1
 * Input: m = 2, n = 100 
 * Output: 14
 * 
 * Example 2
 * Input: m = 2, n = 36 
 * Output: 8
 * 
 * Related Problems 
 * 254. Drop Eggs
 */

/**
 * Leaderboard, TOP ONE solution
 * change the parameterization of the problem fi = max # floors we can cover using i trials and j eggs fi = 1 + fi-1 + fi-1 given m, n, we need to find first i such that fi >= n
 * Time complexity <= O(M * sqrt(N)) why? because when M >= 2, # trials is at most sqrt(N) (from Egg drop I result)
 * Ref[1]: https://www.jiuzhang.com/problem/drop-eggs-ii/
 * Running Time: 50ms
 */
class Solution
{
public:
    /**
     * @param m: the number of eggs
     * @param n: the number of floors
     * @return: the number of drops in the worst case
     */
    int dropEggs2(int m, int n)
    {
        // write your code here
        if (m == 0)
        {
            return n == 0 ? 0 : -1;
        }
        if (n <= 1)
        {
            return n;
        }

        vector<int> f(m + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                f[j] += 1 + f[j - 1];
            }
            // if i is large enough, return the result
            if (f[m] >= n)
            {
                return i;
            }
        }
    }
};

// /**
//  * Ref[1]: https://mp.weixin.qq.com/s/xn4LjWfaKTPQeCXR0qDqZg
//  * Ref[2]: https://www.jiuzhang.com/problem/drop-eggs-ii/
//  * Running Time: 101ms
//  */
// class Solution
// {
// public:
//     /**
//      * @param m: the number of eggs
//      * @param n: the number of floors
//      * @return: the number of drops in the worst case
//      */
//     int dropEggs2(int m, int n)
//     {
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//         //int[][] dp = new int[m + 1][n + 1];

//         for (int i = 1; i <= m; ++i)
//         {
//             dp[i][1] = 1;
//             dp[i][0] = 0;
//         }

//         // Only have one egg.
//         for (int j = 1; j <= n; ++j)
//             dp[1][j] = j;

//         for (int i = 2; i <= m; ++i)
//         {
//             for (int j = 2; j <= n; ++j)
//             {
//                 dp[i][j] = INT_MAX;
//                 for (int k = 1; k <= j; ++k)
//                 // k present that the first egg is dropped from the k-th floor.
//                 {
//                     dp[i][j] = min(dp[i][j], 1 + max(dp[i - 1][k - 1], dp[i][j - k]));
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };