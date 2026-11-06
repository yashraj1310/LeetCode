class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        int n = nums.size();
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        int operation = 0;

        for(int i=0;i<n;i++)
            minHeap.push(nums[i]);

        while(minHeap.top() < k)
        {
            long long x = minHeap.top();
            minHeap.pop();

            long long y = minHeap.top();
            minHeap.pop();

            long long temp = (long long)x*2 + (long long)y;

            minHeap.push(temp);
            operation++;
        }    

        return operation;
    }
};