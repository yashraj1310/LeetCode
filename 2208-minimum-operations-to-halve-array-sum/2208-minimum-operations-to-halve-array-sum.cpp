class Solution {
public:
    int halveArray(vector<int>& nums) 
    {
        int n = nums.size();
        priority_queue<double> maxHeap;

        double sum = 0;

        for(int i=0;i<n;i++)
        {
            sum = sum + nums[i];
            maxHeap.push(nums[i]);
        } 

        double half = sum/2.0;
        int count = 0;

        while(sum > half)
        {
            double x = maxHeap.top();
            maxHeap.pop();
            sum = sum - x;

            maxHeap.push(x/2.0);
            sum = sum + x/2.0;
            count++;
        }

        return count;
    }
};