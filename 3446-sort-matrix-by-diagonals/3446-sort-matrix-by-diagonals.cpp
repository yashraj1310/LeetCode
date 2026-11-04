class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        unordered_map<int, vector<int>> mpp; //(row-col) --> vector

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mpp[i-j].push_back(grid[i][j]);
            }
        }    

        for(auto &it : mpp)
        {
            sort(it.second.begin(), it.second.end());
        }

        for(auto &it : mpp)
        {
            if(it.first >= 0)
                reverse(it.second.begin(), it.second.end());
        }

        //Reconstructing the original matrix :

        unordered_map<int, int> idx; //for indexing across each element of sorted vector

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                grid[i][j] = mpp[i-j][idx[i-j]];
                idx[i-j]++;
            }
        }

        return grid;
    }
};