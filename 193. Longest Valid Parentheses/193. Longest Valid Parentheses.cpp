/** 
 * 193. Longest Valid Parentheses
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *  
 * Example
 * Example 1:
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * Example 2:
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * Related Problems  
 * 427. Generate Parentheses
 * 423. Valid Parentheses
 * */

/**
 * DP with reversed direction
 * Ref[1]: https://www.jiuzhang.com/problem/longest-valid-parentheses/#tag-lang-cpp
 * Running Time: 561ms
 */

class Solution
{
public:
    /**
     * @param s: a string
     * @return: return a integer
     */
    int longestValidParentheses(string &s)
    {
        if (s.size() <= 1)
            return 0;
        int result = 0;

        // dp[i] presents the length of the longest valid sub-string starting from i to s.size()-1
        vector<int> dp(s.size(), 0);

        for (int i = s.size() - 2; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                int j = i + dp[i + 1] + 1;
                if (j < s.size() && s[j] == ')')
                {
                    dp[i] = dp[i + 1] + 2;
                    if (j + 1 < s.size())
                        dp[i] += dp[j + 1];
                }
                result = max(result, dp[i]);
            }
        }
        return result;
    }
};