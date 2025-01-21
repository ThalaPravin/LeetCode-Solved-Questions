class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
              sort(nums.begin(), nums.end());
        int cnt=1,mx=0;
        int n = nums.size();
        if(n==1) return 1;

        for(int i=1; i<n; i++){
            if(nums[i]-nums[i-1] ==1){
                cnt++;
            }
            else{
                if(nums[i]!=nums[i-1]){
                    cnt=1;
                }
            }
            mx=max(mx,cnt);
        }

        return mx;  
    }
};