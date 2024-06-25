class Solution {
public:
    int tribonacci(int n) {
        if(n<1) return 0;
        if(n<3) return 1;
        int dp[n+1];
        dp[0]=0;
        dp[1]=dp[2]=1;

        for(int i=3; i<n+1; i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }

        return dp[n];
    }
};