class Solution {
public:
    struct data{
        int start;
        int end;
    };
    static bool comp(data val1, data val2)
    {
        return val1.start < val2.start;
    }
    int numberOfPoints(vector<vector<int>>& nums) 
    {
        int n = nums.size();
        vector<data> arr;

        for(int i=0;i<n;i++)
        {
            data temp;
            temp.start = nums[i][0];
            temp.end = nums[i][1];
            arr.push_back(temp);
        }

        sort(arr.begin(), arr.end(), comp);

        vector<vector<int>> ans;

        int startTime = arr[0].start;
        int endTime = arr[0].end;

        for(int i=1;i<arr.size();i++)
        {
            if(arr[i].start <= endTime)
                endTime = max(arr[i].end, endTime);

            else{
                ans.push_back({startTime, endTime});
                startTime = arr[i].start;
                endTime = arr[i].end;
            }
        }

        ans.push_back({startTime, endTime});

        int count = 0;

        for(int i=0;i<ans.size();i++)
        {
            count = count + (ans[i][1] - ans[i][0] + 1);
        }

        return count;
    }
};