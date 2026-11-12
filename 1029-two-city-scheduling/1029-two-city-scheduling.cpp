class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        int n = costs.size();  

        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });

        int cost = 0;

        for(int i=0;i<n/2;i++)
        {
            cost = cost + costs[i][0];
        }

        for(int i=n/2;i<n;i++)
        {
            cost = cost + costs[i][1];
        }

        return cost;
    }
};