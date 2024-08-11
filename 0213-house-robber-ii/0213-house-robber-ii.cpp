class Solution {
public:
    int solve(vector<int>& dp, int start, int end, vector<int>& nums) {
        for (int i = start; i <= end; ++i) {
            dp[i] = max((i - 2 >= start ? dp[i - 2] : 0) + nums[i], (i - 1 >= start ? dp[i - 1] : 0));
        }
        return dp[end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);

        
        int ans1 = solve(dp1, 0, n - 2, nums);

        int ans2 = solve(dp2, 1, n - 1, nums);

        return max(ans1, ans2);
    }
};
