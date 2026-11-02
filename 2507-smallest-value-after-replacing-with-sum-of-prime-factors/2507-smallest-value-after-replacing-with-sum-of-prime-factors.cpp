class Solution {
public:
    int smallestValue(int n) 
    {
        //Use spf array, for finding prime factor -> nlog(logn)
        vector<int> spf(n+1);
        spf[0] = 0;
        spf[1] = 0;

        for(int i=2;i<=n;i++)
            spf[i] = i;

        for(int i=2;i*i<=n;i++)
        {
            if(spf[i]==i)
            {
                //Marks all multiples with i
                for(int j=i*i;j<=n;j+=i)
                {
                    if(spf[j]=j)
                        spf[j] = i;
                }
            }
        }    


    while(spf[n] != n)
    {
        int sum = 0;
        int temp = n;

        while(temp != 1)
        {
            sum = sum + spf[temp];
            temp = temp/spf[temp];
        }

        if(n == sum)
            return n;

        n = sum;
    }

        return n;
    }
};