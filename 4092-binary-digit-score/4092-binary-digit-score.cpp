class Solution {
public:

    string decimalToBinary(int x)
    {
        string s;
        while(x > 0)
        {
            s.push_back(x%2 + '0');
            x = x/2;
        }

        reverse(s.begin(), s.end());

        return s;
    }

    int calculateScore(int a, int b) 
    {
        string str1 = decimalToBinary(a);
        string str2 = decimalToBinary(b);

        int s1 = 0;
        int s2 = 0;

        for(int i=0;i<str1.length();i++)
        {
            if(str1[i]=='1')
                s1++;
        }
        for(int i=0;i<str2.length();i++)
        {
            if(str2[i]=='1')
                s2++;
        }

        if(s1>=s2)
            return s1*s2;

        return s2/s1;
    }
};