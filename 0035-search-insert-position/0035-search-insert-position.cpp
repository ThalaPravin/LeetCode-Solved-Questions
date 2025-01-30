class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size(), l=0;
        int r=n-1, m=(l+r)/2;

        while(l<=r){
            m=(l+r)/2;
            if(nums[m] == target) return m;
            if(m < n - 1 && nums[m] < target && nums[m + 1] > target) return m + 1;
            else if(nums[m]<target){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }

        if(target<nums[0]) return 0;
        else return n;

    }
};