/** 
 * 1238. Find All Duplicates in an Array
 * Difficulty
 * Medium
 * 
 * Description
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 * Find all the elements that appear twice in this array.
 *
 * Example
 * Example 1
 * Input:
 * [4,3,2,7,8,2,3,1]
 * Output:
 * [2,3]
 * 
 * Example2
 * Input:
 * [10,2,5,10,9,1,1,4,3,7]
 * Output:
 * [1,10]
 * 
 * Challenge
 * Could you do it without extra space and in O(n) runtime?
 * 
 * */

/**
 * Challenge
 * Could you do it without extra space and in O(n) runtime?
 * 
 * Since 1 ≤ a[i] ≤ n (n = size of array), use a[i]-1 as the index.
 * Note that some elements appear twice and others appear once
 * Get the opposite number of a[abs(a[i])-1], if a[abs(a[i])-1] has already been negative, then a[abs(a[i])-1] is a duplication.
 * Ref[1]:https://www.jiuzhang.com/problem/find-all-duplicates-in-an-array/#tag-lang-cpp
 * 
 * Running Time: 151ms
 */
class Solution
{
public:
	/**
     * @param nums: a list of integers
     * @return: return a list of integers
     */
	vector<int> findDuplicates(vector<int> &nums)
	{
		vector<int> result;
		for (vector<int>::size_type i = 0; i != nums.size(); i++)
		{
			vector<int>::size_type index = abs(nums[i]) - 1;
			if (nums[index] < 0)
			{
				result.emplace_back(index + 1); //C++ 11
			}
			nums[index] = -nums[index];
		}
		return result;
	}
};