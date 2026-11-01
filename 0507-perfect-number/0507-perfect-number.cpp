class Solution {
public:
    bool checkPerfectNumber(int num) 
    {
        int sum = 0;

        if(num==1)
            return false;

        for(int i=1;i*i<=num;i++)
        {
            if(num%i==0)
            {
                if(i != 1)
                {
                    sum = sum + i;
                    if(i != num/i)
                        sum = sum + num/i;
                }
                else{
                    sum = sum + i;
                }
            }

            if(sum > num)
                return false;
        }    

        if(sum==num)
            return true;

        return false;
    }
};