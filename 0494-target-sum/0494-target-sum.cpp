class Solution {
public:
     int subsetsumDiff(vector <int> arr, int n , int sum){
  
	    int dp[n+1] [sum+1];
	    
	    memset(dp, 0, sizeof(dp));
	    
	    for(int i=0; i<n+1; i++){
	        dp[i][0]=1;
	    }
        // if (arr[0]==0) dp[0][0] = 2;
	    
	    for(int i=1; i<n+1; i++){
	        for(int j=0; j<sum+1; j++){
	            
	            if(arr[i-1]<=j){
	                dp[i][j]= dp[i-1][j-arr[i-1]]  + dp[i-1][j];
	            }
	            else{
	                dp[i][j]= dp[i-1][j];
	            }
	        }
	    }

        return dp[n][sum];
     }

    int findTargetSumWays(vector<int>& arr, int target) {
        long long sum=0;
        int n=arr.size();
	    for(int i=0; i<n; i++){
	        sum+=arr[i];
	    }
        int s=(target+sum)/2;

        if(sum<abs(target)||(sum+target)%2!=0)
            return 0;

        int count=subsetsumDiff(arr, n, abs(s));
        return count ;
    }
};