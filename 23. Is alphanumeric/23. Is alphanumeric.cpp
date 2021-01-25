/** 
 * 23. Is alphanumeric
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a character c, if it is a letter or a number, return ‘true’.
 * 
 * Clarification
 * If you use Python, the input will be a string which has a length of 1.
 * 
 * Example
 * Input：'1'
 * Output：true
 * */

/**
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param c: A character.
     * @return: The character is alphanumeric or not.
     */
    bool isAlphanumeric(char c)
    {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            return true;
        return false;
    }
};