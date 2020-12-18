/** 
 * 16. Permutations II
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given a list of numbers with duplicate number in it. 
 * Find all unique permutations. 
 * 
 * Example
 * Example 1
 * Input: [1,1]
 * Output:
 * [
 *   [1,1]
 * ]
 * 
 * Example 2
 * Input: [1,2,2]
 * Output:
 * [
 *   [1,2,2],
 *   [2,1,2],
 *   [2,2,1]
 * ]
 *
 * Challenge
 * Using recursion to do it is acceptable. 
 * If you can do it without recursion, that would be great!
 * 
 * Related Problems
 * 917. Palindrome Permutation II
 * 388. Permutation Sequence
 * 190. Next Permutation II
 * 52. Next Permutation
 * 15. Permutations
 * */

/**  
 * DFS + Recursive
 * Ref: https://www.jiuzhang.com/problem/permutations-ii/#tag-lang-cpp
 * Running Time:  384ms
 */

class Solution
{
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<remove_reference<decltype(nums)>::type> result;
        function<decltype(result)(decltype(nums))> dfs;
        dfs = [&dfs](decltype(nums) nums) -> decltype(result) {
            if (nums.empty())
                return {{}};
            decltype(result) res;
            for (auto i = 0; i < nums.size(); ++i)
                if (i < 1 || nums[i] != nums[i - 1])
                {
                    auto n = nums;
                    n.erase(n.begin() + i);
                    for (auto r : dfs(n))
                    {
                        res.push_back(r);
                        res.back().push_back(nums[i]);
                    }
                }
            return res;
        };
        return dfs(nums);
    }
};