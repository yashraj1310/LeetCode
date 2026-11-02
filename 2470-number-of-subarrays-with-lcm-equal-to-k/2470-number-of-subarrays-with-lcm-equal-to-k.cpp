class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) 
    {
        int n = nums.size();
        long long LCM = 1;
        int count = 0;

        for(int i=0;i<n;i++)
        {
            for(int j = i;j<n;j++)
            {
                LCM = lcm(LCM, nums[j]);
                
                if(LCM > k)
                    break;

                if(LCM == k)
                    count++;
            }
            LCM = 1;
        }

        return count;
    }
};