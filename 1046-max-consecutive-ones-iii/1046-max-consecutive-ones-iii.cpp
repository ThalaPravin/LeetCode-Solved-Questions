class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size()-1;
        int i=0, j=0, mx=0,zr=0;

        while(j<=n){
            if(nums[j]==0){
                zr++;
            }
            if(zr>k){
                if(nums[i]==0) zr --;
                i++;
            }
            if(zr<=k) mx=(mx, j-i+1);

            j++;
        }
        return mx;
    }
};