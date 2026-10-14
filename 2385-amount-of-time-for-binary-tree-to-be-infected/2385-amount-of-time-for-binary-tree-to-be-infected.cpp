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
    void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mpp, queue<TreeNode*>& q)
    {
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
                    mpp[temp->left] = temp;
                }

                if(temp->right)
                {
                    q.push(temp->right);
                    mpp[temp->right] = temp;
                }
            }
        }
    }

    TreeNode* findStart(TreeNode* root, int start)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->val == start)
                    return temp;

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }
        }

        return NULL;
    }

    int amountOfTime(TreeNode* root, int start) 
    {
        if(root == NULL)
            return 0;

        unordered_map<TreeNode*, TreeNode*> mpp; //Child --> Parent
        queue<TreeNode*> q;

        findParent(root, mpp, q);
        TreeNode* startNode = findStart(root, start);

        if(startNode == NULL)
            return 0;

        unordered_map<TreeNode*, int> visitedMap;

        q.push(startNode);
        visitedMap[startNode]++;

        int time = 0;

        while(!q.empty())
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
                    if(visitedMap.find(mpp[temp]) == visitedMap.end())
                    {
                        q.push(mpp[temp]);
                        visitedMap[mpp[temp]]++;
                    }
                }
            }
            time++;
        }
        return time-1;
    }
};