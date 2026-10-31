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
class CBTInserter {
public:
    TreeNode* root;
    queue<TreeNode*> candidates;

    CBTInserter(TreeNode* root) //Constructor
    {
        this->root = root;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            int size = q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left==NULL && temp->right==NULL)
                    candidates.push(temp);

                else if(!temp->left || !temp->right)
                    candidates.push(temp);

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }
        }
    }
    
    int insert(int val) 
    {
        TreeNode* temp = candidates.front();
        TreeNode* newnode = new TreeNode(val);

        if(temp->left==NULL)
            temp->left = newnode;

        else{
            temp->right = newnode;
            candidates.pop();
        }

        candidates.push(newnode);

        return temp->val;
    }
    
    TreeNode* get_root() 
    {
        return root;    
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */