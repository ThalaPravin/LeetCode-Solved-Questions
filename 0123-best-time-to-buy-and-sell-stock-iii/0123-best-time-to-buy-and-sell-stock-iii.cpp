class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 0, n, dp, prices, 0);
    }

    int f(int ind, int buy, int n, vector<vector<vector<int>>>& dp, vector<int>& prices, int tk) {
        if (tk == 2 || ind == n) return 0; 

        if (dp[ind][buy][tk] != -1) return dp[ind][buy][tk];

        int op1 = 0, op2 = 0;
        if (buy == 0) {  
            op1 = f(ind + 1, 0, n, dp, prices, tk); 
            op2 = -prices[ind] + f(ind + 1, 1, n, dp, prices, tk); 
        } else {  
            op1 = f(ind + 1, 1, n, dp, prices, tk); 
            op2 = prices[ind] + f(ind + 1, 0, n, dp, prices, tk + 1);  
        }

        return dp[ind][buy][tk] = max(op1, op2);
    }
};
