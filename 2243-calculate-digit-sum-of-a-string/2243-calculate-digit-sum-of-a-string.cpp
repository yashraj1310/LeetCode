class Solution {
public:
    string digitSum(string s, int k) 
    {

        while(s.length() > k)
        {
            string temp1 = "";
            int sum = 0;
            int count = 0;

            for(int i=0;i<s.length();i++)
            {
                sum = sum + s[i]-'0';
                count++;

                if(count==k)
                {
                    temp1+=to_string(sum);
                    count=0;
                    sum=0;
                }
            }

            if(count > 0)
            {
                temp1+=to_string(sum);
                count=0;
                sum=0;
            }

            s = temp1;
        }

        return s;
    }
};