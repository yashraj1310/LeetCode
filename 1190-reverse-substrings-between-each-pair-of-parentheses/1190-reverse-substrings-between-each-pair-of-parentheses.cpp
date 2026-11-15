class Solution {
public:
    string reverseParentheses(string s) 
    {
        int n = s.length();
        stack<int> st; //indices of opening bracket

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                st.push(i);

            if(s[i]==')')
            {
                int temp = st.top();
                st.pop();
                reverse(s.begin() + temp, s.begin() + i);
            }
        }    

        string ans = "";

        for(int i=0;i<n;i++)
        {
            if(s[i] != '(' && s[i] != ')')
                ans.push_back(s[i]);
        }

        return ans;
    }
};