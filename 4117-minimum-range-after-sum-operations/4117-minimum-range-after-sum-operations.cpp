class Solution {
public:
    int minRange(int a, int b, int c) 
    {
        int first, second, third;
        vector<int> vec = {a, b, c};
        sort(vec.begin(), vec.end());

        if(vec[2] >= vec[0] + vec[1])
        {
            vec[2] = vec[0] + vec[1];
            return vec[2] - vec[0];
        }    
        else{
            return vec[2] - vec[0];
        }

        return 0;
    }
};