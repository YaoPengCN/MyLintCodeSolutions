/** 
* 44. Minimum Subarray
* Difficulty
* Easy
* 
* Description
* Given an array of integers, find the continuous subarray with smallest sum.
* Return the sum of the subarray.
* 
* Example
* Example 1
* Input: [1, -1, -2, 1]
* Output: -3
* 
* Example 2
* Input: [1, -1, -2, 1, -4]
* Output: -6
*
* Related Problems 
* 1779. Shortest Duplicate Subarray
* 191. Maximum Product Subway
*/

/**
 * Running Time:  582ms
 */
class Solution
{
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the sum of max subarray
     */
    int minSubArray(vector<int> &nums)
    {
        //greedy algorithm
        if (nums.empty())
            return NULL;

        int cur = nums[0], sum = nums[0];
        for (vector<int>::size_type i = 1; i != nums.size(); i++)
        {
            cur = min(nums[i], cur + nums[i]);
            sum = min(cur, sum);
        }
        return sum;

        /* //prefix sum in array
         * //ref[1]: https://geekstocode.com/prefix-sum-in-array/
         * //ref[2]: https://www.jiuzhang.com/problem/maximum-subarray/#tag-lang-cpp
         * //Running Time: 776ms
         * //Time complexity O(n+k)
         * if (nums.empty())
         *    return NULL;
         * int prefix_sum = nums[0];
         * int max_sum = nums[0];
         * int result = INT_MAX;
         * for (auto n : nums) 
         * {
         *     prefix_sum += n;
         *     result = min(result, prefix_sum - max_sum);
         *     max_sum = max(prefix_sum, max_sum);
         * }
         * return result;
         */
    }
};