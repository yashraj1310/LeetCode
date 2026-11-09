class Solution {
public:
    string reorganizeString(string s) 
    {
        int n = s.length();

        unordered_map<char, int> mpp;

        for(int i=0;i<n;i++)
            mpp[s[i]]++;

        priority_queue<pair<int, char>> pq;

        for(auto it : mpp)
        {
            pq.push({it.second, it.first});
        }

        string ans = "";

        while(pq.size() >= 2)
        {
            auto first = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            ans = ans + first.second;
            first.first--;

            ans = ans + second.second;
            second.first--;

            if(first.first > 0)
                pq.push(first);

            if(second.first > 0)
                pq.push(second);
        }

        if(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            if(it.first > 1)
                return "";

            ans = ans + it.second;
        }

        return ans;
    }
};