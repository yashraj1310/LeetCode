class Solution {
public:
    bool threeFibonacciSum(int n) 
    {
        if(n%2!=0)
            return false;

        int a = 0;
        int b = 1;
        int c = 1;
        int sum;

        while(sum <= n)
        {
            sum = a + b + c;
            if(sum==n)
                return true;

            a = b;
            b = c;
            c = a + b;
        }

        return false;
    }
};