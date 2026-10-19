
class Solution {
public:

    bool dfs(TreeNode* root, int sum)
    {
        if(root == NULL)
            return false;

        sum = sum - root->val;

        if(root->left == NULL && root->right == NULL)
            return sum == 0;

        bool left = dfs(root->left, sum);
        bool right = dfs(root->right, sum);

        return left || right;
    }

    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if(root == NULL)
            return false;

        return dfs(root, targetSum);
    }
};
