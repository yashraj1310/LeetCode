class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) 
    {
        //Hire k workers
        //each session -  choose the worker with the lowest cost from either the first candidates workers or the last candidates workers.

        int n = costs.size();
        long long sum = 0;

        priority_queue<int, vector<int>, greater<int>> minHeap1;
        priority_queue<int, vector<int>, greater<int>> minHeap2;

        int i=0;
        int j=n-1;

        while(i < candidates && i<=j)
            minHeap1.push(costs[i++]);

        while(j >= n-candidates && i<=j)
            minHeap2.push(costs[j--]);

        while(k--)
        {
            int a = minHeap1.empty() ? INT_MAX : minHeap1.top();
            int b = minHeap2.empty() ? INT_MAX : minHeap2.top();

            if(a <= b)
            {
                sum = sum + a;
                minHeap1.pop();

                if(i<=j)
                    minHeap1.push(costs[i++]);
            }
            else{
                sum = sum + b;
                minHeap2.pop();

                if(i<=j)
                    minHeap2.push(costs[j--]);
            }
        }

        return sum;
    }
};