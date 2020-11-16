/** 
 * 1311. Lowest Common Ancestor of a Binary Search Tree
 * Difficulty
 * Easy
 * 
 * Description
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 * According to the definition of LCA on Wikipedia:
 * “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
 * (where we allow a node to be a descendant of itself).”
 * Given binary search tree: root = {6,2,8,0,4,7,9,#,#,3,5}
 * 
 * Clarification
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the BST.
 *
 * Example
 * Example 1
 * Input:
 * {6,2,8,0,4,7,9,#,#,3,5}
 * 2
 * 8
 * Output:
 * 6
 * Explanation: 
 * The LCA of nodes 2 and 8 is 6.
 * 
 * Example 2
 * Input:
 * {6,2,8,0,4,7,9,#,#,3,5}
 * 2
 * 4
 * Output:
 * 2
 * Explanation: 
 * The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
 * 
 * Related Problems
 * 88. Lowest Common Ancestor of a Binary Tree
 * 474. Lowest Common Ancestor II
 * 578. Lowest Common Ancestor III
 * */

/**
 * Divide and conquer
 * Running Time: 51ms
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
     * @param root: root of the tree
     * @param p: the node p
     * @param q: the node q
     * @return: find the LCA of p and q
     */
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		// root is the target p or q
		if (root == p || root == q)
		{
			return root;
		}
		// p and q are in the left sub-tree of root
		if (p->val < root->val && q->val < root->val)
		{
			return lowestCommonAncestor(root->left, p, q);
		}
		// p and q are in the right sub-tree of root
		if (p->val > root->val && q->val > root->val)
		{
			return lowestCommonAncestor(root->right, p, q);
		}
		// p and q are in the different sub-trees of root
		return root;
	}
};