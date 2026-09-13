class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
    {
        int size = bookings.size();
        vector<int> arr(n+1, 0);

        //Marksing the starting & ending of each range

        for(int i=0;i<size;i++)
        {
            int first = bookings[i][0]-1;
            int last = bookings[i][1]-1;
            int seats = bookings[i][2];

            arr[first] += seats;
            arr[last + 1] -= seats;
        }

        //Traversing
        int preSum = 0;

        for(int i=0;i<=n;i++)
        {
            preSum = preSum + arr[i];
            arr[i] = preSum;
        }

        arr.pop_back();

        return arr;
        
    }
};