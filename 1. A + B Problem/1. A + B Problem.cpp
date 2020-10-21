/** 
* 1. A + B Problem
* Difficulty
* Easy
* 
* Description
* Write a function that add two numbers A and B.
*
* Clarification
* Are a and b both 32-bit integers?
* Yes.
* 
* Can I use bit operation?
* Sure you can.
* 
* Example
* Given a=1 and b=2 return 3.
* 
* Challenge
* Of course you can just return a + b to get accepted. But Can you challenge not do it like that?(You should not use + or any arithmetic operators.)

* Related Problems 
* 766. Leap Year, 765. Valid Triangle, 658. Swap Without Extra Variable (Only C++)
*/

/**
 * Challenge: do not use + or any arithmetic operators.
 * Running Time: 6ms
 */
class Solution {
public:
	/**
	 * @param a: An integer
	 * @param b: An integer
	 * @return: The sum of a and b
	 */
	// using XOR ^, "a ^ b" means "a + b" bit by bit without carrying
	// "a & b << 1" records the carrying on each bit. 
	// Thus, a + b = (a ^ b) + (a & b << 1)
	int aplusb(int a, int b) {
		while (b != 0) {
			int _a = a ^ b;
			int _b = (a & b) << 1;
			a = _a;
			b = _b;
		}
		return a;
	}
};

///**
// * Running Time: 6ms
// */
///* class Solution {
//public:
//    /*
//     * @param a: An integer
//     * @param b: An integer
//     * @return: The sum of a and b 
//     */
//    int aplusb(int a, int b) {
//       return a+b;
//    }
//};

