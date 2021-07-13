class Solution {
public:
    map<int,int>mp;
    int solve(int i,string s)
    {
         if(mp[i]!=0)
        {
            return mp[i];
        }
       
        int n=s.size();
        if (i==n)
        {
            return 1;
        }
        if (s[i]=='0')
        {
            return 0;
        }
        
        int res=solve(i+1,s);
        mp[i+1]=res;
        if (i+2<=n && (s[i]=='1' || (s[i]=='2' && s[i+1]>='0' && s[i+1]<='6')))
        {
            mp[i+2]=solve(i+2,s);
            res+=mp[i+2];
        }
        return res;
        
    }
    
    
    int numDecodings(string s) {
        
        return s.size()==0 ? 0 : solve(0,s);
        
    }
};
