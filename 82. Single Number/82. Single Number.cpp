/** 
 * 82. Single Number
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given 2 * n + 1 numbers, every numbers occurs twice except one, find it.
 * 
 * Clarification
 * n <= 100
 * 
 * Example
 * Example 1
 * Input：[1,1,2,2,3,4,4]
 * Output：3
 * Explanation:
 * Only 3 appears once
 * 
 * Example 2
 * Input：[0,0,1]
 * Output：1
 * Explanation:
 * Only 1 appears once
 * 
 * Challenge
 * One-pass, constant extra space.
 *
 * Related Problems
 * 824. Single Number IV
 * 633. Find the Duplicate Number
 * 84. Single Number III
 * 83. Single Number II
 * 48. Majority Number III
 * 47. Majority Element II
 * 46. Majority Element
 * */

/** 
 * Challenge
 * One-pass, constant extra space.
 * 
 * XOR operation
 *  
 * Running Time:  50ms
 */

class Solution
{
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A)
    {
        if (A.empty())
            return -1;

        int res;
        for (vector<int>::size_type i = 0; i != A.size(); i++)
        {
            res ^= A[i];
        }
        return res;
    }
};