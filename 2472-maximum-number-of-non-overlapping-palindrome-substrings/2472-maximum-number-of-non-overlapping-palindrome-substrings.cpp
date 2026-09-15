class Solution {
public:

    bool isPalindrome(string x)
    {
        string temp = x;
        reverse(temp.begin(), temp.end());

        return temp==x;
    }
    int maxPalindromes(string s, int k) 
    {
        int n = s.length();
        int count = 0;

        int start = 0;

        for(int j = k-1; j < n; j++)
        {
            for(int i = start; i <= j-k+1; i++)
            {
                if(isPalindrome(s.substr(i, j-i+1)))
                {
                    count++;
                    start = j + 1;
                    break;
                }
            }
        } 

        return count;
    }
};