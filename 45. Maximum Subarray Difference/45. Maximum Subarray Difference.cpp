/** 
 * 45. Maximum Subarray Difference
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given an array with integers.
 * Find two non-overlapping subarrays A and B, which |SUM(A) - SUM(B)| is the largest.
 * Return the largest difference.
 * 
 * Clarification
 * The subarray should contain at least one number
 * 
 * Example
 * Example 1
 * Input:
 * [1, 2, -3, 1]
 * Output:
 * 6
 * Explanation:
 * The subarray are [1,2] and [-3].So the answer is 6.
 * 
 * Example 2
 * Input:
 * [0,-1]
 * Output:
 * 1
 * Explanation:
 * The subarray are [0] and [-1].So the answer is 1.
 * 
 * Challenge
 * O(n) time and O(n) space.
 *
 * Related Problems 
 * 1779. Shortest Duplicate Subarray
 * 944. Maximum Submatrix
 * 621. Maximum Subarray V
 * 620. Maximum Subarray IV
 * 617. Maximum Average Subarray II
 * 402. Continuous Subarray Sum
 * 191. Maximum Product Subarray
 * 151. Best Time to Buy and Sell Stock III
 * 43. Maximum Subarray III
 * 42. Maximum Subarray II
 * 41. Maximum Subarray
 * */

/**
 * Challenge
 * O(n) time and O(n) space.
 * Ref: https://www.jiuzhang.com/problem/maximum-subarray-difference/#tag-lang-cpp
 * Running Time:  50ms
 */
class Solution
{
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two substrings
     */
    int maxDiffSubArrays(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return 0;
        }

        vector<int> leftMax(n), leftMin(n);
        vector<int> rightMax(n), rightMin(n);
        int curMax, curMin;

        curMax = nums[0];
        curMin = nums[0];
        leftMax[0] = nums[0];
        leftMin[0] = nums[0];
        for (int i = 1; i != n; i++)
        {
            curMax = max(nums[i], curMax + nums[i]);
            leftMax[i] = max(leftMax[i - 1], curMax);

            curMin = min(nums[i], curMin + nums[i]);
            leftMin[i] = min(leftMin[i - 1], curMin);
        }

        curMax = nums[n - 1];
        curMin = nums[n - 1];
        rightMax[n - 1] = nums[n - 1];
        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            curMax = max(nums[i], curMax + nums[i]);
            rightMax[i] = max(rightMax[i + 1], curMax);

            curMin = min(nums[i], curMin + nums[i]);
            rightMin[i] = min(rightMin[i + 1], curMin);
        }

        int result = INT_MIN;
        for (int i = 0; i != n - 1; i++)
        {
            result = max(result, max(abs(leftMax[i] - rightMin[i + 1]), abs(leftMin[i] - rightMax[i + 1])));
        }
        return result;
    }
};