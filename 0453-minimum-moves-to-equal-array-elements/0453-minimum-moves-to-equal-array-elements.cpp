class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        //It simply means, in one move reduce any one element by 1
        int n = nums.size();
        int mini = nums[0];

        for(int i=1;i<n;i++)
        {
            mini = min(mini, nums[i]);
        }    
        int moves = 0;

        for(int i=0;i<n;i++)
        {
            moves = moves + (nums[i] - mini);
        }

        return moves;
    }
};