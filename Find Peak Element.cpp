class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        if (nums.size()==1)
        {
            return 0;
        }
        
        int n=nums.size();
        
        int low=0;
        int high=n-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(mid==0)
            {
                if (nums[mid]>nums[mid+1])
                {
                    return mid;
                }
                
            }
            else if (mid==n-1)
            {
                if (nums[mid]>nums[mid-1])
                {
                    return mid;
                }
                
            }
            else
            {
                if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
                {
                    return mid;
                }
                
            }
            
            if (nums[mid]<nums[mid+1])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
            
            
            
            
        }
        
    return nums[0];   
    }
};
