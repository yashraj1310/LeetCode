class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int ans= 0;
        int size=0;

        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }    

        for(auto it : mpp)
        {
            if(it.second==1)
                return -1;

            if(it.second%3==0)
            {
                ans = ans + it.second/3;
                size++;
            }
            else{
                ans = ans + it.second/3;
                ans++;
                size++;
            }
        }

        if(mpp.size() == size)
            return ans;

        return -1;
    }
};