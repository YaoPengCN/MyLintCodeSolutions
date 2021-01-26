/** 
 * 85. Insert Node in a Binary Search Tree
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a binary search tree and a new tree node, insert the node into the tree. 
 * You should keep the tree still be a valid binary search tree.
 * 
 * Clarification
 * You can assume there is no duplicate values in this tree + node.
 * 
 * Example
 * Example 1
 * Input: tree = {}, node = 1
 * Output: 1
 * Explanation:
 * Insert node 1 into the empty tree, so there is only one node on the tree.
 * 
 * Example 2
 * Input: tree = {2,1,4,3}, node = 6
 * Output: {2,1,4,3,6}
 * Explanation:
 * Like this:
 * 	  2             2
 * 	 / \           / \
 * 	1   4   -->   1   4
 * 	   /             / \
 * 	  3             3   6
 * 
 * Challenge
 * Can you do it without recursion?
 *
 * Related Problems
 * 701. Trim a Binary Search Tree
 * 219. Insert Node in Sorted Linked List
 * 87. Remove Node in Binary Search Tree
 * */

/** 
 * Challenge
 * Can you do it without recursion?
 * 
 * Ref: https://www.jiuzhang.com/problem/insert-node-in-a-binary-search-tree/
 *  
 * Running Time:  391ms
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
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode *insertNode(TreeNode *root, TreeNode *node)
    {
        if (root == nullptr)
        {
            return node;
        }
        TreeNode *temp = root;
        while (temp != nullptr)
        {
            if (node->val > temp->val)
            {
                //root->right
                if (temp->right == nullptr)
                {
                    temp->right = node;
                    return root;
                    break;
                }
                temp = temp->right;
                continue;
            }
            //root->left
            if (temp->left == nullptr)
            {
                temp->left = node;
                return root;
                break;
            }
            temp = temp->left;
        }
    }
};

// /**
//  * Ref: https://www.jiuzhang.com/problem/insert-node-in-a-binary-search-tree/
//  *
//  * Running Time:  348ms
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
//     /*
//      * @param root: The root of the binary search tree.
//      * @param node: insert this node into the binary search tree
//      * @return: The root of the new binary search tree.
//      */
//     TreeNode *insertNode(TreeNode *root, TreeNode *node)
//     {
//         if (root == NULL)
//         {
//             return node;
//         }
//         if (node->val < root->val)
//         {
//             root->left = insertNode(root->left, node);
//             return root;
//         }
//         root->right = insertNode(root->right, node);
//         return root;
//     }
// };