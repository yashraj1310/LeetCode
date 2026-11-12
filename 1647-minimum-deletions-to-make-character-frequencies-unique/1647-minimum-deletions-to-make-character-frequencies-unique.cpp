class Solution {
public:
    int minDeletions(string s) 
    {
        int n = s.length();
        unordered_map<char, int> mpp;
        int count = 0;

        for(int i=0;i<n;i++)
        {
            mpp[s[i]]++;
        }

        priority_queue<int> pq;

        for(auto it : mpp)
        {
            pq.push(it.second);
        }

        while(pq.size() >= 2)
        {
            auto first = pq.top();
            pq.pop();
            auto second = pq.top();

            if(first == second)
            {
                first--;
                count++;
                if(first > 0)
                    pq.push(first);
            }
        }

        return count;
    }
};