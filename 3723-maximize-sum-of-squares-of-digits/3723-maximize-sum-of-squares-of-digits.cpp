class Solution {
public:
    string maxSumOfSquares(int num, int sum) 
    {
        string ans = "";

        while(num--)
        {
            int curr = min(9, sum);
            ans.push_back('0' + curr);
            sum = sum-curr;
        }    

        if(sum==0)
            return ans;

        return "";
    }
};