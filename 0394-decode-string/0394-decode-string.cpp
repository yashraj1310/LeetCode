class Solution {
public:
    string decodeString(string s) 
    {
        int n = s.length();    
        stack<pair<string, int>> st;
        string temp = "";
        int k = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
                k = k*10 + s[i]-'0';

            else if(s[i] == '[')
            {
                st.push({temp, k});
                temp = "";
                k = 0;
            }

            else if(s[i] >= 'a' && s[i] <= 'z')
                temp.push_back(s[i]);

            else if(s[i] == ']')
            {
                int count = st.top().second;
                string temp1 = st.top().first;
                st.pop();

                for(int i=0;i<count;i++)
                    temp1 += temp;

                temp = temp1;
            }
        }

        return temp;
    }
};