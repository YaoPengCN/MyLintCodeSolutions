/** 
 * 118. Distinct Subsequences
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given two strings S and T. 
 * Count the number of distinct subsequences of S which equals T.
 * A subsequence of a string is a new string,
 * which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. 
 * (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not)
 *
 * Example
 * Example 1
 * Input: 
 * S = "rabbbit", T = "rabbit"
 * Output: 
 * 3
 * Explanation: 
 * You could remove any 'b' in S, so there are 3 ways to get T.
 *
 * Example 2
 * Input: 
 * S = "abcd", T = ""
 * Output: 
 * 1
 * Explanation: 
 * There is only 1 way to get T ---- remove all chars in S.
 * 
 * Challenge
 * Do it in O(n^2) time and O(n) memory.
 * O(n^2) memory is also acceptable if you do not know how to optimize memory.
 *
 * Related Problems 
 * 29. Interleaving String
 */

/**
 * Challenge
 * Do it in O(n^2) time and O(n) memory.
 * O(n^2) memory is also acceptable if you do not know how to optimize memory.
 * 
 * Dynamic programming
 * Ref: https://www.jiuzhang.com/problem/distinct-subsequences/#tag-lang-cpp
 * 
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param S: A string
     * @param T: A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T)
    {
        int n = S.size(), m = T.size();
        if (n <= 0 || m <= 0)
        {
            return 1;
        }

        // dp[i][j] records the times of T[0 : j + 1] appearing in S[0 : i + 1]
        vector<int> dp(m + 1);

        // dp[i][0] = 1
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++)
            for (int j = m; j > 0; j--)
                if (S[i - 1] == T[j - 1])
                    dp[j] += dp[j - 1];
        return dp[m];
    }
};