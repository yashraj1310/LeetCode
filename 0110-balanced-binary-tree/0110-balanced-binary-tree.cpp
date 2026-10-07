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
    int Height(TreeNode *node)
    {
        if(node == NULL)
            return 0;

        int left = Height(node->left);
        int right = Height(node->right);

        if(left==-1)
            return -1;

        if(right==-1)
            return -1;

        if(abs(left-right) > 1)
            return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) 
    {
        return Height(root)!=-1;
    }
};