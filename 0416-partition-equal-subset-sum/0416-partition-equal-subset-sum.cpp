class Solution {
public:

bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        
        bool dp[n+1][ sum+1];
        memset(dp , false, sizeof(dp));
        
        for(int i=0; i<n; i++){
            dp[i][0]=true;
        }
        
       
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1 ; j++){
                if(arr[i-1]<=j){
                    dp[i][j]= dp[i-1] [j-arr[i-1]]  || dp[i-1] [j];
                }
                else{
                    dp[i] [j] = dp[i-1] [j];
                }
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        long long sum= 0;
        for(auto i: nums ){
            sum+=i;
        }
        if(sum%2) return false;

        return isSubsetSum(nums, sum/2);
        
    }
};