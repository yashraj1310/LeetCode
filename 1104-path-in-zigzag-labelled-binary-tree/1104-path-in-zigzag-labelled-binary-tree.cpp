class Solution {
public:
    vector<int> pathInZigZagTree(int label) 
    {
        vector<int> ans;

        // int level = (bit_width(label) - 1) + 1;
        int level = -1;
        ans.push_back(label);

        while(level != 1)
        {
            level = bit_width((unsigned int)label);

            if(level == 1)
                break;

            long long mini = pow(2, (level-1));
            long long maxi = pow(2, (level)) - 1;

            long long mirror = mini + maxi - label;
            int parent = mirror/2;
            label = parent;
            ans.push_back(label);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};