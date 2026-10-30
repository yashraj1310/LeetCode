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

    void dfs(TreeNode* root, vector<int>& inorder)
    {
        if(root==NULL)
            return;

        dfs(root->left, inorder);
        inorder.push_back(root->val);
        dfs(root->right, inorder);

    }

    void preorder(TreeNode* root, TreeNode* &temp, int value)
    {
        if(root==NULL)
            return;

        if(root->val == value)
            temp = root;

        preorder(root->left, temp, value);
        preorder(root->right, temp, value);
    }

    void recoverTree(TreeNode* root) 
    {
        vector<int> inorder;    
        dfs(root, inorder);
        vector<int> sorted;
        sorted = inorder;
        sort(sorted.begin(), sorted.end());

        int n = inorder.size();
        int a, b;
        bool first = false, second = false;

        for(int i=0;i<n;i++)
        {
            if(!first && inorder[i] != sorted[i])
            {
                a = inorder[i];
                first = true;
                continue;
            }
            if(!second && inorder[i] != sorted[i])
            {
                b = inorder[i];
                second = true;
                continue;
            }
        }

        TreeNode* temp1;
        TreeNode* temp2;
        
        preorder(root, temp1, a);
        preorder(root, temp2, b);

        temp1->val = b;
        temp2->val = a;
    }
};