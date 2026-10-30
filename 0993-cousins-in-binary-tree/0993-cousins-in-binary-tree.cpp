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

    bool isCousins(TreeNode* root, int x, int y) 
    {
        unordered_map<int, pair<int, int>> mpp;
        int depth = 1;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            int size = q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left)
                {
                    q.push(temp->left);
                    mpp[temp->left->val] = {temp->val, depth};
                }
                if(temp->right)
                {
                    q.push(temp->right);
                    mpp[temp->right->val] = {temp->val, depth};
                }
            }
            depth++;
        }

        if(mpp[x].first != mpp[y].first && mpp[x].second == mpp[y].second)
            return true;

        return false;
    }
};