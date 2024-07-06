class Solution {
public:
    // int dp[ 1001] [1001];

    // int solve(string x, string y, int n, int m, int lcs){
    //     if(n==0 || m==0) return 0;

    //     if(dp[m][n]!=-1) return dp[m][n];

    //     if(x[n-1] == y[m-1]){
    //         return dp[m][n]= 1+solve(x, y, n-1, m-1, lcs+1);
    //     }
        
    //     return dp[m][n]= max(solve(x, y, n-1, m, lcs), solve(x, y, n, m-1, lcs));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        // memset(dp, -1, sizeof(dp));
        int n=text1.size();
        int m= text2.size();
        // return solve(text1 , text2,n,m, 0);

        int dp[n+1][m+1];
        memset(dp,-1, sizeof(dp));

        for(int i=0; i<n; i++){
            dp[i][0]=0;
        }

        for(int i=0; i<m; i++){
            dp[0][i]=0;
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        if(dp[n][m]==-1) return 0;
        return dp[n][m];
    }
};