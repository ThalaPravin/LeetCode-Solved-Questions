class Solution {
public:

  void dfs(int i,int j,int n,int m,vector<vector<char>> &board,vector<vector<char>> &grid,vector<vector<int>> &vis){
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nrow=i+dr[k];
            int ncol=j+dc[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                grid[nrow][ncol]='O';
                dfs(nrow,ncol,n,m,board,grid,vis);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m= board[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        vector<vector<char>> grid(n,vector<char> (m,'X'));
     
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O' && vis[i][j]==0){
                    grid[i][j]='O';
                    vis[i][j]=1;
                    dfs(i,j,n,m,board,grid,vis);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]=grid[i][j];
            }
        }
        return;
    }
};