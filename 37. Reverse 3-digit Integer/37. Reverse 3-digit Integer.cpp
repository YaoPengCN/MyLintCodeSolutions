/** 
* 37. Reverse 3-digit Integer
* Difficulty
* Easy
* 
* Description
* Reverse a 3-digit integer.
* 
* Example
* Example 1
* Input: number = 123
* Output: 321
* 
* Example 2
* Input: number = 900
* Output: 9
*
* Related Problems 
* 767. Reverse Array
* 413. Reverse Integer
*/

/**
 * Running Time:  50ms
 */
class Solution {
public:
    /**
     * @param number: A 3-digit number.
     * @return: Reversed number.
     */
    int reverseInteger(int number) {
        vector<int> digit(3);
        int reversed = 0;
        for (int i = 0; i < 3; i++)
        {
            digit[i] = number % 10;
            number /= 10;
        }
        for (int i = 0; i < 3; i++)
        {
            reversed *= 10;
            reversed += digit[i];            
        }
        return reversed;
    }
};