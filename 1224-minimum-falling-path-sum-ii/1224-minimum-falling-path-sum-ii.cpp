class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1) return grid[0][0];
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n+1, INT_MAX));
        for(int i=0; i<n; i++){
            ans= min(ans, f(0,i,n, dp, grid));
        }
        return ans;
    }

    int f(int r, int c, int n, vector<vector<int>>&dp, vector<vector<int>>&grid){
        if(r<0 || r>=n || c<0 || c>=n) return 0;
        if(dp[r][c]!=INT_MAX) return dp[r][c];

        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            if(i==c) continue;
            ans=min(ans,  grid[r][c]+f(r+1, i, n, dp, grid));
        }
        return dp[r][c]=ans;
    }
};