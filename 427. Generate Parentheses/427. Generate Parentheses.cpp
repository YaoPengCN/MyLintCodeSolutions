/** 
 * 427. Generate Parentheses
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given n, and there are n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *  
 * Example
 * Example 1:
 * Input: 3
 * Output: ["((()))", "(()())", "(())()", "()(())", "()()()"]
 * 
 * Example 2:
 * Input: 2
 * Output: ["()()", "(())"]
 * 
 * Related Problems  
 * 427. Generate Parentheses
 * 423. Valid Parentheses
 * 193. Longest Valid Parentheses
 * 164. Unique Binary Search Trees II
 * 163. Unique Binary Search Trees
 * */

/**
 * The number of possible realizations equals to Catalan number: C(n)=(2n)!/(n!(n+1)!)
 * Solve this problem by DFS
 * Ref[1]: https://www.jiuzhang.com/problem/generate-parentheses/
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param n: n pairs
     * @return: All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        dfs(0, 0,"", n, result);
        return result;
    }

private:
    // use "vector<string> &result" instead of "vector<string> result" to avoid the cost of duplications.
    void dfs(int leftCount, int rightCount, string nowSeq, int n, vector<string> &result)
    {
        if (leftCount > n || rightCount > n)
            return;
        if (leftCount < rightCount)
            return;
        if (leftCount == n && rightCount == n)
        {
            result.push_back(nowSeq);
            return;
        }
        dfs(leftCount + 1, rightCount, nowSeq + "(", n, result);
        dfs(leftCount, rightCount + 1, nowSeq + ")", n, result);
    }
};