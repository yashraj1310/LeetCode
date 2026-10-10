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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;
            
        int a = 1;

        // if a==1 --> L to R
        // if a==0 --> R to L

        deque<TreeNode*> dq; 
        dq.push_back(root);

        while(!dq.empty())
        {
            int size = dq.size();

            vector<int> level;

            for(int i=0;i<size;i++)
            {
                if(a==1)
                {
                    TreeNode* temp = dq.front();
                    dq.pop_front();

                    if(temp->left)
                        dq.push_back(temp->left);

                    if(temp->right)
                        dq.push_back(temp->right);

                    level.push_back(temp->val);
                }
                if(a==0)
                {
                    TreeNode* temp = dq.back();
                    dq.pop_back();

                    if(temp->right)
                        dq.push_front(temp->right);

                    if(temp->left)
                        dq.push_front(temp->left);

                    level.push_back(temp->val);
                }
            }
            ans.push_back(level);
            if(a==0)
                a=1;
            else
                a=0;
        }

        return ans;
    }
};