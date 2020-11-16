/** 
 * 569. Add Digits

 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * 
 * Example
 * Example 1
 * Input:
 * num=38
 * Output:
 * 2
 * Explanation:
 * The process is like: 3 + 8 = 11, 1 + 1 = 2. 
 * Since 2 has only one digit, return 2.
 * 
 * Example 2
 * Input:
 * num=9
 * Output:
 * 9
 * Explanation:
 * 9<10,return 9.
 * 
 * Challenge
 * Could you do it without any loop/recursion in O(1) runtime?
 * 
 * Related Problems
 * 488. Happy Number
 * */

/**
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param num: a non-negative integer
     * @return: one digit
     */
    int addDigits(int num)
    {
        if (num < 10)
            return num;

        while (num >= 10)
        {
            int cur = 0;
            while (num > 0)
            {
                int digit = num % 10;
                cur += digit;
                num /= 10;
            }
            num = cur;
            if (num < 10)
                break;
        }
        return num;
    }
};