/** 
 * 1169. Permutation in String
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
 * In other words, one of the first string's permutations is the substring of the second string.
 *
 * Clarification
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 * 
 * Example
 * Example 1
 * Input:
 * s1 = "ab" s2 = "eidbaooo"
 * Output:
 * true
 * Explanation: 
 * s2 contains one permutation of s1 ("ba").
 * 
 * Example 2
 * Input: 
 * s1= "ab" s2 = "eidboaoo"
 * Output:	
 * false
 * 
 * Related Problems
 * 1362. Substring with Concatenation of All Words
 * 1117. Smallest Range
 * 857. Minimum Window Subsequence
 * 647. Find All Anagrams in a String
 * 604. Window Sum
 * 32. Minimum Window Substring
 * */

/**
 * Sliding window
 * https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hua-dong-chuang-kou-ji-qiao-jin-jie
 * 
 * Define the window [left, right).
 * Step 1. Enlarge the window until the window contains all the characters of the target.
 * Step 2. Shrink the window until the window no longer contains all the characters of the target.
 * Step 3. Repeat Step 1. and Step 2. until "right" reaches the end of the source.
 * 
 * Running Time:  50ms
 */

class Solution
{
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    bool checkInclusion(string &s1, string &s2)
    {
        if (s1.size() == 0 || s2.size() == 0)
            return false;

        // "need" records the frequencies of the characters in the target
        unordered_map<char, int> need, window;
        for (char c : s1)
            need[c]++;

        // window [left, right)
        int left = 0, right = 0;

        // "valid" records the needed characters in "need"
        int valid = 0;

        // Step 3. Repeat Step 1. and Step 2.
        while (right < s2.size())
        {
            // Step 1. Enlarge the window
            char c = s2[right];
            right++;
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            // Step 2. Shrink the window
            while (right - left >= s1.size())
            {
                if (valid == need.size())
                    return true;

                // char "d" is to be deleted
                char d = s2[left];
                left++;
                if (need.count(d))
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};