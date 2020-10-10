/** 
* 155. Minimum Depth of Binary Tree
* Difficulty
* Easy
* 
* Description
* Given a binary tree, find its minimum depth.
* The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
* Output: 2	
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
 * BFS
 * Ref[1]: https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/bfs-kuang-jia
 * Ref[2]: https://www.jiuzhang.com/problem/minimum-depth-of-binary-tree/
 * Run Time: 101ms
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
     * @param root: The root of binary tree
     * @return: An integer
     */
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty())
        {
            depth++;
            int qSize = q.size();
            for (int i = 0; i < qSize; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (!cur->left && !cur->right)
                {
                    return depth;
                }
                if (cur->left)
                {
                    q.push(cur->left);
                }
                if (cur->right)
                {
                    q.push(cur->right);
                }
            }
        }
        return 0;
    }
};

// /**
//  * Divide and conquer
//  * Ref[1]: https://www.jiuzhang.com/problem/minimum-depth-of-binary-tree/
//  * Run Time: 101ms
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
//      * @param root: The root of binary tree
//      * @return: An integer
//      */
//     int minDepth(TreeNode *root)
//     {
//         if (root == NULL)
//             return 0;
//         int leftDepth = minDepth(root->left);
//         int rightDepth = minDepth(root->right);
//         // 当左子树或右子树为空时，最小深度取决于另一颗子树
//         if (leftDepth == 0 || rightDepth == 0)
//         {
//             return leftDepth + rightDepth + 1;
//         }
//         return min(leftDepth, rightDepth) + 1;
//     }
// };