/** 
 * 145. Lowercase to Uppercase
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Convert a lowercase character to uppercase.
 * 
 * Clarification
 * You may assume that the input character is between 'a' and 'z'.
 * 
 * Example
 * Example 1
 * Input: 'a'
 * Output: 'A'
 * 
 * Example 2:
 * Input: 'b'
 * Output: 'B'
 *  
 * Related Problems
 * 146. Lowercase to Uppercase II
 */

/**
 * Running Time: 101ms
 */

class Solution
{
public:
    /**
     * @param character: a character
     * @return: a character
     */
    char lowercaseToUppercase(char character)
    {
        return character - 'a' + 'A';
    }
};