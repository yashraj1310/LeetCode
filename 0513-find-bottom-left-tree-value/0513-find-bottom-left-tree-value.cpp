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

    int findHeight(TreeNode* root)
    {
        if(root==NULL)
            return 0;

        int left = findHeight(root->left);
        int right = findHeight(root->right);

        return 1 + max(left, right);
    }

    int findBottomLeftValue(TreeNode* root) 
    {
        int height = findHeight(root);
        queue<TreeNode*> q;

        q.push(root);
        int curr = 1;

        while(!q.empty())
        {
            if(curr==height)
                return q.front()->val;

            int size = q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }

            curr++;
        }
        return 0;
    }
};