/** 
 * 84. Single Number III
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given 2*n + 2 numbers, every numbers occurs twice except two, find them.
 * 
 * Example
 * Example 1
 * Input:  [1,2,2,3,4,4,5,3]
 * Output:  [1,5]
 * Explanation:
 * Only 1 and 5 appear once
 * 
 * Example 2
 * Input: [1,1,2,3,4,4]
 * Output:  [2,3]
 * Explanation:
 * Only 2 and 3 appear once
 * 
 * Challenge
 * O(n) time, O(1) extra space.
 *
 * Related Problems
 * 824. Single Number IV
 * 633. Find the Duplicate Number
 * 83. Single Number II
 * 82. Single Number
 * 48. Majority Number III
 * 47. Majority Element II
 * 46. Majority Element
 * */

/** 
 * Challenge
 * O(n) time, O(1) extra space.
 * 
 * use XOR operation
 * 
 * Ref[1]: https://www.lintcode.com/problem/single-number-iii/discuss
 * Ref[2]: https://www.jiuzhang.com/problem/single-number-iii/
 * 
 * Running Time:  3452ms
 */

class Solution
{
public:
    /**
     * @param A: An integer array
     * @return: An integer array
     */
    vector<int> singleNumberIII(vector<int> &A)
    {
        if (A.empty())
            return {};

        int diff = 0;
        for (int num : A)
        {
            diff ^= num;
        }
        // now, diff = num1 ^ num2

        // get a 1 in diff = num1 ^ num2
        // here, diff &= -diff accesses the rightest 1 in num1 ^ num2       
        diff &= -diff;

        int num1 = 0, num2 = 0;
        for (int num : A)
        {
            if ((num & diff) == 0)
            {
                num1 ^= num;
            }
            else
            {
                num2 ^= num;
            }
        }
        return {num1, num2};
    }
};
