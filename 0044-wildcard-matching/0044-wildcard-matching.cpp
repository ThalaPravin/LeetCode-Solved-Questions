class Solution {
public:

    bool all(string& s, int j) {
        for(int i=1; i<=j; i++) {
            if(s[i-1] != '*') return false;
        }
        return true;
    } 

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));

        dp[0][0] = true;

        for(int j=1; j<=m; j++) {
            dp[0][j] = all(p, j);
        }

        for(int i=1; i<=n; i++) {
            dp[i][0] = false;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    if(p[j-1] == '*') {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    }
                    else dp[i][j] = false;
                }
            }
        }
        
        return dp[n][m];
    }
};