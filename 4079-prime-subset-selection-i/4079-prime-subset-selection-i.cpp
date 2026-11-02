class Solution {
public:

    vector<int> maxPrimes(int n, int s) 
    {
        vector<bool> primes(n+1);
        primes[0] = false;
        primes[1] = false;

        for(int i=2;i<=n;i++)
            primes[i] = true;

        for(int i=2;i*i<=n;i++)
        {
            if(primes[i])
            {
                for(int j=i*i;j<=n;j+=i)
                    primes[j] = false;
            }
        }

        vector<int> ans;
        int sum = 0;

        for(int i=2;i<=n;i++)
        {
            if(primes[i])
            {
                sum = sum + i;
            }
            if(sum > s)
                break;

            if(primes[i])
                ans.push_back(i);
        }

        return ans;
    }
};