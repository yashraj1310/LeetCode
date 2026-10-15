class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int mini = nums[0];
        int maxi = nums[0];

        for(int i=0;i<n;i++)
        {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        return (long long)(maxi-mini)*k;
    }
};