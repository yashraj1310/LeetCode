class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        int n = arr.size();
        unordered_map<int, int> mpp;

        for(int i=0;i<n;i++)
        {
            mpp[arr[i]]++;
        }    

        priority_queue<int, vector<int>, greater<int>> pq; // only freq

        for(auto it : mpp)
        {
            pq.push(it.second);
        }

        while(k--)
        {
            auto it = pq.top();
            pq.pop();

            it--;
            if(it > 0)
                pq.push(it);
        }

        return pq.size();

    }
};