class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int n = pushed.size();

        int i=1;
        int j=0;
        stack<int> st;
        st.push(pushed[0]);

        while(i < n)
        {
            while(!st.empty() && popped[j] == st.top())
            {
                st.pop();
                j++;
            }

            st.push(pushed[i]);
            i++;
        }    

        while(!st.empty() && j<n)
        {
            if(st.top() != popped[j])
                return false;

            st.pop();
            j++;
        }

        return st.empty();
    }
};