/** 
* 55. Compare Strings
* Difficulty
* Easy
* 
* Description
* Compare two strings A and B, determine whether A contains all of the characters in B.
* The characters in string A and B are all Upper Case letters.
*
* Clarification
* The characters of B in A are not necessary continuous or ordered.
* 
* 
* Example
* Example 1
* For A = "ABCD", B = "ACD", return true.
* 
* Example 2
* For A = "ABCD", B = "AABC", return false.
*
* Related Problems 
* 158. Valid Anagram
*/

/**
 * Run Time:  101ms
 */
class Solution
{
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: if string A contains all of the characters in B return true else return false
     */
    bool compareStrings(string &A, string &B)
    {
        if (A.length() < B.length())
            return false;
        int count[26];
        for (int i = 0; i < 26; i++)
        {
            count[i] = 0;
        }
        for (int i = 0; i < A.length(); i++)
        {
            count[A[i] - 'A']++;
        }
        for (int i = 0; i < B.length(); i++)
        {
            count[B[i] - 'A']--;
            if (count[B[i] - 'A'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};