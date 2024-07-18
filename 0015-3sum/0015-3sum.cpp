#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       set<vector<int>> ans;

        int n=nums.size();
        sort(nums.begin(), nums.end());
    

    

        for(int i=0; i<n; i++){
            int l=i+1, r=n-1, sum;

            while(l<r){
                sum=nums[i]+nums[l]+nums[r];

                if(sum==0){
                    ans.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(sum<0){
                    l++;
                }
                else{
                    r--;
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