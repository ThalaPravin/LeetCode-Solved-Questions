class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     map<int,int>mp;
     int n=nums.size();
     for(int i=0; i<n; i++){
         int nd=target-nums[i];
         if(mp.find(nd)!=mp.end()) return {i,mp[nd]};//if present in map it will not point to last iterator
         mp[nums[i]]=i;
     }
     return {-1,-1};

    }
};