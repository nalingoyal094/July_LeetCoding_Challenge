class Solution {
public:
    string pushDominoes(string v) {
        
        int n=v.size();
        
        vector<int>right(n,0);
         vector<int>left(n,0);
        
        int r=0;
        
        for(int i=0;i<n;i++)
        {
            if((v[i]=='.' and r==0) ||(v[i]=='L'))
            {
                right[i]=0;
                r=0;
            }
            else if (v[i]=='.' and r!=0)
            {
                r+=1;
                right[i]=r;
            }
            else
            {
                right[i]=1;
                r=1;
            }
        }
        
        // left
        int l=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if((v[i]=='.' and l==0) ||(v[i]=='R'))
            {
        //        cout<<"j"<<endl;
                 left[i]=0;
                l=0;
            }
            else if (v[i]=='.' and l!=0)
            {
                l-=1;
                left[i]=l;
            }
            else
            {
                left[i]= -1;
                l=-1;
            }
        }
        
      //  for (int i=0;i<n;i++)
      //  cout<<left[i]<<endl;
        
        string ans="";
        
        for (int i=0;i<n;i++)
        {
            if(abs(left[i])==abs(right[i]) )
            {
                ans.push_back('.');
            }
            else if((abs(left[i])>abs(right[i]))&& (abs(left[i])!=0 && abs(right[i])!=0 ))
            {
                ans.push_back('R');
            }
            else if ((abs(left[i])<abs(right[i]))&& (abs(left[i])!=0 && abs(right[i])!=0 ))
            {
                ans.push_back('L');
                
            }
            else if (abs(left[i])==0)
            {
                ans.push_back('R');
            }
            else
            {
                ans.push_back('L');
            }
            
        }
        
        
    //    cout<<right[4]<<endl;
        
        return ans;
        
        
        
        
        
        
    }
};
