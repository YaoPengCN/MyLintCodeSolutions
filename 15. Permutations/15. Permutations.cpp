/** 
* 15. Permutations
* Difficulty
* Medium
* 
* Description
* Given a list of numbers, return all possible permutations.
*
* Clarification
* You can assume that there is no duplicate numbers in the list.
*
* Example
* Example 1
* Input: [1]
* Output:
* [
*   [1]
* ]
* 
* Example 2:
* Input: [1,2,3]
* Output:
* [
*   [1,2,3],
*   [1,3,2],
*   [2,1,3],
*   [2,3,1],
*   [3,1,2],
*   [3,2,1]
* ]	
* 
* Challenge
* Do it without recursion.
* 
* Related Problems 
* 935. Cartesian Product
* 388. Permutation Sequence
* 371. Print Numbers by Recursion
* 16. Permutations II
*/

/**
 * Challenge
 * Do it without recursion.
 * Ref[1]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hui-su-suan-fa-xiang-jie-xiu-ding-ban
 * Ref[2]: https://www.jiuzhang.com/problem/permutations/#tag-lang-cpp
 * Running Time:  448ms
 */

class Solution
{
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        bool next = true;

        sort(nums.begin(), nums.end());
        while (next)
        {
            res.push_back(nums);
            next = nextPermute(nums);
        }
        return res;
    }

private:
    bool nextPermute(vector<int> &nums)
    {
        int i = nums.size() - 2;

        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }

        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        else
        {
            return false;
        }

        reverse(nums.begin() + i + 1, nums.end());
        return true;
    }
};

// /**
//  * Ref[1]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hui-su-suan-fa-xiang-jie-xiu-ding-ban
//  * Ref[2]: https://www.jiuzhang.com/problem/permutations/#tag-lang-cpp
//  * Running Time:  403ms
//  */

// class Solution
// {
// public:
//     /*
//      * @param nums: A list of integers.
//      * @return: A list of permutations.
//      */
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         vector<vector<int>> results;

//         // 如果数组为空直接返回空
//         if (nums.size() == 0)
//         {
//             results.push_back(vector<int>());
//             return results;
//         }

//         // dfs
//         vector<bool> used(nums.size(), 0);
//         vector<int> current;
//         dfs(nums, used, current, results);

//         return results;
//     }

// private:
//     void dfs(vector<int> nums, vector<bool> &used, vector<int> &current, vector<vector<int>> &results)
//     {
//         //找到一组排列，已到达边界条件
//         if (current.size() == nums.size())
//         {
//             results.push_back(current);
//             return;
//         }

//         for (int i = 0; i < nums.size(); i++)
//         {
//             // i位置这个元素已经被用过
//             if (used[i])
//             {
//                 continue;
//             }

//             //继续递归
//             current.push_back(nums[i]);
//             used[i] = true;
//             dfs(nums, used, current, results);
//             used[i] = false;
//             current.pop_back();
//         }
//     }
// };