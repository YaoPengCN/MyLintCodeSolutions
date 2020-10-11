/** 
 * 92. Backpack
 * Difficulty
 * Medium
 * 
 * Description
 * Given n items with size Ai, an integer m denotes the size of a backpack. 
 * How full you can fill this backpack?
 * 
 * Clarification
 * You can not divide any item into small pieces.
 *
 * Example
 * Example1
 * Input: [3,4,8,5], backpack size=10
 * Output: 9
 * 
 * Example2
 * Input: [2,3,5,7], backpack size=12
 * Output: 12
 * 
 * Challenge
 * O(n x m) time and O(m) memory.
 * O(n x m) memory is also acceptable if you do not know how to optimize memory.
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
 * 400. Backpack III
 * 279. Number of Ways to Represent N Cents
 * 125. Backpack II
 */

/**
 * Challenge
 * O(n x m) time and O(m) memory.
 * O(n x m) memory is also acceptable if you do not know how to optimize memory.
 * 
 * Ref[1]: https://mp.weixin.qq.com/s/RXfnhSpVBmVneQjDSUSAVQ
 * Ref[2]: https://www.jiuzhang.com/problem/backpack/#tag-lang-cpp
 * Run Time: 253ms
 */
class Solution
{
public:
	/**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
	int backPack(int m, vector<int> &A)
	{
		if (m == 0 || A.size() == 0)
			return 0;
		vector<int> dp(m + 1);
		for (int i = 0; i != A.size(); i++)
		{
			for (int j = m; j >= A[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
			}
		}
		return dp[m];
	}
};