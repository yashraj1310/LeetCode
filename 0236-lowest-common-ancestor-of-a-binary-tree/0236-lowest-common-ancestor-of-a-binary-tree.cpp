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

    bool findTreePath(TreeNode* node, vector<TreeNode*>& arr, int x)
    {
        if(node==NULL)
            return false;

        arr.push_back(node);

        if(node->val == x)
            return true;

        if(findTreePath(node->left, arr, x) || findTreePath(node->right, arr, x))
            return true;

        arr.pop_back();

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == NULL)
            return NULL;

        if(root->left == NULL && root->right == NULL)
            return root;
            
        vector<TreeNode* > temp1, temp2;
        bool a = findTreePath(root, temp1, p->val);
        bool b = findTreePath(root, temp2, q->val);

        int size1 = temp1.size();
        int size2 = temp2.size();

        for(int i=size1-1;i>=0;i--)
        {
            for(int j=size2-1;j>=0;j--)
            {
                if(temp1[i]->val==temp2[j]->val)
                    return temp1[i];
            }
        }    

        return NULL;
    }
};