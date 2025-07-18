class Solution {
public:
    int answer(vector<int>& nums, int goal) {
        int ans = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        long long sum = 0;
        
        while (r < n) {
            sum += nums[r];
            while (l <= r && sum > goal) {
                sum -= nums[l];
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return answer(nums, goal) - answer(nums, goal - 1);
    }
};