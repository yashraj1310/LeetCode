class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) 
    {
        long long cost = 0;

        int a = min(cost1 + cost2, costBoth);
        int low = min(need1, need2);
        cost = cost + (long long)a*low;
        need1 = need1-low;
        need2 = need2-low;

        if(need1 > 0)
            cost = cost + (long long)need1*min(cost1, costBoth);

        if(need2 > 0)
            cost = cost + (long long)need2*min(cost2, costBoth);

        return cost;
    }
};