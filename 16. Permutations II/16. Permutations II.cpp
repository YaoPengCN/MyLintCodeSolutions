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
 * Challenge
 * Using recursion to do it is acceptable. 
 * If you can do it without recursion, that would be great!
 * 
 * DFS + Non-recursive
 * Ref: https://www.jiuzhang.com/problem/permutations-ii/#tag-lang-cpp
 * Running Time: 451ms
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
        int s = nums.size();
        if (s < 1)
            return {{}};
        vector<int> states(s, 0);
        vector<bool> used(s + 1, false);
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        nums.insert(nums.begin(), INT_MIN);
        for (int i = 0; i >= 0;)
        {
            auto prev = states[i];
            auto ok = false;
            for (used[prev] = false; !ok && ++states[i] <= s;
                 ok = !used[states[i]] && nums[states[i]] != nums[prev])
                ;
            if (ok)
            {
                used[states[i]] = true;
                ++i;
                if (i >= s)
                {
                    vector<int> r(s);
                    for (int j = 0; j < s; ++j)
                        r[j] = nums[states[j]];
                    result.push_back(r);
                    --i;
                }
                else
                    states[i] = 0;
            }
            else
                --i;
        }
        return result;
    }
};

// /**
//  * DFS + Recursive
//  * Ref: https://www.jiuzhang.com/problem/permutations-ii/#tag-lang-cpp
//  * Running Time: 384ms
//  */

// class Solution
// {
// public:
//     /*
//      * @param :  A list of integers
//      * @return: A list of unique permutations
//      */
//     vector<vector<int>> permuteUnique(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         vector<remove_reference<decltype(nums)>::type> result;
//         function<decltype(result)(decltype(nums))> dfs;
//         dfs = [&dfs](decltype(nums) nums) -> decltype(result) {
//             if (nums.empty())
//                 return {{}};
//             decltype(result) res;
//             for (auto i = 0; i < nums.size(); ++i)
//                 if (i < 1 || nums[i] != nums[i - 1])
//                 {
//                     auto n = nums;
//                     n.erase(n.begin() + i);
//                     for (auto r : dfs(n))
//                     {
//                         res.push_back(r);
//                         res.back().push_back(nums[i]);
//                     }
//                 }
//             return res;
//         };
//         return dfs(nums);
//     }
// };