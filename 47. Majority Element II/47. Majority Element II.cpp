/** 
 * 47. Majority Element II
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given an array of integers, the majority number is the number that occurs more than 1/3 of the size of the array.
 * Find it.
 * 
 * Clarification
 * There is only one majority number in the array.
 * 
 * Example
 * Example 1
 * Input: [99,2,99,2,99,3,3], 
 * Output: 99.
 * 
 * Example 2
 * Input: [1, 2, 1, 2, 1, 3, 3],
 * Output: 1.
 * 
 * Challenge
 * O(n) time and O(1) extra space
 *
 * Related Problems 
 * 84. Single Number III
 * 83. Single Number II
 * 82. Single Number
 * 48. Majority Number III
 * 46. Majority Element
 * */

/**
 * Challenge: O(n) time and O(1) extra space
 * 
 * Moore majority vote algorithm
 * Ref: https://www.jiuzhang.com/problem/majority-element-ii/
 * 
 * Running Time:  750ms
 */

class Solution
{
public:
    /*
     * @param nums: a list of integers
     * @return: The majority number that occurs more than 1/3
     */
    int majorityNumber(vector<int> &nums)
    {
        if (nums.empty())
            return -1;

        int n1 = 0, n2 = 1;
        int count1 = 0, count2 = 0;
        for (int x : nums)
        {
            if (x == n1)
            {
                ++count1;
            }
            else if (x == n2)
            {
                ++count2;
            }
            else if (count1 == 0)
            {
                n1 = x;
                ++count1;
            }
            else if (count2 == 0)
            {
                n2 = x;
                ++count2;
            }
            else
            {
                --count1;
                --count2;
            }
        }

        count1 = 0;
        count2 = 0;
        for (int x : nums)
        {
            if (x == n1)
                ++count1;
            if (x == n2)
                ++count2;
        }
        
        return count1 > count2 ? n1 : n2;
    }
};