/** 
 * 177. Convert Sorted Array to Binary Search Tree With Minimal Height
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a sorted (increasing order) array, convert it to create a binary search tree with minimal height.
 * 
 * Clarification
 * There may exist multiple valid solutions, return any of them.
 * 
 * Example
 * Example 1
 * Input: []
 * Output:  {}
 * Explanation: 
 * The binary search tree is null
 * 
 * Example 2:
 * Input: [1,2,3,4,5,6,7]
 * Output:  {4,2,6,1,3,5,7}
 * Explanation:
 * A binary search tree with minimal height.
 *          4
 *        /   \
 *       2     6
 *      / \    / \
 *     1   3  5   7
 * 
 * Related Problems
 * 106. Convert Sorted List to Binary Search Tree
 */

/**
 * Running Time: 1093ms
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
     * @param A: an integer array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A)
    {
        if (A.empty())
            return nullptr;

        return buildTree(A, 0, A.size() - 1);
    }

private:
    TreeNode *buildTree(vector<int> &A, int low, int high)
    {
        if (low > high)
            return nullptr;

        int mid = low + (high - low) / 2;

        TreeNode *root = new TreeNode(A[mid]);
        root->left = buildTree(A, low, mid - 1);
        root->right = buildTree(A, mid + 1, high);

        return root;
    }
};