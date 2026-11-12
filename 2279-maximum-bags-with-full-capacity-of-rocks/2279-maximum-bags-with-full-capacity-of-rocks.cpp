class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        int n = capacity.size();
        vector<int> arr(n);

        for(int i=0;i<n;i++)
        {
            arr[i] = capacity[i] - rocks[i];
        }

        sort(arr.begin(), arr.end());
        int count = 0;

        for(int i=0;i<n;i++)
        {
            if(arr[i] <= additionalRocks)
            {
                count++;
                additionalRocks-=arr[i];
            }
        }

        return count;
    }
};