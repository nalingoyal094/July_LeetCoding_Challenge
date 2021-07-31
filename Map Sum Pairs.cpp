class MapSum {
public:
    /** Initialize your data structure here. */
    
    
    map<string,int>mp;
    
    MapSum() 
    {
        
    }
    
    void insert(string key, int val) {
    
        mp[key]=val;
        
    }
    
    int sum(string prefix) {
        
        int ans=0;
        
        for (auto i:mp)
        {
            if ((i.first).find(prefix)==0)
            {
                ans+=i.second;
            }
}
        return ans;
        
    }
};
