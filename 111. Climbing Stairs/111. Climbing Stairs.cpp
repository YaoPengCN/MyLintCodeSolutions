/** 
 * 111. Climbing Stairs
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. 
 * In how many distinct ways can you climb to the top?
 * 
 * Example
 * Example 1
 * Input:  n = 3
 * Output: 3
 * Explanation:
 * 1) 1, 1, 1
 * 2) 1, 2
 * 3) 2, 1
 * total 3.
 * 
 * Example 2:
 * Input:  n = 1
 * Output: 1
 * Explanation:  
 * only 1 way.
 *  
 * Related Problems 
 * 1142. Non-negative Integers without Consecutive Ones
 * 866. Coin Path
 * 535. House Robber III
 * 534. House Robber II
 * 515. Paint House
 * 514. Paint Fence
 * 392. House Robber
 * 366. Fibonacci
 */

/**
 * Dynamic programming
 * Running Time: 50ms
 */
class Solution
{
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n)
    {
        int stair1 = 1;
        int stair2 = 2;
        if (n <= 0)
            return 0;
        if (n == 1)
            return stair1;
        if (n == 2)
            return stair2;
        for (int i = 3; i <= n; i++)
        {
            int temp = stair2;
            stair2 = stair2 + stair1;
            stair1 = temp;
        }
        return stair2;
    }
};