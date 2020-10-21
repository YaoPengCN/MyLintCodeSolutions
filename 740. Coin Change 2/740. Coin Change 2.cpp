/** 
 * 740. Coin Change 2
 * Difficulty
 * Medium
 * 
 * Description
 * You are given coins of different denominations and a total amount of money.
 * Write a function to compute the number of combinations that make up that amount.
 * You may assume that you have infinite number of each kind of coin.
 * 
 * Clarification
 * You can assume below:
 * 0 <= amount <= 5000
 * 1 <= coin <= 5000
 * the number of coins is less than 500
 * the answer is guaranteed to fit into signed 32-bit integer
 *
 * Example
 * Example 1
 * Input: amount = 10 and coins = [10] 
 * Output: 1
 * 
 * Example 2
 * Input: amount = 8 and coins = [2, 3, 8]
 * Output: 3
 * Explanation: 
 * there are three ways to make up the amount:
 * 8 = 8
 * 8 = 3 + 3 + 2
 * 8 = 2 + 2 + 2 + 2
 * 
 * Related Problems 
 * 564. Combination Sum IV
 * 563. Backpack V
 * 440. Backpack III
 * 153. Combination Sum II
 * 152. Combinations
 * 135. Combination Sum 
 */

/**
 * Since different orders are counted as same combinations, we should first traverse items in backpack problems. 
 * If different orders are counted as different combinations, we should first traverse capacity in backpack problems. (e.g. 564. Combination Sum IV)
 * Ref[1]: https://blog.csdn.net/u012280578/article/details/72934999
 * Ref[2]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/bei-bao-ling-qian
 * Ref[3]: https://www.jiuzhang.com/problem/coin-change-ii/
 * Running Time: 50ms
 */
class Solution
{
public:
	/**
     * @param amount: a total amount of money amount
     * @param coins: the denomination of each coin
     * @return: the number of combinations that make up the amount
     */
	int change(int amount, vector<int> &coins)
	{
		vector<int> dp(amount + 1);
		dp[0] = 1;
		for (vector<int>::size_type i = 0; i < coins.size(); i++)
		{
			for (int j = coins[i]; j <= amount; j++)
			{
				dp[j] += dp[j - coins[i]];
			}
		}
		return dp[amount];
	}
};