class Solution {
public:

    const int MOD = 1337;

    long long power(long long base, long long exp)
    {
        long long r = 1;
        base = base % MOD;

        while(exp > 0)
        {
            if(exp & 1)
                r = ((r%MOD) * (base%MOD))%MOD;

            base = ((base % MOD) * (base % MOD)) % MOD;

            exp = exp >> 1;
        }

        return r;
    }

    int superPow(int a, vector<int>& b) 
    {
        int n = b.size();
        int ans = 1;

        ans = ans * power(a, b[0]);

        for(int i=1;i<n;i++)
        {
            ans = ((power(ans, 10) % MOD) * (power(a, b[i]) % MOD)) % MOD;
        }

        return ans;
    }
};