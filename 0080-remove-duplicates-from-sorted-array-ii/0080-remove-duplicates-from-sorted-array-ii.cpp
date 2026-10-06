class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        map<int, int> mpp;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }

        int i=0;

        int a = 0;

        for(auto it : mpp)
        {
            if(it.second > 2)
            {
                a=1;
                break;
            }
        }

        if(a==0)
            return n;

        for(auto it : mpp)
        {
            if(it.second >= 2)
            {
                nums[i] = it.first;
                
                if(i!=n-1)
                    i++;

                nums[i] = it.first;

                if(i!=n-1)
                    i++;
            }
            else{
                nums[i] = it.first;
                if(i!=n-1)
                    i++;
            }
        }
        return i;
    }
};