class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return f(0,-1,nums,n , dp);
    }

    int f(int curr, int prev, vector<int>&nums,int n, vector<vector<int>>&dp){
        if(curr==n) return 0;

        if(  dp[curr][prev+1] !=-1) return dp[curr][prev+1];
        int tk=0;
       
        if( prev==-1 ||  nums[prev]<nums[curr]){
             tk=1+f(curr+1, curr, nums, n, dp);
        }
        int ntk= f(curr+1,prev,nums,n,dp);
        

        return dp[curr] [prev+1] =max(tk,ntk);
    }

};