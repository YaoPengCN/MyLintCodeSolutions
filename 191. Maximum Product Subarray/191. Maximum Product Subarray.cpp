/** 
 * 191. Maximum Product Subarray
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 * 
 * Clarification
 * It is guaranteed that the length of nums doesn't exceed 20000
 * The product of the largest subsequence of the product, less than 2147483647
 * 
 * Example
 * Example 1
 * Input:
 * [2,3,-2,4]
 * Output:
 * 6
 * 
 * Example 2
 * Input:
 * [-1,2,4,1]
 * Output:
 * 8
 * 
 * Related Problems 
 * 1779. Shortest Duplicate Subarray
 * 944. Maximum Submatrix
 * 621. Maximum Subarray V
 * 620. Maximum Subarray IV
 * 617. Maximum Average Subarray II
 * 402. Continuous Subarray Sum
 * 151. Best Time to Buy and Sell Stock III
 * 45. Maximum Subarray Difference
 * 43. Maximum Subarray III
 * 42. Maximum Subarray II
 * 41. Maximum Subarray
 * */

/**
 * Ref: https://www.jiuzhang.com/problem/maximum-product-subarray/#tag-lang-cpp
 * Running Time:  50ms
 */
class Solution
{
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() <= 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];

        vector<int> curMax(nums.size());
        vector<int> curMin(nums.size());
        int result = nums[0];
        curMax[0] = nums[0];
        curMin[0] = nums[0];
        for (vector<int>::size_type i = 1; i != nums.size(); i++)
        {
            curMax[i] = max(max(curMin[i - 1] * nums[i], curMax[i - 1] * nums[i]), nums[i]);
            curMin[i] = min(min(curMin[i - 1] * nums[i], curMax[i - 1] * nums[i]), nums[i]);
            result = max(result, curMax[i]);
        }
        return result;
    }
};