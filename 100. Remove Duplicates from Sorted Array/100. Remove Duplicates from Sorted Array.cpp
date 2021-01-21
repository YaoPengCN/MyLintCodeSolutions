/** 
 * 100. Remove Duplicates from Sorted Array
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a sorted array, 'remove' the duplicates in place such that each element appear only once and return the 'new' length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * 
 * Example
 * Example 1
 * Input:  []
 * Output: 0
 * 
 * Example 2:
 * Input:  [1,1,2]
 * Output: 2
 * Explanation:  uniqued array: [1,2]
 *  
 * Related Problems
 * 172. Remove Element
 * 101. Remove Duplicates from Sorted Array II
 */

/**
 * Running Time: 864ms
 */

class Solution
{
public:
    /*
     * @param nums: An integer array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int res = 0;
        for (vector<int>::size_type i = 0; i != nums.size(); i++)
        {
            if (nums[i] != nums[res])
            {
                nums[++res] = nums[i];
            }
        }
        return res + 1;
    }
};