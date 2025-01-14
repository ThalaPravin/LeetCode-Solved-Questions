class Solution {
public:
    bool check(vector<int>& nums) {
       int r = 0;
        for (int i = 0; i < nums.size() ; i++)
        {
             if (!(nums[(i + 1) % nums.size()] >= nums[i]))  r++;
        }
         return r <= 1;
    }
};