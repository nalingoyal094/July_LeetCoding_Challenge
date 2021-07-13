class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        map<char,char>mp;
        map<char,int>mp1;
        
        if (s.size()!=t.size())
            return false;
        
        for (int i=0;i<s.size();i++)
        {
            if (mp.find(s[i])!=mp.end())
            {
                
                if (t[i]!=mp[s[i]])
                    return false;
                
            }
            else
            {
                if(mp1[t[i]]==1)
                {
                    return false;
                }
                else
                {
                    mp[s[i]]=t[i];
                    mp1[t[i]]=1;
                }
            }
        }
        return true;
        
        
        
    }
};
