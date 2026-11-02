class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int GCD = 0;
        int count = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                GCD = gcd(GCD, nums[j]);
                if(GCD == k)
                    count++;
            }
            GCD = 0;
        }    

        return count;
    }
};