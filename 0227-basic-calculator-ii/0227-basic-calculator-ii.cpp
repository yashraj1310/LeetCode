class Solution {
public:
    int calculate(string s) 
    {
        int n = s.length();
        char prevOp = '+';
        stack<int> st;
        long long num = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
                num = num*10 + s[i]-'0';

            else if(s[i] == ' ')
                continue;

            else{
                if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
                {
                    if(prevOp=='+')
                        st.push(num);

                    else if(prevOp=='-')
                        st.push(-num);

                    else if(prevOp=='*')
                    {
                        int temp = st.top();
                        st.pop();
                        st.push(temp*num);
                    }
                    else{
                        int temp = st.top();
                        st.pop();
                        st.push(temp/num);
                    }
                    prevOp = s[i];
                    num=0;
                }
            }
        }    
         if(prevOp=='+')
            {
                st.push(num);
            }

            else if(prevOp=='-')
                st.push(-num);

            else if(prevOp=='*')
            {
                int temp = st.top();
                st.pop();
                st.push(temp*num);
            }

            else{
                int temp = st.top();
                st.pop();
                st.push(temp/num);
            }
            int ans = 0;

            while(!st.empty())
            {
                ans = ans + st.top();
                st.pop();
            }

        return ans;
    }
};