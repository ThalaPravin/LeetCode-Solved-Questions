class Solution {
public:
    int solve(int i,int &n,vector<int> &v,int k,vector<vector<int>> &dp){
        if(i>=n)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int ans1 = solve(i+1,n,v,k,dp);
        int ans2 = 0;
        if(k){
            ans2 = -v[i]+solve(i+1,n,v,0,dp);
        }else{
            ans2 = v[i]+solve(i+2,n,v,1,dp);
        }
        return dp[i][k] = max(ans1,ans2);
    }
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int ans =  solve(0,n,v,1,dp);
        return ans;
    }
};