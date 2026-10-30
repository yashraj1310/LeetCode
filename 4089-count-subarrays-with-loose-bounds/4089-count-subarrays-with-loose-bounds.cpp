class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        long long count = 0;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i] > maxK || nums[i] < minK)
                nums[i] = -1;
        }

        vector<int> range;
        int length = 0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==-1)
            {
                range.push_back(length);
                length=0;
            }
            else{
                length++;
            }
        }

        range.push_back(length);
        int m = range.size();

        for(int i=0;i<m;i++)
        {
            count = count + ((long long)range[i]*(range[i]+1))/2;
        }

        return count;
    }
};