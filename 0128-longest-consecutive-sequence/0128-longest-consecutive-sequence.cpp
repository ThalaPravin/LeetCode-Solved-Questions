class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int count=0;
        int ans=0;
        if(n==0) return 0;
        
        for(int i=0; i<n-1; i++){
            if (nums[i]-nums[i+1]==0) continue;
            if(nums[i+1]-nums[i]==1){
                count++;
                ans=max(ans,count);
            } 
             else{
                 count=0;
            }
        }
        return ans+1;
    }
};