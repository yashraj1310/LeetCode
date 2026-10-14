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

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& mpp, int& postIndex, int start, int end)
    {
        //Base Case
        if(start > end)
            return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = mpp[rootVal];

        root->right = solve(inorder, postorder, mpp, postIndex, inIndex+1, end);
        root->left = solve(inorder, postorder, mpp, postIndex, start, inIndex-1);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n = postorder.size();
        int postIndex = n-1;

        unordered_map<int, int> mpp;

        for(int i=0;i<n;i++)
        {
            mpp[inorder[i]] = i;
        }    

        return solve(inorder, postorder, mpp, postIndex, 0, n-1);
    }
};