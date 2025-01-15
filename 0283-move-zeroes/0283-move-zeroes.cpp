class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        int cnt=0;
        for(int i:nums){
            if(i!= 0) temp.push_back(i);
            else cnt++;
        }

        for(int i=0; i<n-cnt; i++){
            nums[i]=temp[i];
        }

        for(int i=0; i<cnt; i++){
            nums[n-cnt+i]=0;
        }
    }
};