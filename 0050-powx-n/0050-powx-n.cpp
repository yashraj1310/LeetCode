class Solution {
public:
    double myPow(double x, int n) 
    {
        double ans = 1;
        long m = n;
        long temp;
        
        if(m < 0)
            temp = -m;
        else
            temp = m;

        while(temp > 0) 
        {
            if(temp%2==1)
            {
                ans = ans * x;
                temp--;
            }
            else{
                temp = temp/2;
                x = x*x;
            }
        }   

        if(m<0)
            return 1.0/ans;

        return ans;
    }
};