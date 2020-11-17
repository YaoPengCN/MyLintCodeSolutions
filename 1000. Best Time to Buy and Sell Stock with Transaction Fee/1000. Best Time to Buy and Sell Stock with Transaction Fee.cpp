/** 
 * 1000. Best Time to Buy and Sell Stock with Transaction Fee
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given an array of integers prices, for which the i-th element is the price of a given stock on day i;
 * and a non-negative integer fee representing a transaction fee. (You need to pay fee only on selling.)
 * Return the maximum profit you can make.
 * 
 * Clarification
 * You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 * 0 < prices.length <= 50000.
 * 0 < prices[i] < 50000.
 * 0 <= fee < 50000.
 * 
 * Example
 * Example 1
 * Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
 * Output: 8
 * Explanation: The maximum profit can be achieved by:
 * Buying  at prices[0] = 1
 * Selling at prices[3] = 8
 * Buying  at prices[4] = 4
 * Selling at prices[5] = 9
 * The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 * 
 * Example 2:
 * Input: prices = [1, 4, 6, 2, 8, 3, 10, 14], fee = 3
 * Output: 13
 * 
 * Related Problems 
 * 1691. Best Time to Buy and Sell Stock V
 * 995. Best Time to Buy and Sell Stock with Cooldown
 * 393. Best Time to Buy and Sell Stock IV
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
 * Dynamic programming
 * Ref[1]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/tuan-mie-gu-piao-wen-ti
 * Ref[2]: https://www.jiuzhang.com/problem/best-time-to-buy-and-sell-stock-with-transaction-fee/#tag-lang-cpp
 * Running Time: 101ms
 */
class Solution
{
public:
	/**
     * @param prices: a list of integers
     * @param fee: a integer
     * @return: return a integer
     */
	int maxProfit(vector<int> &prices, int fee)
	{
		if (prices.size() == 0)
			return 0;

		int sell = 0, own = -prices[0];
        for (int price : prices) {
            int sellOld = sell;
            sell = max(sell, own + price - fee);
            own = max(own, sellOld - price);
        }
        return sell;
	}
};