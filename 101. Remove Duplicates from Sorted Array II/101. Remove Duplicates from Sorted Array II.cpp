/** 
 * 101. Remove Duplicates from Sorted Array II
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a sorted array, remove the duplicates in place such that each element appear at most twice and return the new length.
 * If a number appears more than two times, then keep the number appears twice in array after remove.
 * 
 * Clarification
 * Need to operate in the original array.
 * 
 * Example
 * Example 1
 * Input: []
 * Output: 0
 *  
 * Example 2:
 * Input:  [1,1,1,2,2,3]	
 * Output: 5
 * Explanation:
 * the length is 5: [1,1,2,2,3]
 *  
 * Related Problems
 * 172. Remove Element
 * 100. Remove Duplicates from Sorted Array
 */

/**
 * Running Time: 883ms
 */

class Solution
{
public:
    /**
     * @param nums: an integer array
     * @return : an integer
     */
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        vector<int>::size_type cnt = 0, res = 0;
        for (vector<int>::size_type i = 0; i != nums.size(); i++)
        {
            if (nums[i] == nums[res])
            {
                cnt++;
                if (cnt == 2)
                {
                    nums[++res] = nums[i];
                }
            }
            else
            {
                nums[++res] = nums[i];
                cnt = 1;
            }
        }

        return res + 1;
    }
};
