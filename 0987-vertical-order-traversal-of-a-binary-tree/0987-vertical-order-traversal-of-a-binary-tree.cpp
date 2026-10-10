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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> ans;

        if(root==NULL)
            return ans;

        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mpp; //each vertical -> level -> Same vertical and same level can have multiple nodes 

        q.push({root,{0, 0}});

        while(!q.empty())
        {
            int x = q.front().second.first; // vertical
            int y = q.front().second.second; // level
            TreeNode *temp = q.front().first;
            q.pop();

            mpp[x][y].insert(temp->val);

            if(temp->left)
                q.push({temp->left, {x-1, y+1}});

            if(temp->right)
                q.push({temp->right, {x+1, y+1}});
        } 

        for (auto it : mpp)           // Vertical columns
        {
            vector<int> col;

            for (auto p : it.second)  // Levels
            {
                for (auto node : p.second) // Node values
                {
                    col.push_back(node);
                }
            }

            ans.push_back(col);
        }

        return ans;
    }
};