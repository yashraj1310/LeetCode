class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        int n = gifts.size();
        priority_queue<int> pq;

        for(int i=0;i<n;i++)
            pq.push(gifts[i]);

        while(k--)
        {
            auto it = pq.top();
            pq.pop();

            it = (int)sqrt(it);
            pq.push(it);
        }

        long long ans = 0;

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            ans = ans + it;
        }

        return ans;
    }
};