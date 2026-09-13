class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        //Passengers are going from <=From to <To
        //So, include from (from to to-1) & indicate to as the ending point
         
        int n = trips.size();

        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi, trips[i][2]);
        }

        vector<int> arr(maxi + 1, 0);

        int preSum = 0;

        for(int i=0;i<n;i++)
        {
            int passengers = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            arr[from] += passengers;
            arr[to] -= passengers;
        }

        for(int i=0;i<arr.size();i++)
        {
            preSum = preSum + arr[i];
            arr[i] = preSum;

            if(preSum > capacity)
                return false;
        }

        return true;
    }
};