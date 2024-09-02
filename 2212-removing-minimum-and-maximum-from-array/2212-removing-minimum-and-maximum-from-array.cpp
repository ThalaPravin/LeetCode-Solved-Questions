class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
         int n=nums.size();
        if(n==1) return 1;
        map<int,int>mp;
        int mn=INT_MAX;
        int mx=INT_MIN;

        for(int i=0; i<n; i++){
            mp[nums[i]]=i+1;
            mn=min(nums[i], mn);
            mx= max(nums[i], mx);
        }

        int mxi=mp[mx], mni=mp[mn];
        
        vector<int>ans;
        ans.push_back(max(mxi,mni));
        ans.push_back(max(n+1-mni, n+1-mxi));
        ans.push_back(min(mni,mxi)+ n+1- max(mni,mxi));

        int a=INT_MAX;

        for(auto i:ans){
            a=min(i,a);
        }

        return a;
    }
};