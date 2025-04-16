class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        long long sum = 0, maxi = 0;
        int distinct = 0;
        int n = nums.size();

        for (int i = 0; i < k && i < n; i++) {
            if (m[nums[i]] == 0) distinct++;
            m[nums[i]]++;
            sum += nums[i];
        }

        if (distinct == k) maxi = sum;

        for (int i = k; i < n; i++) {
            // Remove the element going out of the window
            if (--m[nums[i - k]] == 0) distinct--;
            sum -= nums[i - k];

            // Add the new element into the window
            if (m[nums[i]]++ == 0) distinct++;
            sum += nums[i];

            if (distinct == k) maxi = max(maxi, sum);
        }

        return maxi;
    }
};