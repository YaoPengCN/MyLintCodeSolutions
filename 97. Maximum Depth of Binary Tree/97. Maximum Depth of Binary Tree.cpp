/** 
* 97. Maximum Depth of Binary Tree
* Difficulty
* Easy
* 
* Description
* Given a binary tree, find its maximum depth.
* The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*
* Example
* Example 1
* Input：{}
* Output：0
* 
* Example 2:
* Input：{1,#,2,3}
* Output：3
* Explanation:
* 1
*  \
*   2
*  /
* 3
* it will be serialized {1,#,2,3}
* 
* Example 3:
* Input:  {1,2,3,#,#,4,5}
* Output: 3	
* Explanation: 
*       1
*      / \ 
*     2   3
*        / \
*       4   5  
* it will be serialized {1,2,3,#,#,4,5}
* 
* Related Problems 
* 1115. Average of Levels in Binary Tree
* 650. Find Leaves of Binary Tree
* 97. Maximum Depth of Binary Tree
*/

/**
 * DFS
 * Ref[1]: https://www.jiuzhang.com/problem/maximum-depth-of-binary-tree/#tag-lang-cpp
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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
};