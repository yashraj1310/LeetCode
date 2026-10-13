class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        int n = nums.size();
        int minus, plus;

        if(n%2==0)
        {
            minus = n/2;
            plus = minus-1;
        }
        else{
            minus = n/2;
            plus = n/2;
        }

        sort(nums.begin(), nums.end(), [](int a, int b) 
        {
            return abs(a) < abs(b);
        });

        long long sum = nums[n-1]*nums[n-1];
        int i = n-2;

        while(plus)
        {
            sum = sum + nums[i]*nums[i];
            plus--;
            i--;
        }

        while(minus)
        {
            sum = sum - (nums[i]*nums[i]);
            minus--;
            i--;
        }

        return sum;
    }
};