/** 
 * 17. Subsets
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given a set of distinct integers, return all possible subsets.
 * 
 * Clarification
 * 1. Elements in a subset must be in non-descending order.
 * 2. The solution set must not contain duplicate subsets.
 * 
 * Example
 * Example 1
 * Input: [0]
 * Output:
 * [
 *   [],
 *   [0]
 * ]
 * 
 * Example 2
 * Input: [1,2,3]
 * Output:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 *
 * Challenge
 * Can you do it in both recursively and iteratively?
 * 
 * Related Problems
 * 1210. Increasing Subsequences
 * 935. Cartesian Product
 * 761. Smallest Subset
 * 730. Sum of All Subsets
 * 680. Split String
 * 426. Restore IP Addresses
 * 18. Subsets II
 * */

/**
 * Challenge
 * Can you do it in both recursively and iteratively?
 *   
 * BFS iteratively
 * Ref: https://www.jiuzhang.com/problem/subsets/#tag-lang-cpp
 * Running Time: 50ms
 */

class Solution
{
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        res.push_back({});
        int idx = 0;

        while (idx < res.size())
        {
            vector<int> subset = res[idx];
            idx++;
            for (int num : nums)
            {
                // the following condition is to sort the result
                if (!subset.empty() && num <= subset.back())
                {
                    continue;
                }

                subset.push_back(num);
                res.push_back(subset);
                subset.pop_back();
            }
        }
        return res;
    }
};

// /**
//  * DFS + backtracking
//  * Ref: https://www.jiuzhang.com/problem/subsets/#tag-lang-cpp
//  * Running Time: 50ms
//  */

// class Solution
// {
// public:
//     /**
//      * @param nums: A set of numbers
//      * @return: A list of lists
//      */
//     vector<vector<int>> subsets(vector<int> &nums)
//     {
//         vector<vector<int>> res;

//         // nums must be sorted, or the solution would not pass
//         sort(nums.begin(), nums.end());

//         // dfs
//         vector<int> subset;
//         dfs(nums, 0, subset, res);
//         return res;
//     }

// private:
//     void dfs(vector<int> &nums, int k, vector<int> &subset, vector<vector<int>> &res)
//     {
//         // store the subset into res
//         res.push_back(vector<int>(subset));
//         // add an element in the subset
//         for (int i = k; i < nums.size(); ++i)
//         {
//             subset.push_back(nums[i]);

//             // deeper dfs
//             dfs(nums, i + 1, subset, res);

//             // backtracking
//             subset.pop_back();
//         }
//     }
// };
