class Solution {
public:
    long long dividePlayers(vector<int>& skill) 
    {
        int n = skill.size();
        int teams = n/2;
        long long sum = 0;

        for(int i=0;i<n;i++)
            sum = sum + skill[i];

        if(sum % teams != 0)
            return -1;

        sort(skill.begin(), skill.end());
        int temp = skill[0] + skill[n-1];
        int i=1;
        int j=n-2;

        while(i < j)
        {
            if(skill[i] + skill[j] != temp)
                return -1;

            i++;
            j--;
        }    

        long long ans = 0;
        int k = 0;
        int l = n-1;

        while(k < l)
        {
            ans = ans + skill[k]*skill[l];
            k++;
            l--;
        }

        return ans;
    }
};