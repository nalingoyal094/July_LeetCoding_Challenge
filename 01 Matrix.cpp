class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<pair<int ,int >>dir={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>vis(n,vector<int>(m,-1));
        
        queue<pair<int , int >>q;
        
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (mat[i][j]==0)
                {
                    q.push({i,j});
                    vis[i][j]=0;
                    
}
            }
}
        
        
        while(!q.empty())
        {
            int size=q.size();
            
            while(size--)
            {
                pair<int, int >p=q.front();
                q.pop();
                for (auto i:dir)
                {
                    int f=p.first+i.first;
                    int s=p.second+i.second;
                    
                    if (f>=0 && s>=0 && f<n && s<m && vis[f][s]==-1)
                    {
                        q.push({f,s});
                        vis[f][s]=vis[p.first][p.second]+1;
                        
                    }
                    
                }
}
            
        }
        return vis;
        
        
    }
};
