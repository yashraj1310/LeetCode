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

    void dfs(TreeNode* root, int sum, int& total)
    {
        if(root==NULL)
            return;

        sum = sum*10 + root->val;

        if(root->left==NULL && root->right==NULL)
        {
            total = total + sum;
            return;
        }

        dfs(root->left, sum, total);
        dfs(root->right, sum, total);
    }

    int sumNumbers(TreeNode* root) 
    {
        if(root==NULL)
            return 0;

        int ans = 0;
        dfs(root, 0, ans);

        return ans;

    }
};