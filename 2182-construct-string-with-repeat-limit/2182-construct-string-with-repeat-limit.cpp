class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) 
    {
        int n = s.length();
        unordered_map<char, int> mpp;

        for(int i=0;i<n;i++)
            mpp[s[i]]++;

        priority_queue<pair<char, int>> pq;

        for(auto it : mpp)
        {
            pq.push({it.first, it.second});
        }

        string ans = "";

        while(pq.size() >= 2)
        {
            auto first = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();
            int temp = repeatLimit;

            while(temp--)
            {
                ans.push_back(first.first);
                first.second--;

                if(first.second==0)
                    break;
            }

            if(first.second > 0)
            {
                ans.push_back(second.first);
                second.second--;
                pq.push(first);

                if(second.second > 0)
                    pq.push(second);
            }
            else{
                pq.push(second);
            }
        }    

        if(!pq.empty())
        {
            auto tempo = pq.top();
            pq.pop();

            while(repeatLimit-- && tempo.second > 0)
            {
                ans.push_back(tempo.first);
                tempo.second--;
            }
        }

        return ans;
    }
};