/** 
 * 515. Paint House
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. 
 * You have to paint all the houses such that no two adjacent houses have the same color, and you need to cost the least. 
 * Return the minimum cost.
 * The cost of painting each house with a certain color is represented by a n x 3 cost matrix. 
 * For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... 
 * Find the minimum cost to paint all houses.
 * 
 * Clarification
 * All costs are positive integers.
 * 
 * Example
 * Example 1
 * Input: [[14,2,11],[11,14,5],[14,3,10]]
 * Output: 10
 * Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue. 
 * Minimum cost: 2 + 5 + 3 = 10.
 * 
 * Example 2:
 * Input: [[1,2,3],[1,4,6]]
 * Output: 3 
 *  
 * Related Problems
 * 1310. Product of Array Except Self 
 * 1142. Non-negative Integers without Consecutive Ones
 * 866. Coin Path
 * 535. House Robber III
 * 534. House Robber II
 * 516. Paint House II
 * 514. Paint Fence
 * 392. House Robber
 * 366. Fibonacci
 */

/**
 * Dynamic programming
 * Ref[1]: https://www.jiuzhang.com/problem/paint-house/
 * Running Time: 101ms
 */
class Solution
{
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        if (n == 0)
            return 0;

        // dp[i][j] represents min cost of the i-th house painting j-th color
        vector<vector<int>> dp(2);
        for (int i = 0; i != 3; i++)
        {
            dp[0].push_back(costs[0][i]);
            dp[1].push_back(0);
        }

        for (int i = 1; i != n; i++)
        {
            for (int j = 0; j != 3; j++)
            {
                dp[i & 1][j] = INT_MAX;
                for (int k = 0; k != 3; k++)
                {
                    if (k != j)
                    {
                        dp[i & 1][j] = min(dp[i & 1][j], dp[i & 1 ^ 1][k] + costs[i][j]);
                    }
                }
            }
        }
        return min(dp[n & 1 ^ 1][0], min(dp[n & 1 ^ 1][1], dp[n & 1 ^ 1][2]));
    }
};