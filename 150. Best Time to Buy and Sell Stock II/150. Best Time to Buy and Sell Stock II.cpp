/** 
 * 150. Best Time to Buy and Sell Stock II
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given an array prices, which represents the price of a stock in each day.
 * You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
 * However, you may not engage in multiple transactions at the same time (ie, if you already have the stock, you must sell it before you buy again).
 * Design an algorithm to find the maximum profit.
 *
 * Example
 * Example 1
 * Input: [2, 1, 2, 0, 1]
 * Output: 2
 * Explanation:
 * 1. Buy the stock on the second day at 1, and sell the stock on the third day at 2. Profit is 1.
 * 2. Buy the stock on the 4th day at 0, and sell the stock on the 5th day at 1. Profit is 1.
 * Total profit is 2.
 * 
 * Example 2
 * Input: [4, 3, 2, 1]
 * Output: 0
 * Explanation: No transaction, profit is 0.
 * 
 * Related Problems 
 * 1691. Best Time to Buy and Sell Stock V
 * 1000. Best Time to Buy and Sell Stock with Transaction Fee
 * 995. Best Time to Buy and Sell Stock with Cooldown
 * 393. Best Time to Buy and Sell Stock IV
 * 191. Maximum Product Subarray
 * 151. Best Time to Buy and Sell Stock III
 * 149. Best Time to Buy and Sell Stock
 * 43. Maximum Subarray III
 * 42. Maximum Subarray II
 */

/**
 * Greedy algorithm
 * Ref[1]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/tuan-mie-gu-piao-wen-ti
 * Ref[2]: https://www.jiuzhang.com/problem/best-time-to-buy-and-sell-stock-ii/#tag-lang-cpp
 * Running Time: 101ms
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
		if (prices.size() <= 1)
			return 0;
		int profit = 0;
		for (vector<int>::size_type i = 1; i != prices.size(); i++)
		{
			if (prices[i] > prices[i - 1])
			{
				profit += prices[i] - prices[i - 1];
			}
		}
		return profit;
	}
};