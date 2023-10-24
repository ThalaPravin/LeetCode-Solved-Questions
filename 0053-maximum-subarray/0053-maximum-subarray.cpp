class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int allmax=INT_MIN, maxi=0;
        
        for(int i=0; i<nums.size(); i++){
            maxi=maxi+nums[i];
            
            if(allmax<maxi) allmax=maxi;
            
            if(maxi<0) maxi=0;
        }
        
        return allmax;
    }
};