class Solution {
public:
    int minInsertions(string s) 
    {
        int n = s.length();
        stack<char> st;
        int ans = 0;

        for(int i=0;i<n;i++)
        {
            if(i+1 < n && s[i]==')' && s[i+1]==')')
            {
                if(st.empty())
                {
                    ans = ans + 1;
                    i++;
                }
                else{
                    st.pop();
                    i++;
                }
            }
            else if(s[i]=='(')
                st.push(s[i]);

            else if(i+1 < n && s[i]==')' && s[i+1]!=')')
            {
                if(st.empty())
                {
                    ans = ans+2;
                }
                else{
                    ans+=1;
                    st.pop();
                }
            }

            else if(i==n-1 && s[i]==')')
            {
                if(st.empty())
                {
                    ans = ans + 2;
                }
                else{
                    st.pop();
                    ans++;
                }
            }
        }    

        if(!st.empty())
            ans = ans + 2*st.size();
        
        return ans;
    }
};