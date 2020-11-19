/** 
 * 32. Minimum Window Substring
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given two strings source and target. 
 * Return the minimum substring of source which contains each char of target.
 *
 * Clarification
 * If there is no answer, return "".
 * You are guaranteed that the answer is unique.
 * Target may contain duplicate char, while the answer need to contain at least the same number of that char.
 * 
 * Example
 * Example 1
 * Input:
 * source = "abc", target = "ac"
 * Output:
 * "abc"
 * 
 * Example 2
 * Input: 
 * source = "adobecodebanc", target = "abc"
 * Output:	
 * "banc"
 * Explanation: 
 * "banc" is the minimum substring of source string which contains each char of target "abc".
 *
 * Example 3
 * Input:
 * source = "abc", target = "aa"
 * Output:
 * ""
 * Explanation: 
 * No substring contains two 'a'.
 * 
 * Challenge
 * O(n) time
 * 
 * Related Problems
 * 1362. Substring with Concatenation of All Words
 * 1169. Permutation in String
 * 1117. Smallest Range
 * 857. Minimum Window Subsequence
 * 604. Window Sum
 * */

/**
 * Challenge
 * O(n) time
 * 
 * Sliding window
 * https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hua-dong-chuang-kou-ji-qiao-jin-jie
 * 
 * Define the window [left, right).
 * Step 1. Enlarge the window until the window contains all the characters of the target.
 * Step 2. Shrink the window until the window no longer contains all the characters of the target.
 * Step 3. Repeat Step 1. and Step 2. until "right" reaches the end of the source.
 * 
 * Running Time:  252ms
 */
class Solution
{
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source, string &target)
    {
        if (source.size() == 0 || target.size() == 0)
            return "";

        // "need" records the frequencies of the characters in the target
        unordered_map<char, int> need, window;
        for (char c : target)
            need[c]++;

        // window [left, right)
        int left = 0, right = 0;

        // "valid" records the needed characters in "need"
        int valid = 0;

        // "start" records the start location of the minimum window substring
        // "len" records the length of the minimum window substring
        int start = 0, len = INT_MAX;

        // Step 3. Repeat Step 1. and Step 2.
        while (right < source.size())
        {
            // Step 1. Enlarge the window
            char c = source[right];
            right++;
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            // Step 2. Shrink the window
            while (valid == need.size())
            {
                if (right - left < len)
                {
                    start = left;
                    len = right - left;
                }

                // char "d" is to be deleted
                char d = source[left];
                left++;
                if (need.count(d))
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : source.substr(start, len);
    }
};