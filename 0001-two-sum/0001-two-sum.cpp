class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int cur;
        int n= nums.size();
        for(int i=0; i<n; i++){
            cur=target- nums[i];
            for(int j=i+1; j<n; j++){
                if(nums[j]==cur) return {i,j};
            }
        }
        return {-1};
    }
};