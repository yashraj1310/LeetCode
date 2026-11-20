class Solution {
public:
    string simplifyPath(string s) 
    {
        int n = s.length();
        stack<string> st;
        string curr = "";
        stack<string> dots;

        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='/')
            {
                if(curr == "..")
                    dots.push(curr);

                else if(curr != "" && curr != ".")
                {
                    if(!dots.empty())
                        dots.pop();

                    else{
                        st.push(curr);
                    }
                }

                curr = "";
            }

            else{
                curr.insert(curr.begin(), s[i]);
            }
        }

        string ans = "/";

        if(st.empty())
            return "/";

        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
            ans.push_back('/');
        }

        ans.pop_back();

        return ans;

    }
};