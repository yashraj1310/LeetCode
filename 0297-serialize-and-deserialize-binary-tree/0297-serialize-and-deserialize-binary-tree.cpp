/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(root == NULL)
            return "";

        string ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();

            for(int i = 0; i < size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(temp == NULL)
                {
                    ans += "#,";
                    continue;
                }

                ans += to_string(temp->val) + ",";

                if(temp->left)
                    q.push(temp->left);
                else
                    q.push(NULL);

                if(temp->right)
                    q.push(temp->right);
                else
                    q.push(NULL);
            }
        }

        // Remove trailing null markers
        while(ans.size() >= 2 &&
              ans.substr(ans.size() - 2) == "#,")
        {
            ans.erase(ans.size() - 2);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data == "")
            return NULL;

        vector<string> tokens;
        string curr = "";

        for(int j = 0; j < data.size(); j++)
        {
            if(data[j] == ',')
            {
                tokens.push_back(curr);
                curr = "";
            }
            else
                curr += data[j];
        }

        if(curr != "")
            tokens.push_back(curr);

        if(tokens.empty() || tokens[0] == "#")
            return NULL;

        queue<TreeNode*> q;

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        q.push(root);

        int i = 1;

        while(!q.empty() && i < tokens.size())
        {
            int size = q.size();

            for(int j = 0; j < size && i < tokens.size(); j++)
            {
                TreeNode* parent = q.front();
                q.pop();

                // Left child
                if(tokens[i] != "#")
                {
                    TreeNode* leftChild =
                        new TreeNode(stoi(tokens[i]));

                    parent->left = leftChild;
                    q.push(leftChild);
                }
                i++;

                if(i >= tokens.size())
                    break;

                // Right child
                if(tokens[i] != "#")
                {
                    TreeNode* rightChild =
                        new TreeNode(stoi(tokens[i]));

                    parent->right = rightChild;
                    q.push(rightChild);
                }
                i++;
            }
        }

        return root;
    }
};