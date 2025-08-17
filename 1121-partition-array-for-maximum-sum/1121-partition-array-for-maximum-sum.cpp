#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSumAfterPartitioning(std::vector<int>& arr, int k) {
        int n = arr.size();

        std::vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int curMax = 0, curSum = 0;
            for (int j = i; j >= std::max(0, i - k + 1); j--) {
                curMax = std::max(curMax, arr[j]);
                int cur = curMax * (i - j + 1) + dp[j];
                curSum = std::max(curSum, cur);
            }

        
            dp[i + 1] = curSum;
        }

        return dp[n];
    }
};