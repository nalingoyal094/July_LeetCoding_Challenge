// naive approach
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        if (nums.size()<3)
        {
            return 0;
        }
        
        int count=0;
        for (int i=0;i<=nums.size()-3;i++)
        {
            for (int j=i+1;j<=nums.size()-2;j++)
            {
                for (int k=j+1;k<=nums.size()-1;k++)
                {
                    if (nums[i]+nums[j]>nums[k] && nums[i]>0 && nums[k]>0 && nums[j]>0 && nums[j]+nums[k]>nums[i] && nums[k]+nums[i]>nums[j])
                        count++;
                }
            }
        }
        return count;
        
    }
};

// T.C = O(n^3)



//optimised approach

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        if (nums.size()<3)
        {
            return 0;
        }
        
        
        int ans=0;
        sort(nums.begin(),nums.end());
        for (int i=2;i<nums.size();i++)
        {
            int r=i-1;
           int l=0;
            
            while( r>l )
            {
                if (nums[l]+nums[r]>nums[i])
                {ans+=r-l;
                r--;
                }
                else
                {
                    l++;
                }
                
            }
            
            
            
            
        }
        return ans;
        
    }
};

// O(n^2)
