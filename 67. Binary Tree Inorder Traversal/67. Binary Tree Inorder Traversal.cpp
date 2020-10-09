/** 
* 67. Binary Tree Inorder Traversal
* Difficulty
* Easy
* 
* Description
* Given a binary tree, return the inorder traversal of its nodes' values.
* 
* Clarification
* · The first data is the root node, followed by the value of the left and right son nodes, and "#" indicates that there is no child node.
* · The number of nodes does not exceed 20.
*
* Example
* Example 1
* Input: {1,2,3}
* Output: [2,1,3]
* Explanation:
*    1
*   / \
*  2   3
* it will be serialized {1,2,3}
* Inorder traversal
* 
* Example 2:
* Input: {1,#,2,3}
* Output: [1,3,2]
* Explanation:
* 1
*  \
*   2
*  /
* 3
* it will be serialized {1,#,2,3}
* Inorder Traversal
* 
* Challenge
* Can you do it without recursion?
* 
* Related Problems 
* 1783. Binary Tree Postorder Traversal-null
* 1115. Average of Levels in Binary Tree
* 915. Inorder Predecessor in BST
* 902. Kth Smallest Element in a BST
* 901. Closest Binary Search Tree Value II
* 68. Binary Tree Postorder Traversal
* 66. Binary Tree Preorder Traversal
*/

/**
 * Challenge
 * Can you do it without recursion?
 *
 * Stack
 * Ref[1]: https://www.jiuzhang.com/problem/binary-tree-inorder-traversal/#tag-lang-cpp
 * Ref[2]: https://blog.csdn.net/zhuiyisinian/article/details/107946790
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
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
};

// /**
//  * Challenge
//  * Can you do it without recursion?
//  *
//  * Morris Algorithm
//  * Ref[1]: https://www.jiuzhang.com/problem/binary-tree-inorder-traversal/#tag-lang-cpp
//  * Ref[2]: https://zhuanlan.zhihu.com/p/101321696
//  * Ref[3]: https://zhuanlan.zhihu.com/p/89858150
//  * Run Time: 52ms
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
//      * @param root: A Tree
//      * @return: Inorder in ArrayList which contains node values.
//      */
//     vector<int> inorderTraversal(TreeNode *root)
//     {
//         vector<int> res;
//         TreeNode *cur = NULL;

//         while (root != NULL)
//         {
//             if (root->left != NULL)
//             {
//                 cur = root->left;
//                 while (cur->right && cur->right != root)
//                 {
//                     cur = cur->right;
//                 }
//                 if (cur->right == root)
//                 {
//                     res.push_back(root->val);
//                     cur->right = NULL;
//                     root = root->right;
//                 }
//                 else
//                 {
//                     cur->right = root;
//                     root = root->left;
//                 }
//             }
//             else
//             {
//                 res.push_back(root->val);
//                 root = root->right;
//             }
//         }
//         return res;
//     }
// };

// /**
//  * Divide and conquer
//  * Ref[1]: https://www.jiuzhang.com/problem/binary-tree-inorder-traversal/#tag-lang-cpp
//  * Run Time: 50ms
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
//      * @param root: A Tree
//      * @return: Inorder in ArrayList which contains node values.
//      */
//     vector<int> inorderTraversal(TreeNode *root)
//     {
//         vector<int> result;
//         if (!root)
//             return result;
//         vector<int> leftResult = inorderTraversal(root->left);
//         vector<int> midResult = {root->val};
//         vector<int> rightResult = inorderTraversal(root->right);
//         result.insert(result.end(), leftResult.begin(), leftResult.end());
//         result.insert(result.end(), midResult.begin(), midResult.end());
//         result.insert(result.end(), rightResult.begin(), rightResult.end());
//         return result;
//     }
// };
