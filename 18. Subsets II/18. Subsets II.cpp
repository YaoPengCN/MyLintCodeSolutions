/** 
 * 18. Subsets II
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 * 
 * Clarification
 * 1. Each element in a subset must be in non-descending order.
 * 2. The ordering between two subsets is free.
 * 3. The solution set must not contain duplicate subsets.
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
 * Input: [1,2,2]
 * Output:
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
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
 * 17. Subsets
 * */

/**
 * Challenge
 * Can you do it in both recursively and iteratively?
 * 
 * DFS iteratively
 *  
 * Ref: https://www.jiuzhang.com/problem/subsets-ii/#tag-lang-cpp
 * Running Time: 101ms
 */

class Solution
{
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets = {{}};

        // indexes records the indexes of ending elements of evert subsets
        vector<int> indexes = {-1};

        for (int i = 0; i != nums.size(); ++i)
        {
            int size = subsets.size();
            for (int s = 0; s != size; ++s)
            {
                // remove duplications
                if (i > 0 && nums[i] == nums[i - 1] && indexes[s] != i - 1)
                {
                    continue;
                }
                subsets.push_back(subsets[s]);
                subsets.back().push_back(nums[i]);
                indexes.push_back(i);
            }
        }

        return subsets;
    }
};

// /**
//  * DFS + backtracing
//  *
//  * Ref: https://www.jiuzhang.com/problem/subsets-ii/#tag-lang-cpp
//  * Running Time: 50ms
//  */

// class Solution
// {
// public:
//     /**
//      * @param nums: A set of numbers.
//      * @return: A list of lists. All valid subsets.
//      */
//     vector<vector<int>> subsetsWithDup(vector<int> &nums)
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
//             // pruning
//             if (i != k && nums[i] == nums[i - 1])
//             {
//                 continue;
//             }
//             subset.push_back(nums[i]);

//             // deeper dfs
//             dfs(nums, i + 1, subset, res);

//             // backtracking
//             subset.pop_back();
//         }
//     }
// };