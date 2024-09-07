class Solution {
public:
    int minDistance(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int ind1 = 1; ind1 <= n; ++ind1) {
            for (int ind2 = 1; ind2 <= m; ++ind2) {
                if (text1[ind1-1] == text2[ind2-1]) {
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                } else {
                    dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
                }
            }
        }

        return (n+m-(2*dp[n][m]));
    }
};