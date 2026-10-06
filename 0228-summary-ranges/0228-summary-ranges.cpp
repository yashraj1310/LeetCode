class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> ans;
        int n = nums.size();

        if(n == 0)
            return ans;

        int start = 0;

        for(int i = 1; i < n; i++)
        {
            if(nums[i] != nums[i-1] + 1)
            {
                if(start == i-1)
                {
                    ans.push_back(to_string(nums[i-1]));
                }
                else
                {
                    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[i-1]));
                }

                start = i;
            }
            else
            {
                while(i < n && nums[i] == nums[i-1] + 1)
                {
                    i++;
                }

                if(start == i-1)
                {
                    ans.push_back(to_string(nums[start]));
                }
                else
                {
                    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[i-1]));
                }

                start = i;
                // i--;
            }
        }

        if(start == n-1)
        {
            ans.push_back(to_string(nums[start]));
        }
        else if(start < n)
        {
            ans.push_back(to_string(nums[start]) + "->" + to_string(nums[n-1]));
        }

        return ans;
    }
};