/** 
 * 7. Serialize and Deserialize Binary Tree
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Design an algorithm and write code to serialize and deserialize a binary tree. 
 * Writing the tree to a file is called 'serialization',
 * and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.
 * 
 * Clarification
 * There is no limit of how you deserialize or serialize a binary tree. 
 * LintCode will take your output of serialize as the input of deserialize. 
 * It won't check the result of serialize.
 * Our data serialization use BFS traversal. 
 * This is just for when you got Wrong Answer and want to debug the input.
 * You can use other method to do serialization and deserialization.
 * 
 * 
 * Example
 * Example 1
 * Input：
 * {3,9,20,#,#,15,7}
 * Output：{3,9,20,#,#,15,7}
 * Explanation：
 * Binary tree {3,9,20,#,#,15,7}, denote the following structure:
 * 	  3
 * 	 / \
 * 	9  20
 * 	  /  \
 * 	 15   7
 * it will be serialized {3,9,20,#,#,15,7}
 * 
 * Example 2
 * Input：{1,2,3}
 * Output：{1,2,3}
 * Explanation：
 * Binary tree {1,2,3}, denote the following structure:
 *    1
 *   / \
 *  2   3
 * it will be serialized {1,2,3}
 *
 * Related Problems
 * 1108. Find Duplicate Subtrees
 * 659. Encode and Decode Strings
 * 527. Trie Serialization
 * 232. Tiny URL
 * 11. Search Range in Binary Search Tree
 * */

/**  
 * BFS in serialization
 * Ref: https://www.jiuzhang.com/problem/serialize-and-deserialize-binary-tree/
 * Running Time:  299ms
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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root)
    {
        if (root == NULL)
        {
            return "{}";
        }
        vector<TreeNode *> q;
        q.push_back(root);
        for (int i = 0; i != q.size(); i++)
        {
            TreeNode *node = q[i];
            if (node == NULL)
            {
                continue;
            }
            q.push_back(node->left);
            q.push_back(node->right);
        }
        while (q[q.size() - 1] == NULL)
        {
            q.pop_back();
        }
        string sb = "";
        sb += "{";
        sb += to_string(q[0]->val);
        for (int i = 1; i < q.size(); i++)
        {
            if (q[i] == NULL)
            {
                sb += (",#");
            }
            else
            {
                sb += ",";
                sb += to_string(q[i]->val);
            }
        }
        sb += "}";
        return sb;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string &data)
    {
        if (data == "{}")
            return NULL;
        vector<string> vals = split(data.substr(1, data.size() - 2), ",");
        TreeNode *root = new TreeNode(atoi(vals[0].c_str()));
        queue<TreeNode *> Q;
        Q.push(root);
        bool isLeftChild = true;
        for (int i = 1; i != vals.size(); i++)
        {
            if (vals[i] != "#")
            {
                TreeNode *node = new TreeNode(atoi(vals[i].c_str()));
                if (isLeftChild)
                    Q.front()->left = node;
                else
                    Q.front()->right = node;
                Q.push(node);
            }
            if (!isLeftChild)
            {
                Q.pop();
            }
            isLeftChild = !isLeftChild;
        }
        return root;
    }

private:
    vector<string> split(const string &str, string delim)
    {
        vector<string> results;
        int lastIndex = 0, index;
        while ((index = str.find(delim, lastIndex)) != string::npos)
        {
            results.push_back(str.substr(lastIndex, index - lastIndex));
            lastIndex = index + delim.length();
        }
        if (lastIndex != str.length())
        {
            results.push_back(str.substr(lastIndex, str.length() - lastIndex));
        }
        return results;
    }
};