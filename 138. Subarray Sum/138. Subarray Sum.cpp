/** 
 * 138. Subarray Sum
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given an integer array, find a subarray where the sum of numbers is zero. 
 * Your code should return the index of the first number and the index of the last number.
 * 
 * Clarification
 * There is at least one subarray that it's sum equals to zero.
 * 
 * Example
 * Example 1
 * Input: 
 * [-3, 1, 2, -3, 4]
 * Output: 
 * [0, 2] or [1, 3].
 * Explanation: 
 * Return anyone that the sum is 0.
 * 
 * Example 2:
 * Input: 
 * [-3, 1, -4, 2, -3, 4]
 * Output: 
 * [1,5]	
 * 
 * Related Problems
 * 406. Minimum Size Subarray Sum
 * 405. Submatrix Sum
 * 404. Subarray Sum II
 * 139. Subarray Sum Closest
 */

/**
 * PrefixSum
 * Ref: https://www.jiuzhang.com/problem/subarray-sum/
 * Running Time: 1491ms
 */

class Solution
{
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums)
    {
        vector<int> result;
        unordered_map<int, int> hash;

        // initialization
        hash[0] = -1;
        int sum = 0;

        for (int i = 0; i != nums.size(); i++)
        {

            // prefix sum
            sum += nums[i];

            // if the prefix sum already in hash, then the subarray sum is 0
            if (hash.find(sum) != hash.end())
            {
                result.push_back(hash[sum] + 1);
                result.push_back(i);
                break;
            }

            // store the first prefix sum into hash
            hash[sum] = i;
        }

        return result;
    }
};