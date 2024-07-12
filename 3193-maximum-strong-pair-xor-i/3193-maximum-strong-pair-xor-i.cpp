class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        // Brute Force
        // int mx=INT_MIN;
        // int n=nums.size();
        // for(int i=0;i<n; i++){
        //     for(int j=i; j<n; j++){
        //         if(abs(nums[i]-nums[j])<= min(nums[i], nums[j])){
        //             mx=max(mx, nums[i] ^ nums[j]);
        //         }
        //     }
        // }
        // return mx;


        // Sliding Window O(n *logn)

        int l = 0 , r = 0 , total , maxTotal = 0;
        if (nums.size() < 2)
        {
            return 0;
        }
        for(; l < nums.size() - 1 ; l++)
        {
            if((abs(nums[l] - nums[r])) <= min(nums[l] , nums[r]))
            {
                total = nums[l] ^ nums[r];
                maxTotal = max(total, maxTotal);
            }
            if(r == nums.size()-1)
            {
                r = l + 1;
            }
            else
            {
                l--;
                r++;
            }
        }
        return maxTotal;
    }
};