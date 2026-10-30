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

    bool isSymmetric(TreeNode* root) 
    {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});

        while(!q.empty())
        {
            TreeNode* first = q.front().first;
            TreeNode* second = q.front().second;
            q.pop();

            if(!first && !second)
                continue;

            if(!first || !second || first->val != second->val)
                return false;

            q.push({first->left, second->right});
            q.push({first->right, second->left});
        }

        return true;
    }
};