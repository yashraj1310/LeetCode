class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) 
    {
        int n = nums.size();
        int maxi = 0;

        for(int i=0;i<n;i++)
        {
            maxi = max(maxi, nums[i][1]);
        }

        vector<int> arr(maxi+1, 0);

        for(int i=0;i<n;i++)
        {
            int start = nums[i][0] - 1;
            int end = nums[i][1] - 1;

            arr[start] += 1;
            arr[end+1] -= 1;
        }

        int preSum = 0;
        int count = 0;

        for(int i=0;i<maxi;i++)
        {
            preSum = preSum + arr[i];

            if(preSum > 0)
                count++;
        }

        return count;
    }
};