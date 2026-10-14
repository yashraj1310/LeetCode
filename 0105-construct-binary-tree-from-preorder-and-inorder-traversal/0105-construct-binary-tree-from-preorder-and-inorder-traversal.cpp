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

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& mpp, int& preIndex, int start, int end) // start and end is for left subtree and right subtree of inorder, preIndex is used for preorder index
    {
        if(start > end)
            return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = mpp[rootVal];

        root->left = solve(preorder, inorder, mpp, preIndex, start, inIndex-1);
        root->right = solve(preorder, inorder, mpp, preIndex, inIndex+1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int preIndex = 0;

        unordered_map<int, int> mpp;
        int n = inorder.size();

        for(int i=0;i<n;i++)
        {
            mpp[inorder[i]] = i;
        }    

        return solve(preorder, inorder, mpp, preIndex, 0, n-1);
    }
};