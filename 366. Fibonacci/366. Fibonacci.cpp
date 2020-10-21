/** 
* 366. Fibonacci
* Difficulty
* Easy
* 
* Description
* Find the Nth number in Fibonacci sequence.
* A Fibonacci sequence is defined as follow:
* · The first two numbers are 0 and 1.
* · The i th number is the sum of i-1 th number and i-2 th number.
* The first ten numbers in Fibonacci sequence is:
* 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...
*
* Clarification
* The Nth fibonacci number won't exceed the max value of signed 32-bit integer in the test cases.
*
* Example
* Example 1
* Input: 1
* Output: 0
* Explanation: return the first number in  Fibonacci sequence.
* 
* Example 2:
* Input: 2
* Output: 1
* Explanation: return the first number in  Fibonacci sequence.
* 
* Related Problems 
* 735. Replace With Greatest From Right
* 734. Number of Subsequences of Form a^i b^j c^k
* 392. House Robber
* 111. Climbing Stairs
*/

/**
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param n: an integer
     * @return: an integer f(n)
     */
    int fibonacci(int n)
    {
        if (n == 1)
            return 0;
        if (n == 2)
            return 1;

        int a, b, result;
        a = 0;
        b = 1;
        result = 0;

        for (int i = 3; i <= n; i++)
        {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
};