/** 
* 68. Binary Tree Postorder Traversal
* Difficulty
* Easy
* 
* Description
* Given a binary tree, return the postorder traversal of its nodes' values.
* 
* Clarification
* · The first data is the root node, followed by the value of the left and right son nodes, and "#" indicates that there is no child node.
* · The number of nodes does not exceed 20.
*
* Example
* Example 1
* Input: {1,2,3}
* Output: [2,3,1]
* Explanation:
*    1
*   / \
*  2   3
* it will be serialized {1,2,3}
* Postorder traversal
* 
* Example 2:
* Input: {1,#,2,3}
* Output: [3,2,1]
* Explanation:
* 1
*  \
*   2
*  /
* 3
* it will be serialized {1,#,2,3}
* Postorder Traversal
* 
* Challenge
* Can you do it without recursion?
* 
* Related Problems 
* 67. Binary Tree Inorder Traversal
* 66. Binary Tree Preorder Traversal
*/

/**
 * Divide and conquer
 * Run Time: 50ms
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
     * @param root: A Tree
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        vector<int> leftResult = postorderTraversal(root->left);
        vector<int> midResult = {root->val};
        vector<int> rightResult = postorderTraversal(root->right);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        result.insert(result.end(), rightResult.begin(), rightResult.end());
        result.insert(result.end(), midResult.begin(), midResult.end());
        return result;
    }
};