/** 
* 66. Binary Tree Preorder Traversal
* Difficulty
* Easy
* 
* Description
* Given a binary tree, return the preorder traversal of its nodes' values.
* 
* Clarification
* · The first data is the root node, followed by the value of the left and right son nodes, and "#" indicates that there is no child node.
* · The number of nodes does not exceed 20.
*
* Example
* Example 1
* Input：{1,2,3}
* Output：[1,2,3]
* Explanation:
*    1
*   / \
*  2   3
* it will be serialized {1,2,3}
* Preorder traversal
* 
* Example 2:
* Input：{1,#,2,3}
* Output：[1,2,3]
* Explanation:
* 1
*  \
*   2
*  /
* 3
* it will be serialized {1,#,2,3}
* Preorder traversal
* 
* Challenge
* Can you do it without recursion?
* 
* Related Problems 
* 1783. Binary Tree Postorder Traversal-null
* 68. Binary Tree Postorder Traversal
* 67. Binary Tree Inorder Traversal
*/

/**
 * Challenge
 * Can you do it without recursion?
 * Ref[1]: https://www.jiuzhang.com/problem/binary-tree-preorder-traversal/#tag-lang-ALL
 * Run Time: ms
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

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        // write your code here
    }
};

// /**
//  * Divide and conquer
//  * Ref[1]: https://www.jiuzhang.com/problem/binary-tree-preorder-traversal/#tag-lang-ALL
//  * Run Time: 51ms
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
// 	/**
//      * @param root: A Tree
//      * @return: Preorder in ArrayList which contains node values.
//      */
// 	vector<int> preorderTraversal(TreeNode *root)
// 	{
// 		vector<int> ans;
// 		if (root == NULL)
// 			return ans;
// 		//divide
// 		vector<int> left = preorderTraversal(root->left);
// 		vector<int> right = preorderTraversal(root->right);
// 		//conquer
// 		ans.push_back(root->val);
// 		for (auto i : left)
// 			ans.push_back(i);
// 		for (auto i : right)
// 			ans.push_back(i);
// 		return ans;
// 	}
// };