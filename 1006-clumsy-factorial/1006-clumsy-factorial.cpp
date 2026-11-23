class Solution {
public:
    int clumsy(int n) 
    {
        stack<int> st;
        st.push(n);
        n--;
        char currOp = '*';
        int temp;

        while(n >= 1)
        {
            if(currOp == '*')
            {
                temp = st.top();
                st.pop();
                st.push(temp * n);
                currOp = '/';
            }
            else if(currOp == '/')
            {
                temp = st.top();
                st.pop();
                st.push(temp / n);
                currOp = '+';
            }
            else if(currOp == '+')
            {
                st.push(n);
                currOp = '-';
            }
            else if(currOp == '-')
            {
                st.push(-n);
                currOp = '*';
            }
            n--;
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