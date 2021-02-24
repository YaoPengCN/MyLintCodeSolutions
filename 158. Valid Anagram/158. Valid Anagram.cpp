/** 
 * 158. Valid Anagram
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Write a method anagram(s,t) to decide if two strings are anagrams or not.
 * 
 * Clarification
 * What is Anagram?
 * Two strings are anagram if they can be the same after change the order of characters.
 * 
 * Example
 * Example 1
 * Input: s = "ab", t = "ab"
 * Output: true
 * 
 * Example 2:
 * Input: s = "abcd", t = "dcba"
 * Output: true
 * 
 * Example 3:
 * Input:  s = "ac", t = "ab"
 * Output: false	
 * 
 * Challenge
 * O(n) time, O(1) extra space
 * 
 * Related Problems
 * 772. Group Anagrams
 * 647. Find All Anagrams in a String
 * 503. Anagram (Map Reduce)
 * 216. Substring Rotation
 * 211. String Permutation
 * 171. Anagrams
 * 55. Compare Strings
 */

/**
 * Challenge
 * O(n) time, O(1) extra space
 * 
 * Running Time: 82ms
 */

class Solution
{
public:
    /**
     * @param s: The first string
     * @param t: The second string
     * @return: true or false
     */
    bool anagram(string &s, string &t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        vector<int> ch_s(256, 0);
        vector<int> ch_t(256, 0);

        for (vector<int>::size_type i = 0; i != s.length(); i++)
        {
            ch_s[s[i]]++;
            ch_t[t[i]]++;
        }

        for (vector<int>::size_type i = 0; i != ch_s.size(); i++)
        {
            if (ch_s[i] != ch_t[i])
            {
                return false;
            }
        }

        return true;
    }
};
