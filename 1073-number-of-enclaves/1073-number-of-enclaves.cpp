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

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || j==0 || i== n-1 || j==m-1) && grid[i][j]==1){
                    dfs(i,j, vis, grid);
                }
            }
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