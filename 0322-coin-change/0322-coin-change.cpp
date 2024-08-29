class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = f(coins, n-1, amount, dp);
        return (result == 1e7) ? -1 : result;
    }

    int f(vector<int>& coins, int ind, int amt, vector<vector<int>>&dp) {
        if (amt == 0) return 0;
        if(amt<0 || ind < 0) return 1e7;
    
        if (dp[ind] [amt] != -1) return dp[ind][amt];
        
        int notTake = f(coins, ind - 1, amt, dp);
        
        int take = 1e7;
        if (amt >= coins[ind])
            take = 1 + f(coins, ind, amt - coins[ind], dp);

        return dp[ind ] [amt] = min(take, notTake);
    }

    
};
