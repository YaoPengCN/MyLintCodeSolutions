/** 
 * 58. 4Sum
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 *
 * Clarification
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example
 * Example 1
 * Input:
 * [2,7,11,15],3
 * Output:
 * []
 * 
 * Example 2
 * Input: 
 * [1,0,-1,0,-2,2],0
 * Output:	
 * [[-1, 0, 0, 1],
 *  [-2, -1, 1, 2],
 *  [-2, 0, 0, 2]]
 *
 * Related Problems
 * 57. 3Sum
 * 56. Two Sum
 * */

/**
 * Ref[1]: https://mp.weixin.qq.com/s/fSyJVvggxHq28a0SdmZm6Q
 * Running Time:  390ms
 */
class Solution
{
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> fourSum(vector<int> &numbers, int target)
    {
        sort(numbers.begin(), numbers.end());
        return nSumTarget(numbers, 4, 0, target);
    }

private:
    vector<vector<int>> nSumTarget(vector<int> &nums, int n, int start, int target)
    {
        int sz = nums.size();
        vector<vector<int>> res;

        if (n < 2 || sz < n)
            return res;

        // 2Sum
        if (n == 2)
        {
            // double pointers
            int lo = start, hi = sz - 1;
            while (lo < hi)
            {
                int sum = nums[lo] + nums[hi];
                int left = nums[lo], right = nums[hi];
                if (sum < target)
                {
                    while (lo < hi && nums[lo] == left)
                        lo++;
                }
                else if (sum > target)
                {
                    while (lo < hi && nums[hi] == right)
                        hi--;
                }
                else
                {
                    res.push_back({left, right});
                    while (lo < hi && nums[lo] == left)
                        lo++;
                    while (lo < hi && nums[hi] == right)
                        hi--;
                }
            }
        }
        else
        {
            // n > 2, nSum
            for (int i = start; i < sz; i++)
            {
                vector<vector<int>> sub = nSumTarget(nums, n - 1, i + 1, target - nums[i]);
                for (vector<int> &arr : sub)
                {
                    // the result of nSum is the result of (n-1)Sum with nums[i]
                    arr.push_back(nums[i]);
                    sort(arr.begin(), arr.end());
                    res.push_back(arr);
                }
                while (i < sz - 1 && nums[i] == nums[i + 1])
                    i++;
            }
        }
        return res;
    }
};
