class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MIN;
        int cnt=0;

        for(int i:nums){
            cnt+=i;
            mx=max(mx,cnt);
            if(cnt<0) cnt=0;
        }

        return mx;
    }
};