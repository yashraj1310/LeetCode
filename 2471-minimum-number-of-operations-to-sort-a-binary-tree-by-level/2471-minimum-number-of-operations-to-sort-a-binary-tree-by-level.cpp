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

    int SelectionSort(vector<int>& arr)
    {
        int count = 0;
        int n = arr.size();

        for(int i=0;i<n;i++)
        {
            int minIdx = i;

            for(int j=i+1;j<n;j++)
            {
                if(arr[j] < arr[minIdx])
                {
                    minIdx = j;
                }
            }

            if(minIdx != i)
            {
                swap(arr[i], arr[minIdx]);
                count++;
            }
        }

        return count;
    }

    //Need to apply selection sort, as it does minimum swaps
    int minimumOperations(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                
                level.push_back(temp->val);

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }
            ans = ans + SelectionSort(level);
        }    

        return ans;
    }
};