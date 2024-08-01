class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>&grid){
        vis[row][col]=1;
        int n=grid.size();
    
        int m=grid[0].size();
         int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nrow=row+dr[k];
            int ncol=col+dc[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                
               dfs(nrow, ncol, vis, grid);
            }
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int j = 0; j < m;j++)
        {
            if(!vis[0][j] and grid[0][j] == 1) dfs(0,j,vis,grid);
            if(!vis[n-1][j] and grid[n-1][j] == 1) dfs(n-1,j,vis,grid);
        }
        
        for(int i = 0; i < n;i++)
        {
            if(!vis[i][0] and grid[i][0] == 1) dfs(i,0,vis,grid);
            if(!vis[i][m-1] and grid[i][m-1] == 1) dfs(i,m-1,vis,grid);
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]) cnt++;
            }
        }

        return cnt;
    }
};