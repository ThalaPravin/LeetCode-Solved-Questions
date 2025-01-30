class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();

        for(int i=0; i<n; i++){
            int prd=nums[i];
            for(int j=i+1; j<n; j++){
                prd*=nums[j];
                ans=max(ans,prd);
            }
             ans=max(ans,nums[i]);
        }

        return ans;
    }
};