class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int nd=n/3;

        map<int,int>mp;

        for(int i=0; i<n; i++){
            if(mp.find(nums[i])!=mp.end()){
                mp[nums[i]]++;
            }
            else{
                mp[nums[i]]=0;
            }
        }

        for(auto i:mp){
            if(i.second >=nd){
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};