/** 
 * 142. O(1) Check Power of 2
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Using O(1) time to check whether an integer n is a power of 2.
 * 
 * Clarification
 * O(1)
 * 
 * Example
 * Example 1
 * Input: 4
 * Output: true
 * 
 * Example 2:
 * Input: 5
 * Output: false
 *  
 * Related Problems
 * 365. Count 1 in Binary
 */

/**
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n)
    {
        if (n <= 0)
            return false;

        return (n & (n - 1)) == 0;
    }
};