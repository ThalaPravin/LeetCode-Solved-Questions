class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        
        for(auto i:nums) m[i]++;
        
        for(int i=0; i<=n; i++){
            if(m[i]==0) return i;
        }
        
        return 0;
    }
};