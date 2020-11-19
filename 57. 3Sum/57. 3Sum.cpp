/** 
 * 57. 3Sum
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Clarification
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * 
 * Example
 * Example 1
 * Input:[2,7,11,15]
 * Output:[]
 * 
 * Example 2
 * Input:[-1,0,1,2,-1,-4]
 * Output:	[[-1, 0, 1],[-1, -1, 2]]
 *
 * Related Problems
 * 918. 3Sum Smaller
 * 382. Triangle Count
 * 59. 3Sum Closest
 * 58. 4Sum
 * 56. Two Sum
 * */

/**
 * Ref[1]: https://mp.weixin.qq.com/s/fSyJVvggxHq28a0SdmZm6Q
 * 
 * Running Time:  16ms
 */
class Solution
{
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers)
    {
        sort(numbers.begin(), numbers.end());
        return nSumTarget(numbers, 3, 0, 0);
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
                    sort(arr.begin(),arr.end());
                    res.push_back(arr);
                }
                while (i < sz - 1 && nums[i] == nums[i + 1])
                    i++;
            }
        }
        return res;
    }
};
