class Solution {
public:
    bool isStaircase(int val, int len, unordered_map<int, int>& mpp, vector<int>& arr) 
    {
        if (mpp[val] == 0) 
        {
            arr.push_back(val);
        }
        mpp[val]++;

        int k = arr.size();
        if (len != k * (k + 1) / 2) 
        {
            return false;
        }

        for (int i = 0; i < k; i++) 
        {
            if (mpp[arr[i]] != i + 1) 
            {
                return false;
            }
        }
        return true;
    }

    int countStaircase(vector<int>& nums) 
    {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> mpp;
        vector<int> arr;

        for (int i = 0; i < n; i++) 
        {
            mpp.clear();
            arr.clear();

            for (int j = i; j < n; j++) 
            {
                int len = j - i + 1;
                if (isStaircase(nums[j], len, mpp, arr)) 
                {
                    count++;
                }
            }
        }

        return count;
    }
};