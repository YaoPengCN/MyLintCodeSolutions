/** 
 * 514. Paint Fence
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * There is a fence with n posts, each post can be painted with one of the k colors.
 * You have to paint all the posts such that no more than two adjacent fence posts have the same color.
 * Return the total number of ways you can paint the fence.
 * 
 * Clarification
 * n and k are non-negative integers.
 * 
 * Example
 * Example 1
 * Input: n=3, k=2
 * Output: 6
 * Explanation:
 *       post 1,   post 2, post 3
 * way1    0         0       1 
 * way2    0         1       0
 * way3    0         1       1
 * way4    1         0       0
 * way5    1         0       1
 * way6    1         1       0
 * 
 * Example 2:
 * Input: n=2, k=2  
 * Output: 4
 * Explanation:
 *       post 1,   post 2
 * way1    0         0       
 * way2    0         1            
 * way3    1         0          
 * way4    1         1     
 *  
 * Related Problems 
 * 1142. Non-negative Integers without Consecutive Ones
 * 866. Coin Path
 * 535. House Robber III
 * 534. House Robber II
 * 516. Paint House II
 * 515. Paint House
 * 392. House Robber
 * 366. Fibonacci
 */

/**
 * Dynamic programming
 * Ref[1]: https://www.jiuzhang.com/problem/paint-fence/#tag-lang-cpp
 * Running Time: 50ms
 */
class Solution
{
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k)
    {
        vector<int> dp = {0, k, k * k, 0};
        if (n <= 2)
            return dp[n];
        if (k == 1)
            return 0;
        for (int i = 3; i <= n; ++i)
        {
            dp[3] = (k - 1) * (dp[1] + dp[2]);
            dp[1] = dp[2];
            dp[2] = dp[3];
        }
        return dp[3];
    }
};