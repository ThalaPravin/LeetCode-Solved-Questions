class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        while (true) {
            unordered_set<int> s;
            bool dup = false;
            for (int i = 0; i < nums.size(); ++i) {
                if (s.count(nums[i])) {
                    dup = true;
                    break;
                }
                s.insert(nums[i]);
            }
            if (!dup) break;

            // Remove first 3 elements (or all if < 3)
            if (nums.size() <= 3) return ops + 1;
            nums.erase(nums.begin(), nums.begin() + 3);
            ++ops;
        }
        return ops;
    }
};
