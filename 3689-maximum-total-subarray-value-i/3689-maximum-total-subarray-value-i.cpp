class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long ans = 0;

        while(k--)
        {
            ans = ans + nums[n-1]-nums[0];
        }    

        return ans;
    }
};