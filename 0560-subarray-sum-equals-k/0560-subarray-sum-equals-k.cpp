class Solution {
public:
    int subarraySum(vector<int>& nums, int goal) {
        int cnt=0;
        int prefSum=0;
        map<int,int>mp;
        mp[0]=1;
        int n=nums.size();

        for(int i=0; i<n; i++){
            prefSum+=nums[i];
            int rem=prefSum-goal;
            cnt+=mp[rem];
            mp[prefSum]+=1;
        }
        return cnt;
    }
};