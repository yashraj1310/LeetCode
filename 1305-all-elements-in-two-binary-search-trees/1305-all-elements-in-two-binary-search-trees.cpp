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

    void inorder(TreeNode* root, vector<int>& ans)
    {
        if(root==NULL)
            return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> ans1, ans2, ans;
        inorder(root1, ans1);
        inorder(root2, ans2);
        int m = ans1.size();
        int n = ans2.size();
        int i = 0;
        int j = 0;

        while(i < m && j < n)
        {
            if(ans1[i] < ans2[j])
            {
                ans.push_back(ans1[i]);
                i++;
            }
            else if(ans1[i] > ans2[j])
            {
                ans.push_back(ans2[j]);
                j++;
            }
            else{
                ans.push_back(ans1[i]);
                i++;
            }
        }

        while(i<m)
        {
            ans.push_back(ans1[i]);
                i++;
        }
        while(j<n)
        {
            ans.push_back(ans2[j]);
                j++;
        }

        return ans;
    }
};