class Solution {
public:
    int minRotations(string s) 
    {
        int n = s.length();
        int curr = 0;
        int rotations = 0;

        for(int i=0;i<n;i++)
        {
            int next = s[i] - '0';
            rotations = rotations + min(abs(next-curr), 10-abs(next-curr));
            curr = next;
        }    

        return rotations;
    }
};