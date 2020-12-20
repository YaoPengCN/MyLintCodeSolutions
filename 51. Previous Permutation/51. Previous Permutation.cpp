/** 
 * 51. Previous Permutation
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given a list of integers, which denote a permutation.
 * Find the previous permutation in ascending order.
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
 * Output:[1,2,3,3]
 * 
 * Example 3:
 * Input:[1,2,3,4]
 * Output:[4,3,2,1]
 * 
 * Related Problems
 * 388. Permutation Sequence
 * 197. Permutation Index
 * 52. Next Permutation
 * */

/** 
 * Ref: https://www.jiuzhang.com/problem/previous-permutation/#tag-lang-cpp
 * Running Time: 681ms
 */

class Solution
{
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers that's previous permutation
     */
    vector<int> previousPermuation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] <= nums[i + 1])
        {
            i--;
        }
        if (i < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            int j = i + 2;
            while (j < nums.size() && nums[j] < nums[i])
            {
                j++;
            }
            j--;

            // nums[i] ^= nums[j];
            // nums[j] ^= nums[i];
            // nums[i] ^= nums[j];
            swap(nums[i],nums[j]);

            reverse(nums.begin() + i + 1, nums.end());
        }
        return nums;
    }
};