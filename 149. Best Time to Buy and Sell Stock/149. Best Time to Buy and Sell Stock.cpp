/** 
 * 149. Best Time to Buy and Sell Stock
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Say you have an array for which the i-th element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 *
 * Example
 * Example 1
 * Input: [3, 2, 3, 1, 2]
 * Output: 1
 * Explanation: You can buy at the third day and then sell it at the 4th day. The profit is 2 - 1 = 1
 * 
 * Example 2
 * Input: [1, 2, 3, 4, 5]
 * Output: 4
 * Explanation: You can buy at the 0th day and then sell it at the 4th day. The profit is 5 - 1 = 4
 * 
 * Example 3
 * IInput: [5, 4, 3, 2, 1]
 * Output: 0
 * Explanation: You can do nothing and get nothing.
 * 
 * Related Problems 
 * 1691. Best Time to Buy and Sell Stock V
 * 995. Best Time to Buy and Sell Stock with Cooldown
 * 393. Best Time to Buy and Sell Stock IV
 * 191. Maximum Product Subarray
 * 151. Best Time to Buy and Sell Stock III
 * 150. Best Time to Buy and Sell Stock II
 * 43. Maximum Subarray III
 * 42. Maximum Subarray II
 */

/**
 * Ref[1]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/tuan-mie-gu-piao-wen-ti
 * Ref[2]: https://www.jiuzhang.com/problem/best-time-to-buy-and-sell-stock/#tag-lang-cpp
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
		if (prices.size() <= 1)
			return 0;

		int result = 0;
		int minPrice = INT_MAX;

		for (vector<int>::size_type i = 0; i != prices.size(); i++)
		{
			result = max(result, prices[i] - minPrice);
			minPrice = min(minPrice, prices[i]);
		}
		return result;
	}
};