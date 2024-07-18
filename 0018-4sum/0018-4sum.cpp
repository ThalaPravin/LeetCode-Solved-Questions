class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;

        int n=nums.size();
        sort(nums.begin(), nums.end());
    

    
        for(int p=0; p<n; p++){
        for(int i=p+1; i<n; i++){
            int l=i+1, r=n-1;
            long long sum=0;

            while(l<r){
                sum=  (long long)nums[p]+  (long long)nums[i]+  (long long)nums[l]+ (long long)nums[r];

                if(sum==target){
                    ans.insert({nums[p], nums[i], nums[l] , nums[r]});
                    l++;
                    r--;
                }
                else if(sum<target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        }
         
        vector<vector<int>>fans;
        for( auto i: ans){
            fans.push_back(i);
        }
        return fans;
    }
};