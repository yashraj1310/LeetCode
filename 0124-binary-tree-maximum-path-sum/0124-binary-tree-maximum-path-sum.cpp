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

    int maxi = INT_MIN;

    int Sum(TreeNode* node)
    {
        if(node == NULL)
            return 0;

        int left = Sum(node->left);
        int right = Sum(node->right);

        maxi = max(maxi, node->val + max(0,left) + max(0,right));

        return node->val + max(0, max(left, right));
    }

    int maxPathSum(TreeNode* root) 
    {
        int sum = Sum(root);
        return maxi;    
    }
};