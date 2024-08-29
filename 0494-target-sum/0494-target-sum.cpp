class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
         int tsum=0, n=arr.size();
        for(int i: arr) tsum+=i;
        
        if((tsum-d)%2!=0 || tsum<d ) return 0;
        
        return perfectSum(arr, n, (tsum-d)/2);
    }
  
    int f(vector<vector<int>>&dp,vector<int>& arr, int n, int sum,int i){
        if(sum==0 && i==n){
            return 1;
        }
        
        if(sum<0 || i==n)
            return 0;
        
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        
        
        
        int notTake=f(dp,arr,n,sum,i+1);
        int take=0;
        if(arr[i]<=sum)
            take=f(dp,arr,n,sum-arr[i],i+1);
        
        return dp[i][sum]=(notTake+take);
    }
    
    int perfectSum(vector<int>& arr, int n, int sum)
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(dp,arr,n,sum,0);
    }
};