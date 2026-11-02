class Solution {
public:
    int commonFactors(int a, int b) 
    {
        int GCD = gcd(a, b);
        int count = 0;

        for(int i=1;i*i<=GCD;i++)
        {
            if(GCD % i == 0)
            {
                count++;
                if(i != GCD/i)
                    count++;
            }
        }    

        return count;
    }
};