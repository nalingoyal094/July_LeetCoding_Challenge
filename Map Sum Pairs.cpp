// Approach 1 - using map

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

// S.C = O(n)
// T.C = O(n)


// approach 2 - using trie

struct TrieNode
{
    vector<TrieNode*> children;
    int sum;
    bool isEnd;
    
    TrieNode()
    {
        children.resize(26, NULL);
        sum = 0;
        isEnd = false;
    }
    
    TrieNode* getChar(char ch)
    {
        return children[ch - 'a'];
    }
    
    void setChar(char ch, int val)
    {
        children[ch - 'a'] = new TrieNode();
        children[ch - 'a']->sum = val;
    }
    
    int getSum()
    {
        return sum;
    }
    
    int getCharSum(char ch)
    {
        return children[ch - 'a']->sum;
    }
};

class MapSum {
private:
    TrieNode* root;
    unordered_map<string, int> mp;
public:
    /** Initialize your data structure here. */
    MapSum() 
    {
        root = new TrieNode();
    }
    
    void insert(string key, int val) 
    {
        TrieNode* curr = root;
        
        for(auto ch : key)
        {
            //If there is no node existing for current character, create one and add val to it
            if(curr->getChar(ch) == NULL)
            {
                curr->setChar(ch, val);
            }
            //We have a node existing for current character
            else
            {
                //Get the sum for current character
                int currSum = curr->getCharSum(ch);
                
                //If current key already exists in map.
                if(mp.find(key) != mp.end())
                    //Decrement current key's value from sum and add new val to it
                    curr->getChar(ch)->sum = currSum - mp[key] + val;
                else
                    //Add the value to current sum
                    curr->getChar(ch)->sum = currSum + val;
            }
            
            curr = curr->getChar(ch);
        }
        mp[key] = val;
    }
    
    int sum(string prefix) 
    {
        TrieNode* curr = root;
        
        //Iterate through each character in prefix
        for(auto ch : prefix)
        {
            //If we don't have a node existing for current character, return 0
            if(curr->getChar(ch) == NULL)
                return 0;
            //Else move onto next node
            else
                curr = curr->getChar(ch);
        }
        //return the sum of current node
        return curr->getSum();
    }
};





