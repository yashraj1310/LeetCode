class Solution {
public:
    int minOperations(string s) 
    {
        string temp = s;
        sort(temp.begin(), temp.end());

        if(s==temp)
            return 0;  

        cout << temp;

        int n = s.length();

        char mini = temp[0];
        char maxi = temp[n-1];  

        if(s.find(mini)==0 || s.rfind(maxi)==n-1)
            return 1;

        if(n==2)
            return -1;

        if(s.find(mini)==n-1 && s.rfind(maxi)==0)
            return 3;

        return 2;
    }
};