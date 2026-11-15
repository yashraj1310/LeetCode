class Solution {
public:
    int calPoints(vector<string>& nums) 
    {
        stack<int> st;
        int score = 0;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i] != "+" && nums[i] != "D" && nums[i] != "C")
                st.push(stoi(nums[i]));

            if(nums[i] == "+")
            {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.push(first);
                st.push(first + second);
            }
            else if(nums[i] == "D")
            {
                int temp = st.top();
                st.push(temp*2);
            }
            else if(nums[i]=="C")
                st.pop();
        }    

        while(!st.empty())
        {
            score = score + st.top();
            st.pop();
        }

        return score;
    }
};