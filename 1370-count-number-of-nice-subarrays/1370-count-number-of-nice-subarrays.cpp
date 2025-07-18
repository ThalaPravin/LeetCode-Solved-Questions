class Solution {
public:
int solve(vector<int>& nums, int goal) {
        int ans = 0,l=0,r=0, n=nums.size();
        long long cnt=0;
       
        while (r < n) {
            cnt += nums[r] %2 ==1? 1:0;
            while (l <= r && cnt > goal) {
                cnt -= nums[l] %2 ==1 ? 1:0;
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)- solve(nums, k-1);
    }
};