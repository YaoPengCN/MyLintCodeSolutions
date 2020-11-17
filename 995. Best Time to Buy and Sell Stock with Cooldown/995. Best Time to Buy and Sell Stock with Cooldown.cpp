/** 
 * 995. Best Time to Buy and Sell Stock with Cooldown
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Say you have an array for which the i-th element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. 
 * You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
 * After you sell your stock, you cannot buy stock on next day. (i.e., cooldown 1 day)
 * 
 * Clarification
 * You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 * 
 * Example
 * Example 1
 * Input: [1, 2, 3, 0, 2]
 * Output: 3
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 * Example 2:
 * Input: [3,2,6,5,0,3]
 * Output: 7
 * 
 * Related Problems 
 * 1691. Best Time to Buy and Sell Stock V
 * 1000. Best Time to Buy and Sell Stock with Transaction Fee
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
 * Ref[2]: https://www.jiuzhang.com/problem/best-time-to-buy-and-sell-stock-with-cooldown/#tag-lang-cpp
 * Running Time: 50ms
 */

class Solution {
public:
    /**
     * @param prices: a list of integers
     * @return: return a integer
     */
    int maxProfit(vector<int> &prices) {
        int coldDown=1;
		if (coldDown < 0 || prices.size() == 0)
			return 0;

		// hold[i] = max(hold[i-1], rest[i-1] - prices[i])
		// sold[i] = hold[i-1] + prices[i]
		// rest[i] = max(rest[i-1], sold[i-1])
		// init: rest[0] = sold[0], hold[0] = INT_MIN
		// ans: max(rest[i], sold[i])
		// Time complexity: O(n)
		// Space complexity: O(n) -> O(1)

		int sold = 0, rest = 0, hold = INT_MIN;
		for (vector<int>::size_type i = 0; i != prices.size(); i++)
		{
			int prev_sold = sold;
            sold = hold + prices[i];
            hold = max(hold, rest - prices[i]);
            rest = max(rest, prev_sold);
		}
		return max(rest, sold);
    }
};