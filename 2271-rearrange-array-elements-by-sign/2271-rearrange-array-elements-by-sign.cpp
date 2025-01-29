class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;

        for(auto i: nums){
            if(i<0){
                neg.push_back(i);
            }
            else{
                pos.push_back(i);
            }
        }

        vector<int>ans;

        int n=pos.size();

        for(int i=0; i<n; i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }

        return ans;
    }
};