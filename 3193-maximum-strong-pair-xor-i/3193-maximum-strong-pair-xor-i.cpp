class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int mx=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n; i++){
            for(int j=i; j<n; j++){
                if(abs(nums[i]-nums[j])<= min(nums[i], nums[j])){
                    mx=max(mx, nums[i] ^ nums[j]);
                }
            }
        }
        return mx;
    }
};