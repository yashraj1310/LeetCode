class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        vector<int> rows(m, 0);
        vector<int> cols(n, 0);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    rows[i]++;
                    cols[j]++;
                }
            }
        } 

        for(int i=0;i<m;i++)
        {
            cout << rows[i] << " ";
        }
        cout << endl;
        for(int j=0;j<n;j++)
        {
            cout << cols[j] << " ";
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    if(rows[i]!=1 || cols[j]!=1)
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};