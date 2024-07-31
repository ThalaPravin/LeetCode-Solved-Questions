class Solution {
public:
    int bfs ( int row, int col, vector<vector<int>>&vis, vector<vector<int>>&grid){
        vis[row] [col]=1;
        queue<pair<int, int>>q;
        q.push({row, col});

        int n=grid.size();
        int m= grid[0].size();

        int mx=1;

        while(!q.empty()){
            int row=q.front().first;
            int col= q.front().second;

            q.pop();

            for(int drow=-1; drow<=1; drow++){
                for(int dcol=-1; dcol<=1; dcol++){
                 if(drow !=0 && dcol !=0) continue;
                   int  nrow= row+ drow;
                   int ncol= col+dcol;

               if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
{
                        vis[nrow] [ncol]=1;
                        mx++;
                        q.push({nrow, ncol});

                    }
                }
            }
        }

        return mx;

    }
 int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        int ans=0;
        int cur;

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col]==1){
                    cnt++;
                     cur= bfs(row, col, vis, grid);
                     ans=max(ans, cur);
                }
            }
        }

        return ans;
    }
};


