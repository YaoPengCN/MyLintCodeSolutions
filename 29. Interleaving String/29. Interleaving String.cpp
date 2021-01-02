/** 
 * 29. Interleaving String
 * Difficulty
 * Medium
 * 
 * Description
 * Given three strings: s1, s2, s3, determine whether s3 is formed by the interleaving of s1 and s2.
 *
 * Example
 * Example 1
 * Input: 
 * "aabcc"
 * "dbbca"
 * "aadbbcbcac"
 * Output:
 * true
 *
 * Example 2
 * Input:
 * ""
 * ""
 * "1"
 * Output:
 * false
 * 
 * Example 3
 * Input:
 * "aabcc"
 * "dbbca"
 * "aadbbbaccc"
 * Output:
 * false
 * 
 * Challenge
 * O(n^2) time or better
 *
 * Related Problems 
 * 118. Distinct Subsequences
 */

/**
 * Challenge
 * O(n^2) time or better
 * 
 * Dynamic programming
 * Ref: https://www.jiuzhang.com/problem/interleaving-string/#tag-lang-cpp
 * 
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3)
    {
        if (s1.length() + s2.length() != s3.length())
            return false;

        // bool interleave[i][j] presents 
        // whether the first i elements of s1 and the j elements of s2 could construct the first i+j elements of s3
        bool interleave[s1.length() + 1][s2.length() + 1];
        interleave[0][0] = true;
        for (int i = 1; i <= s1.length(); i++)
            interleave[i][0] = interleave[i - 1][0] && s1[i - 1] == s3[i - 1];
        for (int i = 1; i <= s2.length(); i++)
            interleave[0][i] = interleave[0][i - 1] && s2[i - 1] == s3[i - 1];
        for (int i = 1; i <= s1.length(); i++)
            for (int j = 1; j <= s2.length(); j++)
            {
                interleave[i][j] = false;
                if (s1[i - 1] == s3[i + j - 1])
                    interleave[i][j] = interleave[i][j] || interleave[i - 1][j];
                if (s2[j - 1] == s3[i + j - 1])
                    interleave[i][j] = interleave[i][j] || interleave[i][j - 1];
            }

        return interleave[s1.length()][s2.length()];
    }
};