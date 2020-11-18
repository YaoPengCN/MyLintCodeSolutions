/** 
 * 43. Maximum Subarray III
 * 
 * Difficulty
 * Hard
 * 
 * Description
 * Given an array of integers and a number k, find k non-overlapping subarrays which have the largest sum.
 * The number in each subarray should be contiguous.
 * Return the largest sum.
 * 
 * Clarification
 * The subarray should contain at least one number
 * 
 * Example
 * Example 1
 * Input:
 * List = [1,2,3]
 * k = 1
 * Output:
 * 6
 * Explanation:
 * 1 + 2 + 3 = 6
 * 
 * Example 2
 * Input:
 * List = [-1,4,-2,3,-2,3]
 * k = 2
 * Output:
 * 8
 * Explanation:
 * 4 + (3 + -2 + 3) = 8
 *
 * Related Problems 
 * 1779. Shortest Duplicate Subarray
 * 944. Maximum Submatrix
 * 621. Maximum Subarray V
 * 620. Maximum Subarray IV
 * 617. Maximum Average Subarray II
 * 402. Continuous Subarray Sum
 * 151. Best Time to Buy and Sell Stock III
 * 42. Maximum Subarray II
 * 41. Maximum Subarray
 * */

/**
 * Dynamic programming
 * Time complexity: O(nk), space complexity: O(k)
 * Ref: https://www.jiuzhang.com/problem/maximum-subarray-iii/#tag-lang-cpp
 * Running Time:  50ms
 */
class Solution
{
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> &nums, int k)
    {
        if (k > nums.size())
            return 0;

        vector<int>::size_type n = nums.size();
        // local[i][j]: the maximum sum of j subarrays using nums[i].
        // global[i][j]: the maximum sum of j subarrays whether using nums[i].
        // global[nums.size()][k] is the result.
        vector<int> local(n + 1, 0), global(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = min(i, k); j > 0; j--)
            {
                if (i == j)
                {
                    local[j] = local[j - 1] + nums[i - 1];
                    global[j] = global[j - 1] + nums[i - 1];
                }
                else
                {
                    local[j] = max(local[j], global[j - 1]) + nums[i - 1];
                    global[j] = max(global[j], local[j]);
                }
            }
        }
        return global[k];
    }
};