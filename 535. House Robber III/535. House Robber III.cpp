/** 
 * 535. House Robber III
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * This is an extension of problem 392. House Robber and 534. House Robber II.
 * The thief has found himself a new place for his thievery again. 
 * There is only one entrance to this area, called the "root." 
 * Besides the root, each house has one and only one parent house. 
 * After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
 * It will automatically contact the police if two directly-linked houses were broken into on the same night.
 * Determine the maximum amount of money the thief can rob tonight without alerting the police.
 * 
 * Example
 * Example 1
 * Input:  {3,2,3,#,3,#,1}
 * Output: 7
 * Explanation:
 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 *   3
 *  / \
 * 2   3
 *  \   \
 *   3   1
 * 
 * Example 2:
 * Input:  {3,4,5,1,3,#,1}
 * Output: 9
 * Explanation:
 * Maximum amount of money the thief can rob = 4 + 5 = 9.
 *     3
 *    / \
 *   4   5
 *  / \   \
 * 1   3   1
 *  
 * Related Problems 
 * 1142. Non-negative Integers without Consecutive Ones
 * 866. Coin Path
 * 535. House Robber III
 * 534. House Robber II
 * 515. Paint House
 * 514. Paint Fence
 * 392. House Robber
 * 366. Fibonacci
 * 111. Climbing Stairs
 */

/**
 * Dynamic programming
 * Ref[1]: https://mp.weixin.qq.com/s/z44hk0MW14_mAQd7988mfw
 * Ref[2]: https://www.jiuzhang.com/problem/house-robber-iii/#tag-lang-cpp
 * Running Time: 50ms
 */

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution
{
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode *root)
    {
        vector<int> dp = dfs(root);
        // dp[0] for not robbing, dp[1] for robbing
        return max(dp[0], dp[1]);
    }

private:
    vector<int> dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {0, 0};
        }

        vector<int> dp(2, 0);

        // divide and conquer
        vector<int> dpLeft = dfs(root->left);
        vector<int> dpRight = dfs(root->right);

        dp[0] = max(dpLeft[0], dpLeft[1]) + max(dpRight[0], dpRight[1]);
        dp[1] = (root->val) + dpLeft[0] + dpRight[0];

        return dp;
    }
};
