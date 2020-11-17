/** 
 * 151. Best Time to Buy and Sell Stock III
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Say you have an array for which the i-th element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 * Clarification
 * You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 * 
 * Example
 * Input: [4,4,6,1,1,4,2,5]
 * Output: 6
 * 
 * Related Problems 
 * 1691. Best Time to Buy and Sell Stock V
 * 1000. Best Time to Buy and Sell Stock with Transaction Fee
 * 995. Best Time to Buy and Sell Stock with Cooldown
 * 393. Best Time to Buy and Sell Stock IV
 * 191. Maximum Product Subarray
 * 150. Best Time to Buy and Sell Stock II
 * 149. Best Time to Buy and Sell Stock
 * 45. Maximum Subarray Difference
 * 43. Maximum Subarray III
 * 42. Maximum Subarray II
 * 41. Maximum Subarray
 */

/**
 * Dynamic programming
 * Ref[1]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/tuan-mie-gu-piao-wen-ti
 * Ref[2]: https://www.jiuzhang.com/problem/best-time-to-buy-and-sell-stock-iii/#tag-lang-cpp
 * Running Time: 50ms
 */
class Solution
{
public:
	/**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
	int maxProfit(vector<int> &prices)
	{
		if (prices.size() == 0)
			return 0;

		int k = 2;

		vector<vector<int>> dp(k + 1, vector<int>(prices.size()));
		for (vector<vector<int>>::size_type i = 1; i != dp.size(); i++)
		{
			int maxDiff = -prices[0];
			for (vector<int>::size_type j = 1; j != dp[0].size(); j++)
			{
				maxDiff = max(maxDiff, dp[i - 1][j - 1] - prices[j]);
				dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
			}
		}
		return dp[k][prices.size() - 1];
	}
};