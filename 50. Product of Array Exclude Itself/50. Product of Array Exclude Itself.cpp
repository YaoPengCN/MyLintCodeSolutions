/** 
* 50. Product of Array Exclude Itself
* Difficulty
* Easy
* 
* Description
* Given an integers array A.
* Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B WITHOUT divide operation. Output B.
* 
* Example
* Example 1
* Input: A = [1, 2, 3]
* Output: [6, 3, 2]
* Explanation: B[0] = A[1] * A[2] = 6; B[1] = A[0] * A[2] = 3; B[2] = A[0] * A[1] = 2
* 
* Example 2
* Input: A = [2, 4, 6]
* Output: [24, 12, 8]
*
* Example 3
* Input: A = [0]
* Output: [1]
*
* Related Problems 
* 1119. Maximum Product of Three Numbers
* 516. Paint House II
*/

/**
 * Run Time:  405ms
 */
class Solution
{
public:
    /*
     * @param nums: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums)
    {
        // write your code here
        int n = nums.size();
        long long left = 1, right = 1; //left：从左边累乘，right：从右边累乘
        vector<long long> res(n, 1);

        for (int i = 0; i < n; ++i) //最终每个元素其左右乘积进行相乘得出结果
        {
            res[i] *= left; //乘以其左边的乘积
            left *= nums[i];

            res[n - 1 - i] *= right; //乘以其右边的乘积
            right *= nums[n - 1 - i];
        }

        return res;
    }
};