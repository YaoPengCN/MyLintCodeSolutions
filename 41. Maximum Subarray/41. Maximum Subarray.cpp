/** 
* 41. Maximum Subarray
* Difficulty
* Easy
* 
* Description
* Given an array of integers, find a contiguous subarray which has the largest sum.
* 
* Example
* Example 1
* Input: [−2,2,−3,4,−1,2,1,−5,3]
* Output: 6
* Explanation: the contiguous subarray [4,−1,2,1] has the largest sum = 6.
* 
* Example 2
* Input: [1,2,3,4]
* Output: 10
* Explanation: the contiguous subarray [1,2,3,4] has the largest sum = 10.
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
*/

/**
 * Challenge: Can you do it in time complexity O(n)?
 * Run Time:  50ms
 */
class Solution
{
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums)
    {
        //greedy algorithm
        if (nums.empty())
            return 0;

        int cur = nums[0], sum = nums[0];
        for (vector<int>::size_type i = 1; i != nums.size(); i++)
        {
            cur = max(nums[i], cur + nums[i]);
            sum = max(cur, sum);
        }
        return sum;

        /* //prefix sum in array
         * //ref[1]: https://geekstocode.com/prefix-sum-in-array/
         * //ref[2]: https://www.jiuzhang.com/problem/maximum-subarray/#tag-lang-cpp
         * //Run Time: 50ms
         * //Time complexity O(n+k)
         * if (nums.size() < 0)
         *    return 0;
         * int prefix_sum = nums[0];
         * int min_sum = nums[0];
         * int result = INT_MIN;
         * for (auto n : nums) 
         * {
         *     prefix_sum += n;
         *     result = max(result, prefix_sum - min_sum);
         *     min_sum = min(prefix_sum, min_sum);
         * }
         * return result;
         */
    }
};
