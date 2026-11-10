class Solution {
public:

    const int MOD = 1e9 + 7;

    int maximumProduct(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int zeros = 0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                zeros++;
        }    

        if(zeros > k)
            return 0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                nums[i]++;
                k--;
            }
        } 

        long long ans = 1;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }

        while(k--)
        {
            auto it = pq.top();
            pq.pop();
            it++;
            pq.push(it);
        }

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            ans = (ans % MOD)*(it % MOD);
        }

        return ans%MOD;
    }
};