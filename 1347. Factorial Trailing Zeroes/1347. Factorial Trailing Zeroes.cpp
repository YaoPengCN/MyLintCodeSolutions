/** 
* 1347. Factorial Trailing Zeroes
* Difficulty
* Easy
* 
* Description
* Given an integer n, return the number of trailing zeroes in n!.
* 
* Clarification
* Your solution should be in logarithmic time complexity.
*
* Example
* Example1
* Input: n = 5
* Output: 1
* Explanation:
* 1*2*3*4*5=120
* 
* Example2
* Input: n = 10
* Output: 2
* Explanation:
* 1*2*3*4*5*6*7*8*9*10=3628800
* 
* Related Problems 
* 1312. Number of Digit One
* 1023. Preimage Size of Factorial Zeroes Function
* 2. Trailing Zeros
*/

/**
 * Ref[1]: https://labuladong.gitbook.io/algo/gao-pin-mian-shi-xi-lie/jie-cheng-ti-mu
 * Running Time: 50ms
 */
class Solution
{
public:
	/**
     * @param n: a integer
     * @return: return a integer
     */
	int trailingZeroes(int n)
	{
		int res = 0;
		long divisor = 5;
		while (divisor <= n)
		{
			res += n / divisor;
			divisor *= 5;
		}
		return res;
	}
};