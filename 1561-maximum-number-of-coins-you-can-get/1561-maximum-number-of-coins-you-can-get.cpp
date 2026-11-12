class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        int n = piles.size();
        sort(piles.begin(), piles.end());

        int j = n-2;
        int i=0;

        int maxi = 0;

        while(i < n/3)
        {
            maxi = maxi + piles[j];
            i++;
            j-=2;
        }

        return maxi;
    }
};