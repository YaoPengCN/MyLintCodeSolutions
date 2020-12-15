/** 
 * 11. Search Range in Binary Search Tree
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given a binary search tree and a range [k1, k2], return node values within a given range in ascending order. 
 * 
 * Example
 * Example 1
 * Input：{5},6,10
 * Output：[]
 *         5
 * it will be serialized {5}
 * No number between 6 and 10
 * 
 * Example 2
 * Input：{20,8,22,4,12},10,22
 * Output：[12,20,22]
 * Explanation：
 *         20
 *        /  \
 *       8   22
 *      / \
 *     4   12
 * it will be serialized {20,8,22,4,12}
 * [12,20,22] between 10 and 22
 *
 * Related Problems
 * 665. Range Sum Query 2D - Immutable
 * 14. First Position of Target
 * 7. Serialize and Deserialize Binary Tree
 * */

/**  
 * The in-order traversal of a binary search tree returns a sorted array.
 * Ref: https://www.jiuzhang.com/problem/search-range-in-binary-search-tree/#tag-lang-cpp
 * Running Time:  50ms
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
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode *root, int k1, int k2)
    {
        vector<int> result;
        travel(root, k1, k2, result);
        return result;
    }

private:
    void travel(TreeNode *root, int k1, int k2, vector<int> &result)
    {
        if (root == nullptr)
        {
            return;
        }

        // Pruning. If the current node val <= k1, do not visit the left tree.
        if (root->val > k1)
        {
            travel(root->left, k1, k2, result);
        }
        if (root->val >= k1 && root->val <= k2)
        {
            result.push_back(root->val);
        }

        // Pruning. If the current node val >= k2, do not visit the right tree.
        if (root->val < k2)
        {
            travel(root->right, k1, k2, result);
        }
    }
};