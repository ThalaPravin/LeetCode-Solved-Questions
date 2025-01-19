class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int>mp;
        int n=nums.size();
        int cur=0,mx=0;
        int ans=-1;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            cur=mp[nums[i]];
            if(cur>mx){
                ans=nums[i];
            }

            mx=max(mx, cur);
            
        }

        return ans;
    }
};