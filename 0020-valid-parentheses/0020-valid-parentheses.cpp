class Solution {
public:
    bool isValid(string s) 
    {
        stack<int> st;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }

            if(s[i]==')' || s[i]=='}' || s[i]==']')
            {
                if(st.empty()) 
                    return false;
                    
                char a = st.top();
                st.pop();
                if((s[i]==')' && a!='(') || (s[i]=='}' && a!='{') || (s[i]==']' && a!='['))
                {
                    return false;
                }
            }
        }  
        return st.empty();  
    }
};