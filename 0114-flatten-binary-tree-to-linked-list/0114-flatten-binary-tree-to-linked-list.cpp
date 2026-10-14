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

    void preorder(TreeNode* node, vector<TreeNode*>& arr)
    {
        if(node==NULL)
            return;

        arr.push_back(node);
        preorder(node->left, arr);
        preorder(node->right, arr);
    }

    void flatten(TreeNode* root) 
    {
        if(root==NULL)
            return;

        vector<TreeNode*> arr;
        preorder(root, arr);

        int n = arr.size();

        for(int i=0;i<n-1;i++)
        {
            arr[i]->left=NULL;
            arr[i]->right=arr[i+1];
        }

        arr[n-1]->left = NULL;
        arr[n-1]->right = NULL;
    }
};