/** 
 * 125. Backpack II
 * Difficulty
 * Medium
 * 
 * Description
 * There are n items and a backpack with size m.
 * Given array A representing the size of each item and array V representing the value of each item.
 * 
 * Clarification
 * A[i], V[i], n, m are all integers.
 * You can not split an item.
 * The sum size of the items you want to put into backpack can not exceed m.
 * Each item can only be picked up once
 *
 * Example
 * Example 1
 * Input: m = 10, A = [2, 3, 5, 7], V = [1, 5, 2, 4]
 * Output: 9
 * Explanation: Put A[1] and A[3] into backpack, getting the maximum value V[1] + V[3] = 9 
 * 
 * Example 2
 * Input: m = 10, A = [2, 3, 8], V = [2, 5, 8]
 * Output: 10
 * Explanation: Put A[0] and A[2] into backpack, getting the maximum value V[0] + V[2] = 10 
 * 
 * Challenge
 * O(nm) memory is acceptable, can you do it in O(m) memory?
 * 
 * Related Problems 
 * 1538. Card Game II
 * 800. Backpack IX
 * 749. John's backyard garden
 * 724. Minimum Partition
 * 700. Cutting a Rod
 * 669. Coin Change
 * 588. Partition Equal Subset Sum
 * 564. Combination Sum IV
 * 563. Backpack V
 * 562. Backpack IV
 * 440. Backpack III
 * 279. Number of Ways to Represent N Cents
 * 125. Backpack II
 */

/**
 * Challenge
 * O(nm) memory is acceptable, can you do it in O(m) memory?
 * 
 * Ref[1]: https://mp.weixin.qq.com/s/RXfnhSpVBmVneQjDSUSAVQ
 * Ref[2]: https://www.jiuzhang.com/problem/backpack-ii/
 * Running Time: 50ms
 */
class Solution
{
public:
	/**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
	int backPackII(int m, vector<int> &A, vector<int> &V)
	{
		if (m == 0 || A.size() == 0)
			return 0;
		vector<int> dp(m + 1);
		for (int i = 0; i != A.size(); i++)
		{
			for (int j = m; j >= A[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
			}
		}
		return dp[m];
	}
};

// /**
//  * Ref[1]: https://mp.weixin.qq.com/s/RXfnhSpVBmVneQjDSUSAVQ
//  * Ref[2]: https://www.jiuzhang.com/problem/backpack-ii/
//  * Running Time: 51ms
//  */
// class Solution
// {
// public:
// 	/**
//      * @param m: An integer m denotes the size of a backpack
//      * @param A: Given n items with size A[i]
//      * @param V: Given n items with value V[i]
//      * @return: The maximum value
//      */
// 	int backPackII(int m, vector<int> &A, vector<int> &V)
// 	{
// 		vector<int>::size_type n=A.size();
// 		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
// 		for (int i = 1; i <= n; i++)
// 		{
// 			for (int w = 1; w <= m; w++)
// 			{
// 				if (w - A[i - 1] < 0)
// 				{
// 					// 当前背包容量装不下，只能选择不装入背包
// 					dp[i][w] = dp[i - 1][w];
// 				}
// 				else
// 				{
// 					// 装入或者不装入背包，择优
// 					dp[i][w] = max(dp[i - 1][w - A[i - 1]] + V[i - 1], dp[i - 1][w]);
// 				}
// 			}
// 		}
// 		return dp[n][m];
// 	}
// };