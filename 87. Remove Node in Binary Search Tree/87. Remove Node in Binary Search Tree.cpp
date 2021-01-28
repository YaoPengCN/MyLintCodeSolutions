/** 
 * 87. Remove Node in Binary Search Tree
 * 
 * Difficulty
 * Hard
 * 
 * Description
 * Given a root of Binary Search Tree with unique value for each node. Remove the node with given value. If there is no such a node with given value in the binary search tree, do nothing. 
 * You should keep the tree still a binary search tree after removal.
 * 
 * Example
 * Example 1
 * Input: 
 * Tree = {5,3,6,2,4}
 * k = 3
 * Output: {5,2,6,#,4} or {5,4,6,2}
 * Explanation:
 * Given binary search tree:
 *     5
 *    / \
 *   3   6
 *  / \
 * 2   4
 * Remove 3, you can either return:
 *     5
 *    / \
 *   2   6
 *    \
 *     4
 * or
 *     5
 *    / \
 *   4   6
 *  /
 * 2
 * 
 * Example 2
 * Input: 
 * Tree = {5,3,6,2,4}
 * k = 4
 * Output: {5,3,6,2}
 * Explanation:
 * Given binary search tree:
 *     5
 *    / \
 *   3   6
 *  / \
 * 2   4
 * Remove 4, you should return:
 *     5
 *    / \
 *   3   6
 *  /
 * 2
 *
 * Related Problems
 * 85. Insert Node in Binary Search Tree
 * */

/** 
 * Ref: https://www.jiuzhang.com/problem/remove-node-in-binary-search-tree/
 *  
 * Running Time:  704ms
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
    /*
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode *removeNode(TreeNode *root, int value)
    {
        if (root == nullptr)
        {
            return root;
        }
        // go left/right
        if (value < root->val)
        {
            root->left = removeNode(root->left, value);
            return root;
        }
        if (value > root->val)
        {
            root->right = removeNode(root->right, value);
            return root;
        }

        // root->val = value
        // leaf node
        if (!root->left && !root->right)
        {
            return nullptr;
        }
        // more general case
        // left empty
        if (!root->left)
        {
            return root->right;
        }
        // right empty
        if (!root->right)
        {
            return root->left;
        }
        // both left/right non empty
        TreeNode *cur = root->left;
        while (cur->right)
        {
            cur = cur->right;
        }
        cur->right = root->right;
        return root->left;
    }
};