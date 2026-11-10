class Solution {
public:
    int minimumDeviation(vector<int>& nums) 
    {
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i] % 2 == 1)
                nums[i] = nums[i]*2;
        }    

        priority_queue<int> pq;
        int ans = INT_MAX, mini = INT_MAX, maxi = INT_MIN;

        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
            mini = min(mini, nums[i]);
        }

        while(pq.top()%2==0)
        {
            auto it = pq.top();
            pq.pop();
            maxi = it;
            ans = min(ans, maxi-mini);
            it = it/2;
            mini = min(mini, it);
            pq.push(it);
        }
        if (!pq.empty()) 
        {
            ans = min(ans, pq.top() - mini);
        }
        return ans;
    }
};