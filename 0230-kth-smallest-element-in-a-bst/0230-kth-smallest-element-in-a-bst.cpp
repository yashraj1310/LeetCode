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

    void dfs(TreeNode* root, vector<int>& preorder)
    {
        if(root==NULL)
            return;

        preorder.push_back(root->val);
        dfs(root->left, preorder);
        dfs(root->right, preorder);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        vector<int> preorder;
        dfs(root, preorder);   
        int n = preorder.size();

        priority_queue<int> pq;

        for(int i=0;i<n;i++)
        {
            pq.push(preorder[i]);
        }
        int a = n-k;
        while(a--)
        {
            pq.pop();
        }

        return pq.top();
    }
};