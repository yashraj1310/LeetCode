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

    bool isUnivalTree(TreeNode* root) 
    {
        if(root==NULL)
            return true;

        if(root->left!=NULL)
        {
            if(root->val != root->left->val || !isUnivalTree(root->left))
                return false;
        }    

        if(root->right!=NULL)
        {
            if(root->val != root->right->val || !isUnivalTree(root->right))
                return false;
        }

        return true;
    }
};