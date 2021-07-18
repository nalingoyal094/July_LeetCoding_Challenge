class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        
        int ones=0;
        
        for (int i=0;i<arr.size();i++)
        {
            if (arr[i]==1)
            {
                ones++;
            }
        }
        
        if (ones==0)
        {
            return {0,2};
        }
        
        
        int ones_each_part=ones/3;
        
        vector<int >ans={-1,-1};
        if (ones%3!=0)
        {
            return ans;
        }
        
        int first=-1;
        int second=-1;
        int third=-1;
        
        int one=0;
        
        for (int i=0;i<arr.size();i++)
        {
            if (arr[i]==1)
            {    one++;
            if (one ==1)
            {
                first=i;
                cout<<first<<endl;
            }
            else if (one ==ones_each_part+1)
            {
                second=i;
            }
            else if (one ==2*ones_each_part+1)
            {
                third=i;
            }
            }
            
        }
        cout<<ones_each_part<<endl;
        cout<<first<<second<<third<<endl;
        
        while(third<arr.size())
        {
            if(arr[first]==arr[second] && arr[second]==arr[third])
            {
                first++;
                second++;
                third++;
            }
            else
            {
                return ans;
            }
            
            
        }
        
        
        
        ans={first-1,second};
        return ans;
        
        
        
        
    }
};
