class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_set<int> primes;

        for(int i=0;i<n;i++)
        {
            for(int j=2;j*j<=nums[i];j++)
            {
                if(nums[i]%j==0)
                {
                    primes.insert(j);

                    while(nums[i]%j==0)
                        nums[i] = nums[i]/j;
                }
            }
            if(nums[i]!=1)
                primes.insert(nums[i]);
        }

        return primes.size();
    }
};