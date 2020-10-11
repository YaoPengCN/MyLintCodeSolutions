/** 
 * 588. Partition Equal Subset Sum
 * Difficulty
 * Medium
 * 
 * Description
 * Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
 * 
 * Clarification
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 *
 * Example
 * Example 1
 * Input: nums = [1, 5, 11, 5]
 * Output: true
 * Explanation: two subsets: [1, 5, 5], [11]
 * 
 * Example 2
 * Input: nums = [1, 2, 3, 9]
 * Output: false
 * 
 * Related Problems 
 * 563. Backpack V
 * 562. Backpack IV
 * 440. Backpack III
 * 125. Backpack II
 * 92. Backpack
 */

/**
 * Ref[1]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/bei-bao-zi-ji
 * Ref[2]: https://www.jiuzhang.com/problem/partition-equal-subset-sum/
 * Run Time: 251ms
 */
class Solution
{
public:
	/**
     * @param nums: a non-empty array only positive integers
     * @return: true if can partition or false
     */
	bool canPartition(vector<int> &nums)
	{
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 == 1)
			return false;
		int capacity = sum / 2;
		vector<bool> dp(capacity + 1, false);
		// bool dp[capacity + 1] = {false};
		dp[0] = true;
		for (vector<int>::size_type i = 0; i != nums.size(); i++)
			for (vector<int>::size_type j = capacity; j >= nums[i]; j--)
				dp[j] = dp[j] || dp[j - nums[i]];
		return dp[capacity];
	}
};