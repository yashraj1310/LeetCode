class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        int n = citations.size();
        int maxi = 0;

        for(int i=1;i<=n;i++)
        {
            int count = 0;
            for(int j=0;j<n;j++)
            {
                if(citations[j] >= i)
                    count++;
            }

            if(count >= i)
                maxi = max(maxi, i);
        }

        return maxi;
    }
};

// Published at least h papers, cited at least h times
