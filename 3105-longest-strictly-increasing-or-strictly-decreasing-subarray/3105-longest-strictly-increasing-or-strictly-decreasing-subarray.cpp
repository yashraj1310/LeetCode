class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        int maxi1=1, count1=1;
        int maxi2=1, count2=1;
        int n = nums.size();

        for(int i=1;i<n;i++)
        {
            if(nums[i] > nums[i-1])
            {
                count1++;
                maxi1 = max(maxi1, count1);
                count2=1;
            }
            else if(nums[i] < nums[i-1])
            {
                count2++;
                maxi2 = max(maxi2, count2);
                count1=1;
            }
            else{
                count1=1;
                count2=1;
            }
        }    

        return max(maxi1, maxi2);
    }
};