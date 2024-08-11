class Solution {
public:
    int solve(vector<int>&dp, int i, int n, vector<int>nums){
        if(i>=n) return 0;
        if(i==n-1) return nums[i];

        if(dp[i]!=-1) return dp[i];

        int ans= nums[i];
        int t1=0,t2=0;
        if(i+2<n) t1=solve(dp,i+2,n, nums);
        if(i+3<n) t2=solve (dp,i+3,n,nums);

        
        ans+=max(t1,t2);

        return dp[i]=ans;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        
        return max(solve(dp,0,n,nums), solve(dp,1,n,nums));
    }
};