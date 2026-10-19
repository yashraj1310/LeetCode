/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void dfs(TreeNode* node)
    {
        if(node == NULL)
            return;

        TreeNode* leftNode = node->left;
        TreeNode* rightNode = node->right;

        dfs(node->left);
        dfs(node->right);

        node->left = rightNode;
        node->right = leftNode;
    }

    TreeNode* invertTree(TreeNode* root) 
    {
        dfs(root);
        return root;    
    }
};