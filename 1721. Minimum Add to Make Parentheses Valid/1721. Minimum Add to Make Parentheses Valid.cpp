/** 
 * 1721. Minimum Add to Make Parentheses Valid
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.
 * Formally, a parentheses string is valid if and only if:
 * it is the empty string, 
 * or it can be written as AB (A concatenated with B), where A and B are valid strings, 
 * or it can be written as (A), where A is a valid string.
 * Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.
 *  
 * Clarification
 * S.length <= 1000
 * S only consists of '(' and ')' characters.
 * 
 * Example
 * Example 1:
 * Input: "())"
 * Output: 1
 * 
 * Example 2:
 * Input: "((("
 * Output: 3
 * 
 * Example 3:
 * Input: "()"
 * Output: 0
 * 
 * Example 4:
 * Input: "()))(("
 * Output: 4
 * 
 * Related Problems  
 * 423. Valid Parentheses
 * 427. Generate Parentheses
 * 193. Longest Valid Parentheses
 * */

/**
 * Ref[1]: https://mp.weixin.qq.com/s/plxWQsTgW6LW3T7yBAXjQg
 * Ref[2]: https://www.jiuzhang.com/problem/minimum-add-to-make-parentheses-valid/#tag-lang-cpp
 * Running Time: 51ms
 */

class Solution
{
public:
    /**
     * @param S: the given string
     * @return: the minimum number of parentheses we must add
     */
    int minAddToMakeValid(string &S)
    {
        int left = 0;  // the need of left parentheses
        int right = 0; // the need of right parentheses
        for (string::size_type i = 0; i != S.size(); i++)
        {
            if (right == 0 && S[i] == ')')
            {
                left++;
            }
            else
            {
                right += (S[i] == '(' ? 1 : -1);
            }
        }
        return left + right;
    }
};
