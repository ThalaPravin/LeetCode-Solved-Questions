class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tsum=0;
        for(int i:nums){
            tsum+=i;
        }
        if(tsum%2 !=0) return false;
        int sum=tsum/2;
        int n=nums.size();
         vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(nums,dp, n-1, sum);
    }

     bool f(vector<int>&arr, vector<vector<int>>&dp, int ind, int tar){
        if(arr[ind]==tar) return true;
        if(ind==0) return false;
        
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        bool take=false;
        bool nottake=f(arr, dp, ind-1, tar);
        
        if(arr[ind]<tar) take= f(arr,dp, ind-1, tar-arr[ind]);
        
        return dp[ind][tar] = take || nottake;
    }
};