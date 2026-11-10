class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        int n = score.size();
        vector<string> ans(n);

        priority_queue<pair<int, int>> pq;

        for(int i=0;i<n;i++)
            pq.push({score[i], i});

        pair<int, int> it;

        if(n>=3)
        {
            it = pq.top();
            pq.pop();

            ans[it.second] = "Gold Medal";

            it = pq.top();
            pq.pop();
            ans[it.second] = "Silver Medal";

            it = pq.top();
            pq.pop();
            ans[it.second] = "Bronze Medal";
        }  
        else if(n==2)
        {
            it = pq.top();
            pq.pop();

            ans[it.second] = "Gold Medal";

            it = pq.top();
            pq.pop();
            ans[it.second] = "Silver Medal";
        }
        else if(n==1)
        {
            it = pq.top();
            pq.pop();

            ans[it.second] = "Gold Medal";
        }

        int count = 4;

        while(!pq.empty())
        {
            it = pq.top();
            pq.pop();

            ans[it.second] = to_string(count);
            count++;
        }

        return ans;
    }
};