class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        int n = nums.size();    
        vector<string> arr(n);

        for(int i=0;i<n;i++)
        {
            arr[i] = to_string(nums[i]);
        }

        sort(arr.begin(), arr.end(), [](auto &a, auto &b) 
        {
            return a+b > b+a;
        });

        bool allZero = true;

        for(int i=0;i<n;i++)
        {
            if(arr[i] != "0")
            {
                allZero = false;
                break;
            }
        }

        if(allZero)
            return "0";

        string ans = "";

        for(int i=0;i<n;i++)
        {
            ans += arr[i];
        }

        return ans;
    }
};