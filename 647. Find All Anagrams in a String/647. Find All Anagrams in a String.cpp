/** 
 * 647. Find All Anagrams in a String
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 * Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 40,000.
 * The order of output does not matter.
 * 
 * Example
 * Input: 
 * s = "cbaebabacd", p = "abc"
 * Output: 
 * [0, 6]
 * Explanation : 
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * 
 * Related Problems
 * 1362. Substring with Concatenation of All Words
 * 1169. Permutation in String
 * 1117. Smallest Range
 * 857. Minimum Window Subsequence
 * 772. Group Anagrams
 * 604. Window Sum
 * 171. Anagrams
 * 158. Valid Anagram
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
 * Running Time:  151ms
 */

class Solution
{
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    vector<int> findAnagrams(string &s, string &p) 
    {
        if (s.size() == 0 || p.size() == 0)
            return {};

        // "need" records the frequencies of the characters in the target
        unordered_map<char, int> need, window;
        for (char c : p)
            need[c]++;

        // window [left, right)
        int left = 0, right = 0;

        // "valid" records the needed characters in "need"
        int valid = 0;

        vector<int> result;

        // Step 3. Repeat Step 1. and Step 2.
        while (right < s.size())
        {
            // Step 1. Enlarge the window
            char c = s[right];
            right++;
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            // Step 2. Shrink the window
            while (right - left >= p.size())
            {
                if (valid == need.size())
                    result.push_back(left);

                // char "d" is to be deleted
                char d = s[left];
                left++;
                if (need.count(d))
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return result;
    }
};