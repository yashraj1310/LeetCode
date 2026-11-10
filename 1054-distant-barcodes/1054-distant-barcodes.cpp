class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;

        for(auto it : mpp)
        {
            pq.push({it.second, it.first});
        }

        int i=0;

        while(pq.size() >= 2)
        {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();

            if(i < n)
                nums[i] = a.second;
            a.first--;
            i++;

            if(i < n)
                nums[i] = b.second;
            b.first--;
            i++;

            if(a.first > 0)
                pq.push(a);

            if(b.first > 0)
                pq.push(b);
        }

        if(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            if(i<n)
                nums[i] = it.second;
        }

        return nums;
    }
};