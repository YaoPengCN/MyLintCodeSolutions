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
 * Challenge
 * Can you do it without recursion?
 *
 * Stack
 * Ref[1]: https://www.jiuzhang.com/problem/binary-tree-postorder-traversal/#tag-lang-cpp
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

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        stack<TreeNode *> st;
        vector<int> result;
        if(root == NULL)
        {
            return result;
        }
        st.push(root);
        while(!st.empty())
        {
            TreeNode *temp = st.top();
            st.pop();
            result.insert(result.begin(), temp->val);
            if(temp->left != NULL)
                st.push(temp->left);
            if(temp->right != NULL)
                st.push(temp->right);
        }
        return result;
    }
};


// /**
//  * Challenge
//  * Can you do it without recursion?
//  *
//  * Morris Algorithm
//  * Ref[1]: https://www.jiuzhang.com/problem/binary-tree-postorder-traversal/#tag-lang-cpp
//  * Ref[2]: https://zhuanlan.zhihu.com/p/101321696
//  * Ref[3]: https://zhuanlan.zhihu.com/p/89858150
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
//      * @return: Postorder in ArrayList which contains node values.
//      */
//     vector<int> postorderTraversal(TreeNode *root)
//     {
//         vector<int> res;
//         TreeNode *cur = NULL;

//         while (root != NULL)
//         {
//             if (root->right != NULL)
//             {
//                 cur = root->right;
//                 while (cur->left && cur->left != root)
//                 {
//                     cur = cur->left;
//                 }
//                 if (cur->left == root)
//                 {
//                     cur->left = NULL;
//                     root = root->left;
//                 }
//                 else
//                 {
//                     res.push_back(root->val);
//                     cur->left = root;
//                     root = root->right;
//                 }
//             }
//             else
//             {
//                 res.push_back(root->val);
//                 root = root->left;
//             }
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };

// /**
//  * Divide and conquer
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
//      * @return: Postorder in ArrayList which contains node values.
//      */
//     vector<int> postorderTraversal(TreeNode *root)
//     {
//         vector<int> result;
//         if (!root)
//             return result;
//         vector<int> leftResult = postorderTraversal(root->left);
//         vector<int> midResult = {root->val};
//         vector<int> rightResult = postorderTraversal(root->right);
//         result.insert(result.end(), leftResult.begin(), leftResult.end());
//         result.insert(result.end(), rightResult.begin(), rightResult.end());
//         result.insert(result.end(), midResult.begin(), midResult.end());
//         return result;
//     }
// };