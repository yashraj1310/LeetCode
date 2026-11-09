class Solution {
public:
    string longestDiverseString(int a, int b, int c) 
    {
        // atmost a,b,c
        string ans = "";
        priority_queue<pair<int, char>> pq;

        if(a>0)
            pq.push({a, 'a'});

        if(b>0)
            pq.push({b, 'b'});
        
        if(c>0)
            pq.push({c, 'c'});

        while(pq.size() >= 2)
        {
            auto first = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            if(first.first >= 2)
            {
                ans+=first.second;
                ans+=first.second;
                first.first-=2;
            }
            else
            {
                ans+=first.second;
                first.first-=1;
            }

            if(second.first >= 2 && second.first > first.first)
            {
                ans+=second.second;
                ans+=second.second;
                second.first-=2;
            }
            else
            {
                ans+=second.second;
                second.first-=1;
            }

            if(first.first > 0)
                pq.push(first);

            if(second.first > 0)
                pq.push(second);
        }    

        int n = ans.size();

        if(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int add = min(it.first, 2);
            for(int i=0;i<add;i++)
                ans+=it.second;
        }

        return ans;
    }
};