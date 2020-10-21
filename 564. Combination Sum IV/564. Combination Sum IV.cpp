/** 
 * 564. Combination Sum IV
 * Difficulty
 * Medium
 * 
 * Description
 * Given an integer array nums with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
 * 
 * Clarification
 * A number in the array can be used multiple times in the combination.
 * Different orders are counted as different combinations.
 *
 * Example
 * Example 1
 * Input: nums = [1, 2, 4], and target = 4
 * Output: 6
 * Explanation:
 * The possible combination ways are:
 * [1, 1, 1, 1]
 * [1, 1, 2]
 * [1, 2, 1]
 * [2, 1, 1]
 * [2, 2]
 * [4]
 * 
 * Example 2
 * Input: nums = [1, 2], and target = 4
 * Output: 5
 * Explanation:
 * The possible combination ways are:
 * [1, 1, 1, 1]
 * [1, 1, 2]
 * [1, 2, 1]
 * [2, 1, 1]
 * [2, 2]
 * 
 * Related Problems 
 * 800. Backpack IX
 * 749. John's backyard garden
 * 740. Coin Change 2
 * 669. Coin Change
 * 588. Partition Equal Subset Sum
 * 563. Backpack V
 * 562. Backpack IV
 * 440. Backpack III
 * 125. Backpack II
 * 92. Backpack
 */

/**
 * Since different orders are counted as different combinations, we should first traverse target (i.e. capacity in backpack problems).
 * If different orders are counted as same combinations, we should first traverse items in backpack problems. (e.g. 740. Coin Change 2)
 * Ref: https://blog.csdn.net/u012280578/article/details/72934999
 * Run Time: 50ms
 */
class Solution
{
public:
	/**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
	int backPackVI(vector<int> &nums, int target)
	{
		vector<int>::size_type n = nums.size();
		vector<int> f(target + 1, 0);
		f[0] = 1;
		for (int i = 1; i <= target; i++)
		{
			for (int j = 0; j < n; j++)
				if (i - nums[j] >= 0)
				{
					f[i] += f[i - nums[j]];
				}
		}
		return f[target];
	}
};