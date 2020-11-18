/** 
 * 42. Maximum Subarray II
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given an array of integers, find two non-overlapping subarrays which have the largest sum.
 * The number in each subarray should be contiguous.
 * Return the largest sum.
 * 
 * Clarification
 * The subarray should contain at least one number
 * 
 * Example
 * Example 1
 * Input:
 * [1, 3, -1, 2, -1, 2]
 * Output:
 * 7
 * Explanation:
 * the two subarrays are [1, 3] and [2, -1, 2] or [1, 3, -1, 2] and [2].
 * 
 * Example 2
 * Input:
 * [5,4]
 * Output:
 * 9
 * Explanation:
 * the two subarrays are [5] and [4].
 *
 * Challenge
 * Can you do it in time complexity O(n)?
 *
 * Related Problems 
 * 1779. Shortest Duplicate Subarray
 * 944. Maximum Submatrix
 * 621. Maximum Subarray V
 * 620. Maximum Subarray IV
 * 617. Maximum Average Subarray II
 * 402. Continuous Subarray Sum
 * 151. Best Time to Buy and Sell Stock III
 * 43. Maximum Subarray III
 * */

/**
 * Prefix
 * Challenge: Can you do it in time complexity O(n)?
 * Running Time:  871ms
 */
class Solution
{
public:
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> &nums)
    {
        vector<int>::size_type n = nums.size();
        if (n < 1)
            return 0;
        if (n == 1)
            return nums[n - 1];

        vector<int> leftMax = nums;
        vector<int> rightMax = nums;

        for (vector<int>::size_type i = 1; i != n; i++)
        {
            leftMax[i] = max(nums[i], leftMax[i - 1] + nums[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(nums[i], rightMax[i + 1] + nums[i]);
        }

        vector<int> prefixMax = leftMax;
        vector<int> postfixMax = rightMax;

        for (vector<int>::size_type i = 1; i != n; i++)
        {
            prefixMax[i] = max(prefixMax[i - 1], prefixMax[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            postfixMax[i] = max(postfixMax[i], postfixMax[i + 1]);
        }

        int result = INT_MIN;
        for (vector<int>::size_type i = 0; i != n - 1; i++)
        {
            result = max(result, prefixMax[i] + postfixMax[i + 1]);
        }
        return result;
    }
};
