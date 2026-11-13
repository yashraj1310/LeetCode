class Solution {
public:
    string maximumOddBinaryNumber(string s) 
    {
        int n = s.length();
        int zeros = 0;
        int ones = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
                zeros++;
            else
                ones++;
        }    

        s[n-1] = '1';
        ones--;

        int i=0;

        while(ones--)
        {
            s[i] = '1';
            i++;
        }

        while(zeros--)
        {
            s[i] = '0';
            i++;
        }

        return s;
    }
};