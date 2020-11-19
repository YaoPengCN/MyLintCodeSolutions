/** 
 * 384. Longest Substring Without Repeating Characters
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Example
 * Example 1
 * Input: 
 * "abcabcbb"
 * Output: 
 * 3
 * Explanation: 
 * The longest substring is "abc".
 * 
 * Example 2:
 * Input: 
 * "bbbbb"
 * Output: 
 * 1
 * Explanation: 
 * The longest substring is "b".
 * 
 * Challenge
 * time complexity O(n)
 * 
 * Related Problems
 * 1362. Substring with Concatenation of All Words
 * 1169. Permutation in String
 * 1117. Smallest Range
 * 928. Longest Substring with At Most Two Distinct Characters
 * 857. Minimum Window Subsequence
 * 772. Group Anagrams
 * 604. Window Sum
 * 386. Longest Substring with At Most K Distinct Characters
 * 171. Anagrams
 * 158. Valid Anagram
 * 32. Minimum Window Substring
 * */

/**
 * Challenge
 * time complexity O(n)
 * 
 * Sliding window
 * https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hua-dong-chuang-kou-ji-qiao-jin-jie
 * 
 * Define the window [left, right).
 * Step 1. Enlarge the window until the window contains all the characters of the target.
 * Step 2. Shrink the window until the window no longer contains all the characters of the target.
 * Step 3. Repeat Step 1. and Step 2. until "right" reaches the end of the source.
 * 
 * Running Time:  51ms
 */

class Solution
{
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    int lengthOfLongestSubstring(string &s)
    {
        if (s.size() == 0)
            return 0;

        // window [left, right)
        unordered_map<char, int> window;
        int left = 0, right = 0;

        int result;

        // Step 3. Repeat Step 1. and Step 2.
        while (right < s.size())
        {
            // Step 1. Enlarge the window
            char c = s[right];
            right++;
            window[c]++;

            // Step 2. Shrink the window
            while (window[c] > 1)
            {
                // char "d" is to be deleted
                char d = s[left];
                left++;
                window[d]--;
            }
            result = max(result, right - left);
        }
        return result;
    }
};