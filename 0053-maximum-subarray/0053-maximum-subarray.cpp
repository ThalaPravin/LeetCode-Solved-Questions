class Solution {
public:
    int maxSubArray(vector<int>& nums) {   
        int mx=INT_MIN;
        int sum=0;

        for(int i: nums){
            sum+=i;
            mx=max(mx,sum);
            if(sum<0) sum=0;
        }
        return mx;
    }
};