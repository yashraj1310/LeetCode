class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        int n = arr.size();
        long long ans = 0;
        int evenCount = 1; //as empty subarray is even
        int oddCount = 0;    

        int MOD = 1e9 + 7;
        long long prefix = 0;

        for(int i=0;i<n;i++)
        {
            prefix = prefix + arr[i];

            if(prefix % 2 == 0) //see no. of odd prefixes before it, as even-odd=odd
            {
                ans = ans + oddCount;
                evenCount++;
            } 
            else{
                ans = ans + evenCount;
                oddCount++;
            }
        }

        return ans%MOD;
    }
};