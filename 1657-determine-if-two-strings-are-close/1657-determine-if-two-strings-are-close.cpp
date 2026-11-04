class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        int n1 = word1.length();
        int n2 = word2.length();

        if(n1 != n2)
            return false;

        map<char, int> mpp1, mpp2;

        for(int i=0;i<n1;i++)
        {
            mpp1[word1[i]]++;
            mpp2[word2[i]]++;
        }    

        if(mpp1.size() != mpp2.size())
            return false;

        string s1, s2, count1, count2;

        for(auto it : mpp1)
        {
            s1.push_back(it.first);
            count1 += to_string(it.second);
        }
        for(auto it : mpp2)
        {
            s2.push_back(it.first);
            count2 += to_string(it.second);
        }

        cout << s1 << endl;
        cout << s2 << endl;
        
        if(s1 != s2)
            return false;

        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        cout << count1 << endl;
        cout << count2 << endl;

        if(count1 != count2)
            return false;       

        return true;
    }
};