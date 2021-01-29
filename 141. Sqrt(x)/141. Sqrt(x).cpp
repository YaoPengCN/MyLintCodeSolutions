/** 
 * 141. Sqrt(x)
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 * Return the largest integer y that y*y <= x.
 * 
 * Clarification
 * You may assume that the input character is between 'a' and 'z'.
 * 
 * Example
 * Example 1
 * Input: 0
 * Output: 0
 * 
 * Example 2:
 * Input: 3
 * Output: 1
 * Explanation:
 * Return the largest integer y that y*y <= x. 
 * 
 * Example 3:
 * Input: 4
 * Output: 2
 * 
 * Challenge 
 * O(log(x))
 *  
 * Related Problems
 * 1791. Simple Queries
 * 1728. X of a Kind in a Deck of Cards
 * 777. Valid Perfect Square
 * 586. Sqrt(x) II
 * 428. Pow(x, n)
 * 14. First Position of Target
 */

/**
 * Challenge 
 * O(log(x))
 * 
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x)
    {
        if (x < 0)
            return -1;

        long long left = 0, right = x;
        long long mid = left + (right - left) / 2;
        while (mid > left)
        {
            if (mid * mid > x)
            {
                right = mid;
            }
            else if (mid * mid < x)
            {
                left = mid;
            }
            else
            {
                return mid;
            }
            mid = left + (right - left) / 2;
        }
        return (right * right <= x) ? right : mid;
    }
};