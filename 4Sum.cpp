class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        vector<vector<int>>ans;
        
        if (v.size()<4)
            return ans;
        
        
        sort(v.begin(),v.end());
      
        set<vector<int>>s;
       for (int i=0;i<=v.size()-4;i++)
       {
           for (int j=i+1;j<=v.size()-3;j++)
           {
               //cout<<i<<" "<<j<<endl;
               int t=target-v[i]-v[j];
               
               int q=j+1;
               int w=v.size()-1;
               
               while(w>q && q>j)
               {
                   if (v[w]+v[q]==t)
                   {
                       vector<int >v1;
                       v1.push_back(v[i]);
                       v1.push_back(v[j]);
                       v1.push_back(v[w]);
                       v1.push_back(v[q]);
                       
                       cout<<i<<" "<<j<<" "<<w<<" "<<q<<endl;
                       
                       sort(v1.begin(),v1.end());
                       
                       if (s.find(v1)==s.end())
                       ans.push_back(v1);
                       
                      // cout<<"hello"<<endl;
                      q++;
                       w--;
                       
                       s.insert(v1);
                   }
                   else if (v[w]+v[q]<t)
                   {
                       q++;
                   }
                   else
                   {
                       w--;
                   }
                   
                   
               }
               
               
               
           }
       }
        return ans;
        
        
    }
};
