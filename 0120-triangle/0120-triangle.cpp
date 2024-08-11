class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n, -1));
        return f(0,0,triangle, dp,n);
    }

    int f(int r, int c, vector<vector<int>>&t, vector<vector<int>>&dp , int n ){
        if(r==n-1) return t[r][c];
        if(dp[r][c]!=-1) return dp[r][c];

        return dp[r][c]= t[r][c]+min(f(r+1,c,t,dp,n), f(r+1,c+1,t,dp,n)) ;
    }
};