class Solution {
public:
    string arrangeWords(string s) 
    {
        vector<string> arr;
        int n = s.length();
        string word="";

        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                arr.push_back(word);
                word="";
                continue;
            }
            word.push_back(s[i]);
        }    
        arr.push_back(word);

        stable_sort(arr.begin(), arr.end(), [](auto &a, auto &b)
        {
            return a.length() < b.length();
        });

        string ans="";
        for(int i=0;i<arr.size();i++)
        {
            ans+=arr[i];
            ans.push_back(' ');
        }
        ans.pop_back();
        
        for (char& c : ans) 
        {
            if (c >= 'A' && c <= 'Z') 
                c += 32;
        }
        ans[0]-=32;

        return ans;
    }
};