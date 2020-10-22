/** 
 * 423. Valid Parentheses
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *  
 * Example
 * Example 1:
 * Input: "([)]"
 * Output: False
 * 
 * Example 2:
 * Input: "()[]{}"
 * Output: True
 * 
 * Challenge
 * Use O(n) time, n is the number of parentheses. 
 * 
 * Related Problems  
 * 427. Generate Parentheses
 * 193. Longest Valid Parentheses
 * */

/**
 * Stack
 * Ref[1]: https://mp.weixin.qq.com/s/plxWQsTgW6LW3T7yBAXjQg
 * Ref[2]: https://www.jiuzhang.com/problem/valid-parentheses/#tag-lang-cpp
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
   * @param s A string
   * @return whether the string is a valid parentheses
   */
    bool isValidParentheses(string &s)
    {
        // Write your code here
        stack<char> st;

        for (string::size_type i = 0; i != s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }

            if (st.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}'))
            {
                return false;
            }

            if (!st.empty() && s[i] == ')')
            {
                if (st.top() != '(')
                {
                    return false;
                }
                st.pop();
            }

            if (!st.empty() && s[i] == ']')
            {
                if (st.top() != '[')
                {
                    return false;
                }
                st.pop();
            }

            if (!st.empty() && s[i] == '}')
            {
                if (st.top() != '{')
                {
                    return false;
                }
                st.pop();
            }
        }
        if (!st.empty())
        {
            return false;
        }

        return true;
    }
};
