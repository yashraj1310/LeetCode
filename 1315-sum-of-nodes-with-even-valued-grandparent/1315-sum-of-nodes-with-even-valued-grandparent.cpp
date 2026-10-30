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
    int sumEvenGrandparent(TreeNode* root) 
    {
        int ans = 0;
        queue<vector<TreeNode*>> q; //node, parent, grandparent
        q.push({root, NULL, NULL});

        while(!q.empty())
        {
            TreeNode* node = q.front()[0];
            TreeNode* parent = q.front()[1];
            TreeNode* grandparent = q.front()[2];
            q.pop();

            if(grandparent!=NULL && grandparent->val%2==0)
                ans = ans + node->val;

            if(node->left)
                q.push({node->left, node, parent});

            if(node->right)
                q.push({node->right, node, parent});
        }

        return ans;
    }
};