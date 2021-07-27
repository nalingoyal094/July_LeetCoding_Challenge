class Solution {
public:
    
    TreeNode* solve(vector<int> nums,int l,int h)
    {
        if (l>h)
        {
            return NULL;
        }
        if (l==h)
        {
            TreeNode* i= new TreeNode(nums[h]);
            return i;
        }
        
        
        
        int mid=(l+h+1)/2;
        
        TreeNode*root=new TreeNode(nums[mid]);
        
        root->left= solve(nums,l, mid -1); 
        root->right= solve(nums,mid +1 , h);
            
      return root;
        
        
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        
        
           
        return solve(nums,0, nums.size()-1);
        
        
        
    }
};
