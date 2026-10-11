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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL)
            return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        int maxi = 1;

        while(!q.empty())
        {
            int size = q.size();
            int first;
            int last;
            int minId = q.front().second;

            for(int i=0;i<size;i++)
            {
                long long currentId = q.front().second - minId;
                TreeNode* temp = q.front().first;
                q.pop();

                if(i==0)
                    first = currentId;

                if(i==size-1)
                    last = currentId;

                if(temp->left)
                    q.push({temp->left, 2*currentId + 1});

                if(temp->right)
                    q.push({temp->right, 2*currentId + 2});
            }
            maxi = max(maxi, last-first+1);
        }

        return maxi;
    }
};