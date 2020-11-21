/** 
 * 90. k Sum II
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given n unique positive integers, number k (1<=k<=n) and target.
 * Find all possible k integers where their sum is target.
 * 
 * Example
 * Example 1
 * Input:
 * List = [1,2,3,4]
 * k = 2
 * target = 5
 * Output:
 * [[1,4],[2,3]]
 * Explanation: 
 * 1 + 4 = 2 + 3 = 5
 * 
 * Example 2
 * Input: 
 * List = [1,2,3,4,5]
 * k = 3
 * target = 8
 * Output:	
 * [[1,3,4]]
 *
 * Related Problems
 * 1689. k Sum III
 * 89. k Sum
 * 58. 4Sum
 * 57. 3Sum
 * 56. Two Sum
 * */

/**
 * DFS
 * Ref[1]: https://www.jiuzhang.com/problem/k-sum-ii/#tag-lang-cpp
 * Running Time:  1298ms
 */

class Solution
{
public:
    /*
     * @param A: an integer array
     * @param k: a positive integer <= length(A)
     * @param target: an integer
     * @return: A list of lists of integer
     */
    vector<vector<int>> kSumII(vector<int> &A, int k, int target)
    {
        if (A.empty())
        {
            return {};
        }

        sort(A.begin(), A.end());
        vector<vector<int>> res;
        vector<int> out;
        dfs(A, k, target, 0, out, res);
        return res;
    }

private:
    void dfs(vector<int> &A, int k, int target, int idx,
             vector<int> &out, vector<vector<int>> &res)
    {
        if (out.size() > k || target < 0)
        {
            return;
        }
        if (out.size() == k)
        {
            if (target == 0)
            {
                res.push_back(out);
            }
            return;
        }

        for (int i = idx; i < A.size(); i++)
        {
            out.push_back(A[i]);
            target -= A[i];
            dfs(A, k, target, i + 1, out, res);
            target += A[i];
            out.pop_back();
        }
    }
};