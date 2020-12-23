/** 
 * 94. Binary Tree Maximum Path Sum
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given a binary tree, find the maximum path sum.
 * The path may start and end at any node in the tree.
 * 
 * 
 * Example
 * Example 1
 * Input: 
 * For the following binary tree（only one node）:
 * 	2
 * Output：
 * 2
 * 
 * Example 2:
 * Input: 
 * For the following binary tree:
 *       1
 *      / \
 *     2   3
 * Output: 
 * 6
 *  
 * Related Problems
 * 1743. Bitwise ORs of Subarrays
 * 1353. Sum Root to Leaf Numbers
 * 863. Binary Tree Path Sum IV
 * 475. Binary Tree Maximum Path Sum II
 * 246. Binary Tree Path Sum II
 * 110. Minimum Path Sum
 */

/**
 * Divide and conquer
 * 4 cases to consider: left + root, right + root, root, left + right + root 
 * only the previous 3 cases could pass to up
 * Ref: https://www.jiuzhang.com/problem/binary-tree-maximum-path-sum/#tag-lang-cpp
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
     * @return: An integer
     */
    int maxPathSum(TreeNode *root)
    {
        if (root == NULL)
            return -1;
        int ret = INT_MIN, sum = 0;
        dfs(root, ret, sum);
        return ret;
    }

private:
    void dfs(TreeNode *root, int &ret, int &sum)
    {
        if (root == nullptr)
        {
            sum = 0;
            return;
        }

        int sum_l = 0, sum_r = 0;
        dfs(root->left, ret, sum_l);
        dfs(root->right, ret, sum_r);
        ret = max(ret, max(0, sum_l) + root->val);
        ret = max(ret, max(0, sum_r) + root->val);
        ret = max(ret, sum_l + sum_r + root->val);
        sum = max(0, max(sum_l, sum_r)) + root->val;
    }
};