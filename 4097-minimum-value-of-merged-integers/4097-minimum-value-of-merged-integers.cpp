class Solution {
public:
    int minMergedInteger(vector<int>& nums) 
    {
        int n = nums.size();
        int mini = INT_MAX;
        string s;

        for(int i=0;i<n-1;i=i+2)
        {
            s = to_string(nums[i]) + to_string(nums[i+1]);

            mini = min(mini, stoi(s));
        }    

        return mini;
    }
};