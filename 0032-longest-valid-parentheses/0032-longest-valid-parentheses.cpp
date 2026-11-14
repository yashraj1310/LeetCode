class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int n = s.length();
        int count = 0;
        stack<int> st;
        st.push(-1);
        int maxi = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                st.push(i);

            else if(s[i]==')')
            {
                st.pop();
                if(st.empty()) //start from next of this char
                {
                    st.push(i);
                }
                else{
                    maxi = max(maxi, i-st.top());
                }
            }
        }

        return maxi;
    }
};