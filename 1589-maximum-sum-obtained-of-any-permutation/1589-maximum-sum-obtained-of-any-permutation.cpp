class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) 
    {
        int n = nums.size();
        int m = requests.size();

        const int MOD = 1e9 + 7;
        long long ans = 0;

        vector<long> arr(n+1, 0);

        for(int i=0;i<m;i++)
        {
            int start = requests[i][0];
            int end = requests[i][1];

            arr[start] += 1;
            arr[end+1] += -1;
        }    

        for(int i=1;i<=n;i++)
        {
            arr[i] = arr[i] + arr[i-1];
        }

        arr.pop_back();

        sort(arr.begin(), arr.end());
        sort(nums.begin(), nums.end());

        for(int i=n-1;i>=0;i--)
        {
            ans = ans + (long long)nums[i]*arr[i];
        }

        return ans%MOD;
    }
};