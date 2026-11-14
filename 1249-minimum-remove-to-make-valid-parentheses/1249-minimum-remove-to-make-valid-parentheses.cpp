class Solution {
public:

    bool f(vector<int>& unmatched, int i, int size)
    {
        for(int j=0;j<size;j++)
        {
            if(unmatched[j]==i)
                return true;
        }

        return false;
    }

    string minRemoveToMakeValid(string s) 
    {
        int n = s.length();
        string ans= "";
        stack<pair<char, int>> st;
        vector<int> unmatched;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                st.push({s[i], i});

            else if(s[i]==')')
            {
                if(st.empty())
                {
                    unmatched.push_back(i);
                }
                else{
                    st.pop();
                }
            }
        } 

        while(!st.empty())
        {
            unmatched.push_back(st.top().second);
            st.pop();
        }   

        int size = unmatched.size();

        for(int i=0;i<size;i++)
            cout << unmatched[i] << ' ';

        
        for(int i=0;i<n;i++)
        {
            if(f(unmatched, i, size))
                continue;

            ans.push_back(s[i]);
        }

        return ans;
    }
};