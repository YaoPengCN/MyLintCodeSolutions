/** 
 * 393. Best Time to Buy and Sell Stock IV
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given an array prices and the i-th element of it represents the price of a stock on the i-th day.
 * You may complete at most k transactions. What's the maximum profit?
 * 
 * Clarification
 * You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 * 
 * Example
 * Example 1
 * Input: k = 2, prices = [4, 4, 6, 1, 1, 4, 2 ,5]
 * Output: 6
 * Explanation: Buy at 4 and sell at 6. Then buy at 1 and sell at 5. Your profit is 2 + 4 = 6.
 * 
 * Example 2:
 * Input: k = 1, prices = [3, 2, 1]
 * Output: 0
 * Explanation: No transaction.
 * 
 * Challenge
 * O(nk) time. n is the size of prices.
 * 
 * Related Problems 
 * 1691. Best Time to Buy and Sell Stock V
 * 1000. Best Time to Buy and Sell Stock with Transaction Fee
 * 995. Best Time to Buy and Sell Stock with Cooldown
 * 191. Maximum Product Subarray
 * 151. Best Time to Buy and Sell Stock III
 * 150. Best Time to Buy and Sell Stock II
 * 149. Best Time to Buy and Sell Stock
 * 45. Maximum Subarray Difference
 * 43. Maximum Subarray III
 * 42. Maximum Subarray II
 * 41. Maximum Subarray
 */

/**
 * Challenge
 * O(nk) time. n is the size of prices.
 * 
 * Dynamic programming
 * Ref[1]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/tuan-mie-gu-piao-wen-ti
 * Ref[2]: https://www.jiuzhang.com/problem/best-time-to-buy-and-sell-stock-iv/#tag-lang-cpp
 * Running Time: 151ms
 */
class Solution
{
public:
	/**
     * @param K: An integer
     * @param prices: An integer array
     * @return: Maximum profit
     */
	int maxProfit(int K, vector<int> &prices)
	{
		if (K == 0 || prices.size() == 0)
			return 0;

		// if K > prices.size() / 2, then this case equals to the case of infinity transactions.
		if (K > prices.size() / 2)
		{
			int res = 0;
			for (vector<int>::size_type i = 1; i != prices.size(); i++)
			{
				res += max(0, prices[i] - prices[i - 1]);
			}
			return res;
		}

		// if K <= prices.size() / 2
		vector<vector<int>> dp(K + 1, vector<int>(prices.size()));
		for (vector<vector<int>>::size_type i = 1; i != dp.size(); i++)
		{
			int maxDiff = -prices[0];
			for (vector<int>::size_type j = 1; j != dp[0].size(); j++)
			{
				maxDiff = max(maxDiff, dp[i - 1][j - 1] - prices[j]);
				dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
			}
		}
		return dp[K][prices.size() - 1];
	}
};