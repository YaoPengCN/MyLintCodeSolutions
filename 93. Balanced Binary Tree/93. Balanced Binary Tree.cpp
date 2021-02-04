/** 
 * 93. Balanced Binary Tree
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * 
 * Example
 * Example  1:
 * Input: tree = {1,2,3}
 * Output: true
 * Explanation:
 * This is a balanced binary tree.
 * 		  1
 * 		 / \
 *      2   3
 * 
 * Example  2:
 * Input: tree = {3,9,20,#,#,15,7}
 * Output: true
 * Explanation:
 * This is a balanced binary tree.
 * 		  3
 * 		 / \
 * 		9  20
 * 		  /  \
 * 		 15   7
 * Example  3:
 * Input: tree = {1,#,2,3,4}
 * Output: false
 * Explanation:
 * This is not a balanced tree.
 * The height of node 1's right sub-tree is 2 but left sub-tree is 0.
 * 		  1
 * 		   \
 * 		    2
 * 		   /  \
 * 		  3    4
 *  
 * Related Problems
 * 467. Complete Binary Tree
 * 95. Validate Binary Search Tree
 */

/**
 * DFS
 * Ref: https://www.jiuzhang.com/problem/balanced-binary-tree/
 * Running Time: 102ms
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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root)
    {
        return depth(root) != -1;
    }

private:
    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = depth(root->left);
        int right = depth(root->right);

        if (left == -1 || right == -1 || abs(left - right) > 1)
            return -1;

        return max(left, right) + 1;
    }
};