class Solution {
public:
    
    vector<int>v;
    vector<int>v1;
    
    int n;
    Solution(vector<int>& nums) {
        v=nums;
        v1=nums;
        n=nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        
        return v;
        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
      
        for (int i=n-1;i>=0;i--)
        {
            int j=rand()%(i+1);
            
            swap(v1[i],v1[j]);
            
        }
        return v1;
        
    }
};
