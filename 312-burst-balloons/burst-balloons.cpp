class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n + 2, 1);
        for (int i = 1; i <= n; ++i) a[i] = nums[i - 1];
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len <= n; ++len) {
            for (int i = 1; i + len - 1 <= n; ++i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j],
                                   a[i - 1] * a[k] * a[j + 1]    
                                   + dp[i][k - 1]             
                                   + dp[k + 1][j]);              
                }
            }
        }
        return dp[1][n];
    }
};
