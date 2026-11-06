class Solution {
public:

    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp)
    {
        long long ans = 1;

        while(exp > 0)
        {
            if(exp & 1)
                ans = ((ans % MOD) * (base % MOD)) % MOD;

            base = ((base % MOD) * (base % MOD)) % MOD;

            exp = exp >> 1;
        }

        return ans;
    }

    int countGoodNumbers(long long n) 
    {
        //even --> even
        //odd --> prime    

        //leading zeros allowed
        //even = 0, 2, 4, 6, 8
        //odd = 2, 3, 5, 7

        //even places = n/2 + 1
        //odd places = n/2

        //ans = 5^even + 4^odd

        long long even = (n+1)/2;
        long long odd = n/2;

        long long first = power(5, even) % MOD;
        long long second = power(4, odd) % MOD; 

        return ((first % MOD) * (second % MOD)) % MOD;
    }
};