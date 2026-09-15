class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) 
    {
        int size = nums.size();

        if(size==1)
        {
            if(nums[0] == 0)
                n--;

            return n <= 0;
        }

        if(size==2)
        {
            if(nums[0] == 0 && nums[1] == 0)
                n--;

            return n <= 0;
        }

        for(int i=0;i<size;i++)
        {
            if(nums[i]==0)
            {
                if(i==0 && nums[i+1]==0)
                {
                    nums[i] = 1;
                    n--;
                }
                else if(i!=0 && i!=size-1 && nums[i-1]==0 && nums[i+1]==0)
                {
                    nums[i] = 1;
                    n--;
                }
                else if(i==size-1 && nums[i-1]==0)
                {
                    nums[i] = 1;
                    n--;
                }
            }

            if(n <= 0)
                return true;
        }

        return false;
    }
};