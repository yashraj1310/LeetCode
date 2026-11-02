class Solution {
public:

    bool isPrime(int x)
    {
        int count = 0;

        for(int i=1;i*i<=x;i++)
        {
            if(x%i==0)
            {
                count++;

                if(i != x/i)
                    count++;
            }
        }

        if(count==2)
            return true;

        return false;
    }

    int maximumPrimeDifference(vector<int>& nums) 
    {
       int n = nums.size();

       for(int i=0;i<n;i++)
       {
            if(isPrime(nums[i]))
                nums[i] = 1;

            else
                nums[i] = 0;
       } 
       int i=0;
       int j = n-1;

       while(i<n && nums[i] != 1)
            i++;

        while(j>=0 && nums[j] != 1)
            j--;

        return j-i;
    }
};