class Solution {
public:
     int findsum(int a[],int n,int sum)
{
        int result=INT_MIN;
         
         int prefix_sum=0;
         set<int>s;
         s.insert(0);
         for (int i=0;i<n;i++)
         {
             prefix_sum+=a[i];
             
             auto itr=s.lower_bound(prefix_sum-sum);
             
             if (itr!=s.end())
             {
                 
                 result=max(result,prefix_sum-*itr);
             }
             s.insert(prefix_sum);
             
         }
         return result;
         
         
         
}
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int r=matrix.size();
        int c=matrix[0].size();
        int maxx=INT_MIN;
        for (int i=0;i<r;i++)
        {
            int col[c];
           
            for (int y=0;y<c;y++)
                col[y]=0;
            for (int j=i;j<r;j++)
            {
                for (int k=0;k<c;k++)
                {
                    col[k]+=matrix[j][k];
                }
                
                maxx=max(maxx,findsum(col,c,k));
                
            }
        }
        return maxx;
        
    }
};

// r= number of rows
// c=number of columns

// t.c= O(r^2 + clogc)
