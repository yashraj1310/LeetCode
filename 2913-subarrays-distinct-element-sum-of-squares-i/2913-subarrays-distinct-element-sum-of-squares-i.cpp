class Solution {
public:
    int sumCounts(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mpp;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                mpp[nums[j]]++;
                sum = sum + mpp.size()*mpp.size();
            }
            mpp.clear();
        }    

        return sum;
    }
};