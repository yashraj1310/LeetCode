class Solution {
public:
    double average(vector<int>& salary) 
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = salary.size();

        for(int i=0;i<n;i++)
        {
            mini = min(mini, salary[i]);
            maxi = max(maxi, salary[i]);
        }    

        double avg;
        double sum = 0;

        for(int i=0;i<n;i++)
        {
            if(salary[i]!=mini && salary[i]!=maxi)
                sum = sum + salary[i];
        }

        avg = sum/(n-2);

        return avg;
    }
};