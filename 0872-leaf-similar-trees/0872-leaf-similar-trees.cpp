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

    void dfs(TreeNode* root, string& ans1)
    {
        if(root==NULL)
            return;

        if(root->left==NULL && root->right==NULL)
            ans1.push_back(root->val + '0');

        dfs(root->left, ans1);
        dfs(root->right, ans1);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        string ans1, ans2;
        dfs(root1, ans1);
        cout << ans1 << endl;
        dfs(root2, ans2);
        cout << ans2;    

        if(ans1==ans2)
            return true;

        return false;
    }
};