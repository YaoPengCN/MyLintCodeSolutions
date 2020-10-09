/** 
* 69. Binary Tree Level Order Traversal
* Difficulty
* Easy
* 
* Description
* Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
* 
* Clarification
* · The first data is the root node, followed by the value of the left and right son nodes, and "#" indicates that there is no child node.
* · The number of nodes does not exceed 20.
*
* Example
* Example 1
* Input: {1,2,3}
* Output: [[1],[2,3]]
* Explanation:
*    1
*   / \
*  2   3
* it will be serialized {1,2,3}
* Level order traversal
* 
* Example 2:
* Input: {1,#,2,3}
* Output: [[1],[2],[3]]
* Explanation:
* 1
*  \
*   2
*  /
* 3
* it will be serialized {1,#,2,3}
* Level order traversal
* 
* Challenge
* Challenge 1: Using only 1 queue to implement it.
* Challenge 2: Use BFS algorithm to do it.
* 
* Related Problems 
* 797. Reach a Number
* 760. Binary Tree Right Side View
* 651. Binary Tree Vertical Order Traversal
*/

/**
 * Challenge 1: Using only 1 queue to implement it.
 * Challenge 2: Use BFS algorithm to do it.
 * Ref[1]: https://www.jiuzhang.com/problem/binary-tree-level-order-traversal/#tag-lang-cpp
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
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }

        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            int size = Q.size();
            vector<int> level;

            for (int i = 0; i < size; i++)
            {
                TreeNode *head = Q.front();
                Q.pop();
                level.push_back(head->val);
                if (head->left != NULL)
                {
                    Q.push(head->left);
                }
                if (head->right != NULL)
                {
                    Q.push(head->right);
                }
            }

            result.push_back(level);
        }

        return result;
    }
};