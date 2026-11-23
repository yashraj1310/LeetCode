class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) 
    {
        vector<string> ans;
        int n = rain.size();
        int alice = 0, bob = 0;

        for(int i=0;i<n;i++)
        {
            if(rain[i]==1)
            {
                if(i != n-1)
                {
                    if(rain[i+1] == 1)
                    {
                        if(alice==bob || alice < bob)
                        {
                            ans.push_back("Alice");
                            alice++;
                        }
                        else{
                            ans.push_back("Bob");
                            bob++;
                        }
                    }
                    else{
                        ans.push_back("Bob");
                        bob++;
                    }
                }
                else{
                    ans.push_back("Bob");
                    bob++;
                }
            }
            else{
                ans.push_back("None");
            }
        }   
        return ans; 
    }
};