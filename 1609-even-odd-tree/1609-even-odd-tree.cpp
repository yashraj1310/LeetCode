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
    bool isStrictlyIncreasing(queue<TreeNode*>& q)
    {
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            if(q.size() >= 1)
                if(temp->val >= q.front()->val)
                    return false;
        }

        return true;
    }

    bool isStrictlyDecreasing(queue<TreeNode*>& q)
    {
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            if(q.size() >= 1)
                if(temp->val <= q.front()->val)
                    return false;
        }

        return true;
    }

    bool areAllOdd(queue<TreeNode*>& q)
    {
        while(!q.empty())
        {
            if(q.front()->val % 2 == 0)
                return false;

            q.pop();
        }

        return true;
    }

    bool areAllEven(queue<TreeNode*>& q)
    {
        while(!q.empty())
        {
            if(q.front()->val % 2 != 0)
                return false;

            q.pop();
        }

        return true;
    }

    bool isEvenOddTree(TreeNode* root) 
    {
        if(root==NULL)
            return true;

        int level = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            bool flag;
            queue<TreeNode*> tempo = q;
            queue<TreeNode*> temp1 = q;

            if(level%2 == 0)
                flag = isStrictlyIncreasing(tempo) && areAllOdd(temp1);

            else
                flag = isStrictlyDecreasing(tempo) && areAllEven(temp1);

            if(flag==false)
                return false;

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
            level++;
        }    

        return true;
    }
};