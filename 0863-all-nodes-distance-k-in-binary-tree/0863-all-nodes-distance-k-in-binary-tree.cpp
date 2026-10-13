/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void findParent(TreeNode* root, map<TreeNode*, TreeNode*>& mpp, queue<TreeNode*>& q)
    {
        q.push(root);

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left)
            {
                mpp[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                mpp[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        vector<int> ans;

        map<TreeNode*, TreeNode*> mpp; //Child-->Parent
        queue<TreeNode*> q;
        findParent(root, mpp, q);

        q.push(target);
        unordered_map<TreeNode*, int> visitedMap;
        visitedMap[target]++;

        int dist = 0;

        while(dist != k)
        {
            int size = q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left && visitedMap.find(temp->left) == visitedMap.end())
                {
                    q.push(temp->left);
                    visitedMap[temp->left]++;
                }

                if(temp->right && visitedMap.find(temp->right) == visitedMap.end())
                {
                    q.push(temp->right);
                    visitedMap[temp->right]++;
                }

                if(mpp.find(temp) != mpp.end())
                {
                    TreeNode* parent = mpp[temp];

                    if(visitedMap.find(parent) == visitedMap.end())
                    {
                        q.push(parent);
                        visitedMap[parent]++;
                    }
                }
            }
            dist++;
        }
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};