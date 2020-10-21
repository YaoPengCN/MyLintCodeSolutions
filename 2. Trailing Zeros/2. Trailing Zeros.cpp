/** 
* 2. Trailing Zeros
* Difficulty
* Easy
* 
* Description
* Write an algorithm which computes the number of trailing zeros in n factorial.
*
* Example
* 11! = 39916800, so the out should be 2
* 
* Challenge
* O(log N) time

* Related Problems 
* 1312. Number of Digit One
*/

/**
 * Challenge: O(log N) time
 * Running Time: 27ms
 */
class Solution {
public:
	/*
	 * @param n: A long integer
	 * @return: An integer, denote the number of trailing zeros in n!
	 */
	long long trailingZeros(long long n) {
		// write your code here, try to do it without arithmetic operators.
		// 2 * 5 = 10, each pair (2,5) creates one trailing zero.
		// From 2, 3, 4 = 2 * 2, 5,... , there are more 2s than 5s
		// Therefore the number of 5s decides the number of trailing zeros.
		long long sum = 0;
		while (n != 0) {
			sum += n / 5;
			n /= 5;
		}
		return sum;
	}
};

