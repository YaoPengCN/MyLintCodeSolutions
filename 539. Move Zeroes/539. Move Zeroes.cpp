/** 
 * 539. Move Zeroes
 * Difficulty
 * Easy
 * 
 * Description
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *  
 * Clarification
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 * Example
 * Example 1:
 * Input: nums = [0, 1, 0, 3, 12],
 * Output: [1, 3, 12, 0, 0].
 * 
 * Example 2:
 * Input: nums = [0, 0, 0, 3, 1],
 * Output: [3, 1, 0, 0, 0].
 * 
 * Related Problems 
 * 172. Remove Element
 * */

/**
 * Two pointers
 * Ref[1]: https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ
 * Ref[2]: https://www.jiuzhang.com/problem/move-zeroes/#tag-lang-cpp
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums)
    {
        vector<int>::size_type left = 0, right = 0;
        while (right != nums.size())
        {
            if (nums[right] != 0)
            {
                nums[left] = nums[right];
                left++;
            }
            right++;
        }
        while (left != nums.size())
        {
            nums[left] = 0;
            left++;
        }
    }
};