class Solution {
public:
    vector<int> closestPrimes(int left, int right) 
    {
        vector<int> ans;
        vector<bool> primes(right+1);

        for(int i=0;i<=right;i++)
            primes[i] = true;

        primes[0]=false;
        primes[1]=false;

        for(int i=2;i*i<=right;i++)
        {
            if(primes[i])
            {
                for(int j=i*i;j<=right;j+=i)
                {
                    primes[j] = false;
                }
            }
        }    
        vector<int> arr;
        for(int i=left;i<=right;i++)
        {
            if(primes[i])
                arr.push_back(i);
        }
            
        int mini = 1e7;
        int first;
        int second;

        if(arr.size() < 2)
            return {-1, -1};

        for(int i=1;i<arr.size();i++)
        {
            if(mini > arr[i]-arr[i-1])
            {
                mini = arr[i]-arr[i-1];
                first = arr[i-1];
                second = arr[i];
            }
        }
        ans.push_back(first);
        ans.push_back(second);

        return ans;
    }
};