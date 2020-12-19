/** 
 * 52. Next Permutation
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given a list of integers, which denote a permutation.
 * Find the next permutation in ascending order.
 * 
 * Clarification
 * The list may contains duplicate integers.
 * 
 * Example
 * Example 1
 * Input:[1]
 * Output:[1]
 * 
 * Example 2
 * Input:[1,3,2,3]
 * Output:[1,3,3,2]
 * 
 * Example 3:
 * Input:[4,3,2,1]
 * Output:[1,2,3,4]
 * 
 * Related Problems
 * 917. Palindrome Permutation II
 * 388. Permutation Sequence
 * 190. Next Permutation II
 * 51. Previous Permutation
 * 16. Permutations II
 * 15. Permutations
 * */

/** 
 * Ref: https://www.jiuzhang.com/problem/next-permutation/#tag-lang-cpp
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums;
        }

        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }
        int j = nums.size() - 1;
        if (i >= 0)
        {
            while (nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
        return nums;
    }
};