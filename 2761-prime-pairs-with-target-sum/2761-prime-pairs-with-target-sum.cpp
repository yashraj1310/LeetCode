class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) 
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
                {
                    primes[j] = false;
                }
            }
        }   

        vector<vector<int>> ans;
        vector<int> arr;

        for(int i=2;i<=n;i++)
        {
            if(primes[i])
                arr.push_back(i);
        }

        set<int> st(arr.begin(), arr.end());

        for(auto it : st)
        {
            int need = n-it;

            if(st.find(need) != st.end() && it <= need)
                ans.push_back({it, need});
        }

        return ans;
    }
};