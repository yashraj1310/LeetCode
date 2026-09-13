class Solution {
public:
    long long countCommas(long long n) 
    {
        if(n <= 999)
            return 0;    

        long long ans = 0;

        int digits = 0;
        long long temp = n;

        while(temp > 0)
        {
            digits++;
            temp = temp/10;
        }

        if(digits <= 6)
        {
            ans = ans + n - 1e3 + 1; //(999,999 - 1,000 + 1)
        }
        else if(digits <= 9)
        {
            ans = ans + (n - 1e6 + 1)*2 + (1e6 - 1e3);
        }
        else if(digits <= 12)
        {
            ans = ans + (n - 1e9 + 1)*3 + (1e9 - 1e6)*2 + (1e6 - 1e3);
        }
        else if(digits <= 15)
        {
            ans = ans + (n - 1e12 + 1)*4 + (1e12 - 1e9)*3 + (1e9 - 1e6)*2 + (1e6 - 1e3);
        }
        else{
            ans = ans + (1e15 - 1e12)*4 + (1e12 - 1e9)*3 + (1e9 - 1e6)*2 + (1e6 - 1e3) + 5; 
            //(1,000,000,000,000,000)
        }

        return ans;
    }
};