/** 
 * 488. Happy Number
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Write an algorithm to determine if a number is happy.
 * A happy number is a number defined by the following process: 
 * Starting with any positive integer, replace the number by the sum of the squares of its digits, 
 * and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. 
 * Those numbers for which this process ends in 1 are happy numbers.
 * 
 * Example
 * Example 1
 * Input:
 * 19
 * Output:
 * true
 * Explanation:
 * 19 is a happy number
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * Example 2
 * Input:
 * 5
 * Output:
 * false
 * Explanation:
 * 5 is not a happy number
 * 25->29->85->89->145->42->20->4->16->37->58->89
 * 89 appears again.
 * 
 * Related Problems
 * 742. Self Dividing Numbers
 * 569. Add Digits
 * 517. Ugly Number
 * 147. Narcissistic Number
 * 4. Ugly Number II
 * */

/**
 * Running Time: 51ms
 */

class Solution
{
public:
    /**
     * @param n: An integer
     * @return: true if this is a happy number or false
     */
    bool isHappy(int n)
    {
        if (n < 1)
            return false;
        if (n == 1)
            return true;

        set<int> seen;
        seen.insert(n);

        while (n > 1)
        {
            int cur = 0;
            while (n > 0)
            {
                int digit = n % 10;
                cur += digit * digit;
                n /= 10;
            }
            n = cur;
            if (seen.count(n) == 0)
                seen.insert(n);
            else 
                break;
        }
        return n == 1;
    }
};