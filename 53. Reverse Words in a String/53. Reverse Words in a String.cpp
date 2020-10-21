/** 
* 53. Reverse Words in a String
* Difficulty
* Easy
* 
* Description
* Given an input string, reverse the string word by word.
* 
* Clarification
* · What constitutes a word?
* A sequence of non-space characters constitutes a word and some words have punctuation at the end.
* · Could the input string contain leading or trailing spaces?
* Yes. However, your reversed string should not contain leading or trailing spaces.
* · How about multiple spaces between two words?
* Reduce them to a single space in the reversed string.
* 
* Example
* Example 1
* Input: "the sky is blue"
* Output:  "blue is sky the"
* Explanation: return a reverse the string word by word.
* 
* Example 2
* Input: "hello world"
* Output: "world hello"
* Explanation: return a reverse the string word by word.
*
* Related Problems 
* 1282. Reverse Vowels of a String
* 927. Reverse Words in a String II
* 767. Reverse Array
* 36. Reverse Linked List II
* 35. Reverse Linked List
*/

/**
 * Running Time:  299ms
 */
class Solution
{
public:
    /*
     * @param s: A string
     * @return: A string
     */
    string reverseWords(string &s)
    {
        string ss;
        int i = s.length() - 1;
        while (i >= 0)
        {
            while (i >= 0 && s[i] == ' ')
            {
                i--;
            }
            if (i < 0)
                break;
            if (ss.length() != 0)
                ss.push_back(' ');
            string temp;
            for (; i >= 0 && s[i] != ' '; i--)
                temp.push_back(s[i]);
            reverse(temp.begin(), temp.end());
            ss.append(temp);
        }
        return ss;
    }
};