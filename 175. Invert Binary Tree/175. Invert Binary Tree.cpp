/** 
 * 175. Invert Binary Tree
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Invert a binary tree.Left and right subtrees exchange.
 * 
 * Example
 * Example 1
 * Input: {1,3,#}
 * Output: {1,#,3}
 * Explanation:
 * 	  1    1
 * 	 /  =>  \
 * 	3        3
 * 
 * Example 2:
 * Input: {1,2,3,#,#,4}
 * Output: {1,3,2,#,4}
 * Explanation:
 *       1         1
 *      / \       / \
 *     2   3  => 3   2
 *        /       \
 *       4         4
 * 
 * Challenge
 * Do it in recursion is acceptable, can you do it without recursion?
 * 
 * Related Problems
 * 389. Valid Sudoku
 * 370. Convert Expression to Reverse Polish Notation
 * 367. Expression Tree Build
 * 248. Count of Smaller Number
 */

/**
 * Challenge
 * Do it in recursion is acceptable, can you do it without recursion?
 * 
 * No-recursion with stack
 * Ref: https://www.jiuzhang.com/problem/invert-binary-tree/
 * 
 * Running Time: 61ms
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        std::stack<TreeNode *> stack;
        stack.push(root);

        while (!stack.empty())
        {
            TreeNode *node = stack.top();
            stack.pop();

            swap(node->left, node->right);

            if (node->left)
            {
                stack.push(node->left);
            }
            if (node->right)
            {
                stack.push(node->right);
            }
        }
    }
};

// /**
//  * DFS
//  * Ref: https://www.jiuzhang.com/problem/invert-binary-tree/
//  * Running Time: 41ms
//  */

// /**
//  * Definition of TreeNode:
//  * class TreeNode {
//  * public:
//  *     int val;
//  *     TreeNode *left, *right;
//  *     TreeNode(int val) {
//  *         this->val = val;
//  *         this->left = this->right = NULL;
//  *     }
//  * }
//  */

// class Solution
// {
// public:
//     /**
//      * @param root: a TreeNode, the root of the binary tree
//      * @return: nothing
//      */
//     void invertBinaryTree(TreeNode *root)
//     {
//         if (root == nullptr)
//             return;
//         swap(root->left, root->right);
//         invertBinaryTree(root->left);
//         invertBinaryTree(root->right);
//     }
// };