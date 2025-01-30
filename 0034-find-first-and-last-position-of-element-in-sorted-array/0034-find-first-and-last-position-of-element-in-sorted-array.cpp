class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if (nums.empty()) return ans;

        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        if (l < nums.size() && nums[l] == target) {
            ans[0] = l;
        } else {
            return ans; 
        }

        r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        ans[1] = r;

        return ans;
    }
};
