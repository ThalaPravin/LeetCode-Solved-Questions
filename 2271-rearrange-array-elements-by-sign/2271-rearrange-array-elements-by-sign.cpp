class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i=0, j=0;
        vector<int>ans, p, n;

       for (int i: nums) {
           if (i>=0) p.push_back(i);
           else n.push_back(i);
       }
       for (int i = 0; i<nums.size()/2; i++){
           ans.push_back(p[i]);
           ans.push_back(n[i]);
       }
        return ans;
    }
};