class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int n=nums.size();
        // int m;
        // int ans;

        // for(int i=0; i<n; i++){ 
        //     for(int j=i+1; j<n; j++){
        //         if((nums[i] ^ nums[j])==0){
        //             ans=nums[i];
        //             break;
        //         }
        //     }
        // }
        // return ans;
        int n=nums.size();
        int hash[n];
        
        memset(hash, 0, sizeof(hash));

        for(auto i: nums){
            hash[i]++;
        }

        for(int i=0; i<n; i++){
            if(hash[i]>1) return i;
        }

        return -1;
    }
};