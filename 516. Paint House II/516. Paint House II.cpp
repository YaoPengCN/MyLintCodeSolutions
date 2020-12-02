/** 
 * 516. Paint House II
 * 
 * Difficulty
 * Hard
 * 
 * Description
 * There are a row of n houses, each house can be painted with one of the k colors. 
 * The cost of painting each house with a certain color is different. 
 * You have to paint all the houses such that no two adjacent houses have the same color.
 * The cost of painting each house with a certain color is represented by a n x k cost matrix. 
 * For example, costs[0][0] is the cost of painting house 0 with color 0; 
 * costs[1][2] is the cost of painting house 1 with color 2, and so on... 
 * Find the minimum cost to paint all houses.
 * 
 * Clarification
 * All costs are positive integers.
 * 
 * Example
 * Example 1
 * Input:
 * costs = [[14,2,11],[11,14,5],[14,3,10]]
 * Output: 10
 * Explanation:
 * The three house use color [1,2,1] for each house. The total cost is 10.
 * 
 * Example 2:
 * Input:
 * costs = [[5]]
 * Output: 5
 * Explanation:
 * There is only one color and one house.
 *  
 * Challenge
 * Could you solve it in O(nk)?
 * 
 * Related Problems
 * 1310. Product of Array Except Self 
 * 1142. Non-negative Integers without Consecutive Ones
 * 866. Coin Path
 * 535. House Robber III
 * 534. House Robber II
 * 515. Paint House
 * 514. Paint Fence
 * 392. House Robber
 * 366. Fibonacci
 * 362. Sliding Window Maximum
 * 267. minimum rest days
 * 50. Product of Array Exclude Itself
 */

/**
 * Challenge
 * Could you solve it in O(nk)?
 * 
 * Dynamic programming
 * Ref[1]: https://www.jiuzhang.com/problem/paint-house-ii/
 * 
 * Time complexity O(k), space complexity O(nk)
 * 
 * Running Time: 252ms
 */
class Solution
{
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs)
    {
        int n = costs.size();

        if (n == 0)
        {
            return 0;
        }

        int k = costs[0].size();

        // dp[i][j] represents min cost of the i-th house painting j-th color
        vector<vector<int>> dp(2);

        for (int i = 0; i != k; i++)
        {
            dp[0].push_back(costs[0][i]);
            dp[1].push_back(0);
        }

        // minCost represents the minimun cost,
        // minSecontCost represents the second minimum cost
        int minCost, minSecondCost;

        for (int i = 1; i != n; i++)
        {
            minCost = INT_MAX;
            minSecondCost = INT_MAX;

            for (int j = 0; j != k; j++)
            {
                if (dp[i & 1 ^ 1][j] <= minCost)
                {
                    minSecondCost = minCost;
                    minCost = dp[i & 1 ^ 1][j];
                }
                else if (dp[i & 1 ^ 1][j] < minSecondCost)
                {
                    minSecondCost = dp[i & 1 ^ 1][j];
                }
            }
            for (int j = 0; j != k; j++)
            {
                // if the minimum cost requires the same color
                if (dp[i & 1 ^ 1][j] == minCost)
                {
                    dp[i & 1][j] = minSecondCost + costs[i][j];
                }
                else
                {
                    dp[i & 1][j] = minCost + costs[i][j];
                }
            }
        }
        minCost = INT_MAX;

        for (int j = 0; j != k; j++)
        {
            minCost = min(minCost, dp[n & 1 ^ 1][j]);
        }

        return minCost;
    }
};