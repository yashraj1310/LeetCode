class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& nums, int extraStudents) 
    {
        int classes = nums.size();
        priority_queue<pair<double, pair<int, int>>> pq; //[0] = Max delta (p+1)/(t+1) - p/t
        //[1] = p
        //[2] = t

        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            pq.push({((double)(nums[i][0] + 1) / (nums[i][1] + 1)) - ((double)nums[i][0] / nums[i][1]), {nums[i][0], nums[i][1]}});
        }
        double ans = 0;

        while(extraStudents--)
        {
            auto it = pq.top();
            pq.pop();
            double delta = it.first;
            int p = it.second.first;
            int t = it.second.second;

            pq.push({((double)(p + 2) / (t + 2)) - ((double)(p + 1) / (t + 1)), {p + 1, t + 1}});
        }

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int p = it.second.first;
            int t = it.second.second;

            ans = ans + (double)p/t;
        }

        ans = ans/n;

        return ans;
    }
};